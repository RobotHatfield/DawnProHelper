#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
class QHBoxLayout;
QT_END_NAMESPACE

class ConfigDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConfigDialog(QWidget *parent = 0);
    
signals:
    
public slots:

private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

    void okBtnPress();
    void applyBtnPress();

private:
    void createIcons();

    QListWidget *contentsWidget;
    QStackedWidget *pagesWidget;

    QHBoxLayout *btnLayout;

    QPushButton *okBtn;
    QPushButton *applyBtn;
    QPushButton *closeBtn;
    
};

#endif // CONFIGDIALOG_H
