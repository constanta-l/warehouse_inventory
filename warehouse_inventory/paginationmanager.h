#ifndef PAGINATIONMANAGER_H
#define PAGINATIONMANAGER_H

#include <QObject>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QLabel>
#include <QTableView>

class PaginationManager : public QObject
{
    Q_OBJECT
public:
    explicit PaginationManager(QSqlQueryModel *model, QPushButton *prevBtn, QPushButton *nextBtn, QLabel *pageLabel, QObject *parent = nullptr);
    int getTotalPages();
    void setCurrentPage(int page);

public slots:
    void onNextPage();
    void onPreviousPage();
    void updateModel();
    void updatePageLabel();

private:
    QSqlQueryModel *model;
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QLabel *pageLabel;
    QTableView tableView;
    int currentPage;
    const int pageSize = 10;



};

#endif // PAGINATIONMANAGER_H
