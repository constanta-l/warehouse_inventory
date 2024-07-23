#include "paginationmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableView>



PaginationManager::PaginationManager(QSqlQueryModel *model, QPushButton *prevBtn, QPushButton *nextBtn, QLabel *pageLabel, QObject *parent)
    : QObject(parent), model(model), prevBtn(prevBtn), nextBtn(nextBtn), pageLabel(pageLabel), currentPage(0)
{
    connect(prevBtn, &QPushButton::clicked, this, &PaginationManager::onPreviousPage);
    connect(nextBtn, &QPushButton::clicked, this, &PaginationManager::onNextPage);

    updateModel();
    updatePageLabel();
}

void PaginationManager::updateModel(){
    QSqlQuery query;
    int offset = currentPage * pageSize;

    query.prepare(QString("SELECT * FROM inventory LIMIT %1 OFFSET %2").arg(pageSize).arg(offset));

    if (!query.exec()) {
        qDebug() << "Eroare la interogare:" << query.lastError();
        return;
    }

    model->setQuery(std::move(query));

    //tableView.reset(); // This can help refresh the view after updating the model


}

void PaginationManager::updatePageLabel()
{

    //TO UPDATE WITH NEW FUNCTION -
    int totalRows = 0;
    QSqlQuery query("SELECT COUNT(*) FROM inventory");
    if (query.next()) {
        totalRows = query.value(0).toInt();
    }

    int totalPages = (totalRows + pageSize - 1) / pageSize;
    pageLabel->setText(QString("Pagina %1 din %2").arg(currentPage + 1).arg(totalPages));

    prevBtn->setEnabled(currentPage > 0);
    nextBtn->setEnabled(currentPage < totalPages - 1);
}

void PaginationManager::onNextPage()
{

    currentPage++;
    updateModel();
    updatePageLabel();

}

void PaginationManager::onPreviousPage()
{
    currentPage--;
    updateModel();
    updatePageLabel();
}

int PaginationManager::getTotalPages(){
    int totalRows = 0;
    QSqlQuery query("SELECT COUNT(*) FROM inventory");
    if (query.next()) {
        totalRows = query.value(0).toInt();
    }
    int totalPages = (totalRows + pageSize - 1) / pageSize;

    return totalPages;

}

void PaginationManager::setCurrentPage(int page){
    currentPage = page;

}
