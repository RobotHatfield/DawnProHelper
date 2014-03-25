#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class MainWidget;
class ConfigDialog;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void launchConfigDialog();
    void setFullscreen(bool fs);
    
private:
    void createEarlyConnections();
    void createConnections();
    void readSettings();
    void writeSettings();
    void setupGui();
    void createActions();
    void updateActions();
    void createMenu();
    void createMainWidget();

    QAction *quitAction;
    QAction *configDialogAction;
    QAction *sideBarAction;
    QAction *fullScreenAction;

    QMenu *fileMenu;
    QMenu *toolsMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

    MainWidget *mWidget;
    ConfigDialog *configDialog;
};

#endif // MAINWINDOW_H
