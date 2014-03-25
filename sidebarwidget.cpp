#include "sidebarwidget.h"

#include <QtWidgets>
#include <QDebug>

SideBarWidget::SideBarWidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "SideBarWidget Created";

    QLabel *label = new QLabel(tr("Hello"),this);
}

SideBarWidget::~SideBarWidget()
{
    qDebug() << "SideBarWidget Deleted";
}
