#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QListWidget;
class SideBarWidget;
class PagesWidget;
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
signals:
    
public slots:    
    void setSideBarVisable(bool vis);

private:
    void setupGui();
    void createToolBarNav();
    void createIcons();
    void createSideBar();
    void createPagesWidget();

    QListWidget *navToolbarWidget;
    SideBarWidget *sideBarWidget;
    PagesWidget *pagesWidget;
    
};

#endif // MAINWIDGET_H
