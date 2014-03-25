#ifndef CONFIGDIALOGPAGES_H
#define CONFIGDIALOGPAGES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class GeneralConfigPage : public QWidget
{
    Q_OBJECT
public:
    GeneralConfigPage(QWidget *parent = 0);
};

class UpdateConfigPage : public QWidget
{
    Q_OBJECT
public:
    UpdateConfigPage(QWidget *parent = 0);
};

class SQLConfigPage : public QWidget
{
    Q_OBJECT
public:
    SQLConfigPage(QWidget *parent = 0);

private slots:
    void checkTestConnection();
    bool testConnection(QString conName, QString hostName, QString dbName, QString userName, QString pass);

private:
    QLineEdit *connectionNameEdit;
    QLabel *connectionNameLabel;
    QLineEdit *hostNameEdit;
    QLabel *hostNameLabel;
    QLineEdit *dbNameEdit;
    QLabel *dbNameLabel;
    QLineEdit *userNameEdit;
    QLabel *userNameLabel;
    QLineEdit *passwordEdit;
    QLabel *passwordLabel;

    QPushButton *testConnectionBtn;
};

#endif // CONFIGDIALOGPAGES_H
