#include "pageswidget.h"

#include <QtWidgets>
#include <QDebug>

PagesWidget::PagesWidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "PagesWidget Created";

    QLabel *label = new QLabel(tr("Hello"),this);
}

PagesWidget::~PagesWidget()
{
    qDebug() << "PagesWidget Deleted";
}
