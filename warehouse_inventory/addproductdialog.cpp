#include "addproductdialog.h"

AddProductDialog::AddProductDialog(QWidget *parent)
: QDialog(parent)
{
    productCodeEdit = new QLineEdit(this);
    productNameEdit = new QLineEdit(this);
    quantityEdit = new QLineEdit(this);

    okButton = new QPushButton("Adauga", this);
    cancelButton = new QPushButton("Anulare", this);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Cod produs:", productCodeEdit);
    layout->addRow("Nume produs:", productNameEdit);
    layout->addRow("Cantitate:", quantityEdit);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    setLayout(layout);

    setWindowTitle("Adaugă Produs");


    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

}

QString AddProductDialog::getProductCode() const
{
    return productCodeEdit->text();
}

QString AddProductDialog::getProductName() const
{
    return productNameEdit->text();
}

int AddProductDialog::getQuantity() const
{
    return quantityEdit->text().toInt();
}
