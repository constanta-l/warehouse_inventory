#ifndef ADDPRODUCTDIALOG_H
#define ADDPRODUCTDIALOG_H

#include <QDialog>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class AddProductDialog : public QDialog
{

    Q_OBJECT

public:
    explicit AddProductDialog(QWidget *parent = nullptr);

    QString getProductCode() const;
    QString getProductName() const;
    int getQuantity() const;

private:
    QLineEdit *productCodeEdit;
    QLineEdit *productNameEdit;
    QLineEdit *quantityEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // ADDPRODUCTDIALOG_H
