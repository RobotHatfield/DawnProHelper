#include "mainwindow.h"
#include "mainwidget.h"
#include "configdialog.h"

#include <QtWidgets>
#include <QDebug>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    qDebug() << "Mainwindow Created";

    setupGui();
    readSettings();

    mWidget->setSideBarVisable(sideBarAction->isChecked());
}

MainWindow::~MainWindow()
{
    qDebug() << "Mainwindow Deleted";

    writeSettings();
}

void MainWindow::readSettings()
{
    QSettings settings;
    settings.beginGroup(tr("GUISettings"));
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    /*bool fs = settings.value("fullScreen",bool(false)).toBool();
    if(fs) { changeFullScreen(); }
    bool sb = settings.value("sideBar",bool(true)).toBool();
    if(sb) { changeSideBar(); }
    changeSideBar();*/
    bool fs = settings.value("fullScreen", bool(false)).toBool();
     qDebug() << fs;
    fullScreenAction->setChecked(fs);

    settings.endGroup();
}

void MainWindow::writeSettings()
{
    QSettings settings;
    settings.beginGroup(tr("GUISettings"));
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.setValue("fullScreen", fullScreenAction->isChecked()); qDebug() << fullScreenAction->isChecked();
    //settings.setValue("sideBar",getSideBarEnabled());
    settings.endGroup();
}

void MainWindow::createEarlyConnections()
{
    //
}

void MainWindow::createConnections()
{
    //
}

void MainWindow::setupGui()
{
    createActions();
    createMenu();
    createMainWidget();
}

void MainWindow::createActions()
{
    quitAction = new QAction(tr("Quit"),this);
    connect(quitAction,SIGNAL(triggered()),this,SLOT(close()));

    configDialogAction = new QAction("Configuration...",this);

    connect(configDialogAction,SIGNAL(triggered()),this,SLOT(launchConfigDialog()));

    sideBarAction = new QAction(tr("Show / Hide Sidebar"),this);
    sideBarAction->setCheckable(true);

    fullScreenAction = new QAction(tr("Show Fullscreen"),this);
    fullScreenAction->setCheckable(true);

    connect(fullScreenAction,SIGNAL(toggled(bool)),this,SLOT(setFullscreen(bool)));
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("FILE"));
    fileMenu->addAction(quitAction);

    toolsMenu = menuBar()->addMenu(tr("TOOLS"));
    toolsMenu->addAction(configDialogAction);

    windowMenu = menuBar()->addMenu(tr("WINDOW"));
    windowMenu->addAction(fullScreenAction);
    windowMenu->addAction(sideBarAction);

    helpMenu = menuBar()->addMenu(tr("HELP"));
}

void MainWindow::createMainWidget()
{
    mWidget = new MainWidget(this);

    connect(sideBarAction,SIGNAL(toggled(bool)),mWidget,SLOT(setSideBarVisable(bool)));

    this->setCentralWidget(mWidget);
    qDebug() << QSqlDatabase::drivers();
}

void MainWindow::launchConfigDialog()
{
    configDialog = new ConfigDialog(this);
    configDialog->setModal(true);
    configDialog->exec();
}

void MainWindow::setFullscreen(bool fs)
{
    if (fs)
    {
        showFullScreen();
    }

    else
    {
        showNormal();
    }
}
