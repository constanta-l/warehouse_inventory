#include <QMessageBox>
#include <QTimer>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QPdfDocument>
#include <QDebug>
#include <QtPdf>
#include <QtPdfWidgets>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paginationmanager.h"
#include "readonlyitemdelegate.h"
#include "addproductdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");

    //db.setDatabaseName("D:/Qt/warehouse_inventory-master/warehouse_inventory-master/database/warehouse_inventory.db");
    db.setDatabaseName("./../../../database/warehouse_inventory.db");

    if(db.open()){
        ui->statusbar->showMessage("Baza de date a fost conectata cu succes. " + db.databaseName());

        model = new QSqlTableModel(this, db);
        model->setTable("inventory");
        model->select();

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        PaginationManager(model, ui->prevBtn, ui->nextBtn, ui->pageLabel, this);

        model->setHeaderData(0, Qt::Horizontal, "ID"); // ID
        model->setHeaderData(1, Qt::Horizontal, "Cod produs"); // product_code
        model->setHeaderData(2, Qt::Horizontal, "Nume produs"); // product_name
        model->setHeaderData(3, Qt::Horizontal, "Cantitate"); // quantity

        ui->searchBtn->setIcon(QIcon(":/icons/icons/search.png"));
        ui->prevBtn->setIcon(QIcon(":/icons/icons/prev.png"));
        ui->nextBtn->setIcon(QIcon(":/icons/icons/next.png"));

        //coloana ID sa fie read-only
        ReadOnlyItemDelegate *delegate = new ReadOnlyItemDelegate(ui->tableView);
        ui->tableView->setItemDelegateForColumn(0, delegate);

        paginationManager = new PaginationManager(model, ui->prevBtn, ui->nextBtn, ui->pageLabel, this);

        //La pornirea aplicatie sa fie tab1
        ui->tabWidget->setCurrentIndex(0);

        //Semnal ca s-a schimbat tab-ul
        connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    }
    else{
        ui->statusbar->showMessage("Eroare la conectare cu baza de date.  " +db.lastError().databaseText() );
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete paginationManager;
}

void MainWindow::on_addBtn_clicked()
{

    AddProductDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString productCode = dialog.getProductCode();
        QString productName = dialog.getProductName();
        int quantity = dialog.getQuantity();

        QSqlQuery query;
        query.prepare("INSERT INTO inventory (product_code, product_name, quantity) VALUES (?, ?, ?)");
        query.addBindValue(productCode);
        query.addBindValue(productName);
        query.addBindValue(quantity);

        if (query.exec()) {
            model->select();
            paginationManager->updateModel();
        } else {
            ui->statusbar->showMessage("Eroare la adăugarea produsului. " + query.lastError().text());
        }
    }
}


void MainWindow::on_deleteBtn_clicked()
{

    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        ui->statusbar->showMessage("Niciun produs selectat pentru ștergere.");
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Confirmare ștergere");
    msgBox.setText("Ești sigur că vrei să ștergi produsul selectat?");
    //QPushButton *btnYes =
    msgBox.addButton("Da", QMessageBox::YesRole);
    QPushButton *btnNo = msgBox.addButton("Nu", QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton() == btnNo) {
        return;
    }

    // Șterge produsul
    for (const QModelIndex &index : selectedRows) {
        model->removeRow(index.row());
    }

    if (!model->submitAll()) {
        ui->statusbar->showMessage("Eroare la ștergerea produsului: " + model->lastError().text());
    } else {
        model->select();
        paginationManager->updateModel();


        ui->statusbar->setStyleSheet("QStatusBar { color: green; }");
        ui->statusbar->showMessage("Produsul a fost șters cu succes.", 5000);

        QTimer::singleShot(5000, [this]() {
            ui->statusbar->setStyleSheet("");
        });
    }


}


void MainWindow::on_searchBtn_clicked()
{

    QString searchQuery = ui->searchLineEdit->text().trimmed(); // Get and trim the search query

    if (searchQuery.isEmpty()) {
        // Clear the filter if the search query is empty
        model->setFilter("");
    } else {
        // Build the filter string
        QString filter = QString("product_code LIKE '%%1%' OR product_name LIKE '%%1%'").arg(searchQuery);

        // Apply the filter to the model
        model->setFilter(filter);
    }

}


void MainWindow::on_pushButton_clicked()
{
    //buton: toate produsele, se foloseste dupa search ca sa revenim la toate produsele
    model->select();
    paginationManager->updateModel();
}



void MainWindow::onTabChanged(int index)
{
    if (index == 1) {  // Tab 2 cu index 1


        setupPdfView();

    }
}

void MainWindow::exportTableViewToCSV(QTableView* tableView, const QString& filePath){



    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        QAbstractItemModel* model = tableView->model();


        // Write headers
        for (int col = 0; col < model->columnCount(); ++col) {
            out << model->headerData(col, Qt::Horizontal).toString();
            if (col < model->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";

        // Iterate through all pages
        int totalPages = paginationManager->getTotalPages();
        for (int page = 0; page < totalPages; page++) {
            qDebug() << "Exporting page" << page;
            paginationManager->setCurrentPage(page);


            // Collect all data from the current page
            QStringList rowData;
            int numRows = model->rowCount();

            for (int row = 0; row < numRows; ++row) {


                QStringList rowDataForRow;
                for (int col = 0; col < model->columnCount(); ++col) {

                    QModelIndex index = model->index(row, col);
                    QString data = model->data(index).toString();
                    rowDataForRow << data;

                }
                rowData << rowDataForRow.join(",");
            }

            // Write collected data to the file
            out << rowData.join("\n") << "\n";

            paginationManager->onNextPage();


        }

        file.close();
        qDebug() << "Export completed.";
        paginationManager->setCurrentPage(0);
        paginationManager->updateModel();
        paginationManager->updatePageLabel();


    } else {
        qDebug() << "Failed to open file for writing:" << file.errorString();
    }

}

void MainWindow::on_toPdfBtn_clicked()
{
    //PaginationManager* paginationManager;

    QString tempFolderPath = "./../../../temp";
    QDir tempDir(tempFolderPath);

    if (!tempDir.exists()) {
        qDebug() << "Creating temp folder:" << tempFolderPath;
        if (!tempDir.mkpath(".")) {
            qDebug() << "Failed to create temp folder:" << tempFolderPath;
        }
    }
\
    QString reportsFolderPath = "./../../../Reports";
    QDir reportsDir(reportsFolderPath);

    if (!reportsDir.exists()) {
        qDebug() << "Creating temp folder:" << reportsFolderPath;
        if (!reportsDir.mkpath(".")) {
            qDebug() << "Failed to create temp folder:" << reportsFolderPath;
        }
    }

    QString csvPath = "./../../../temp/table_view_data.csv";
    exportTableViewToCSV(ui->tableView, csvPath);
    QProcess process;
    process.start("python", QStringList() << "./../../../warehouse_inventory/scripts/generate_pdf.py");
    //process.waitForFinished();
    if (!process.waitForStarted()) {
        qDebug() << "Error starting Python process:" << process.errorString();
    }

    if (!process.waitForFinished()) {
        qDebug() << "Error executing Python script:" << process.errorString();
    } else {
        QString output(process.readAllStandardOutput());
        QString error(process.readAllStandardError());
        qDebug() << "Python script output:" << output;
        qDebug() << "Python script error:" << error;
    }

}

void MainWindow::setupPdfView() {

    //new code
    QLayout* existingLayout = ui->tab_2->layout();
    if (existingLayout != nullptr) {
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    QPdfView *pdfView = new QPdfView(this);
    QPdfDocument *pdfDocument = new QPdfDocument(this);
    pdfDocument->load("./../../../Reports/raport_stoc_curent.pdf");
    pdfView->setDocument(pdfDocument);


    QVBoxLayout *layout = new QVBoxLayout(ui->tab_2);
    layout->addWidget(pdfView);
    ui->tab_2->setLayout(layout);
}

