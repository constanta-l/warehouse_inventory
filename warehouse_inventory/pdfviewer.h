#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include <QWidget>
#include <QPdfDocument>
#include <QGraphicsView>
#include <QGraphicsScene>

class PdfViewer : public QWidget
{
    Q_OBJECT

public:
    explicit PdfViewer(QWidget *parent = nullptr);

private:
    QPdfDocument *pdfDocument;
    QGraphicsView *pdfView;
    QGraphicsScene *scene;
};

#endif // PDFVIEWER_H
