#include "mainwidget.h"
#include "sidebarwidget.h"
#include "pageswidget.h"

#include <QtWidgets>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "MainWidget Created";
    setupGui();
}

MainWidget::~MainWidget()
{
    qDebug() << "MainWidget Deleted";
}

void MainWidget::setSideBarVisable(bool vis)
{
    sideBarWidget->setVisible(vis);
}

void MainWidget::setupGui()
{
    createToolBarNav();

    QSplitter *split = new QSplitter(this);

    createSideBar();
    createPagesWidget();

    split->addWidget(sideBarWidget);
    split->addWidget(pagesWidget);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(navToolbarWidget);
    hLayout->addWidget(split);
    hLayout->setMargin(0);

    this->setLayout(hLayout);
}

void MainWidget::createToolBarNav()
{
    navToolbarWidget = new QListWidget();
    navToolbarWidget->setFixedWidth(80);
    createIcons();
}

void MainWidget::createIcons()
{
    //
}

void MainWidget::createSideBar()
{
    sideBarWidget = new SideBarWidget();
}

void MainWidget::createPagesWidget()
{
    pagesWidget = new PagesWidget();
}
