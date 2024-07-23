#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlQuery>
#include <QList>
#include <QStandardItemModel>
#include <QPdfDocument>
#include <QtPdf>
#include <QtPdfWidgets>




#include "paginationmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //void updateListView();

    void exportTableViewToCSV(QTableView* tableView, const QString& filePath);
    void setupPdfView();

private slots:
    void on_addBtn_clicked();

    void on_deleteBtn_clicked();

    void on_searchBtn_clicked();

    void on_pushButton_clicked();

    void onTabChanged(int index);





    void on_toPdfBtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
    PaginationManager *paginationManager;





};
#endif // MAINWINDOW_H
