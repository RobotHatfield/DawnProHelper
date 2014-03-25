#include "configdialogpages.h"

#include <QtWidgets>
#include <QtSql>
#include <QDebug>

GeneralConfigPage::GeneralConfigPage(QWidget *parent)
{
    QLabel *EditorLabel = new QLabel(tr("General Label"),this);
}

UpdateConfigPage::UpdateConfigPage(QWidget *parent)
{
    QLabel *EditorLabel = new QLabel(tr("Update Label"),this);
}

SQLConfigPage::SQLConfigPage(QWidget *parent)
{
    QLabel *sqlLabel = new QLabel(tr("SQL Options"));

    QVBoxLayout *vLayout = new QVBoxLayout(this);

    QHBoxLayout *connectionNameLayout = new QHBoxLayout();

    connectionNameEdit = new QLineEdit();
    connectionNameLabel = new QLabel(tr("Connection Name:"));

    connectionNameLayout->addWidget(connectionNameLabel);
    connectionNameLayout->addWidget(connectionNameEdit);

    QHBoxLayout *hostNameLayout = new QHBoxLayout();

    hostNameEdit = new QLineEdit();
    hostNameLabel = new QLabel(tr("Hostname:"));

    hostNameLayout->addWidget(hostNameLabel);
    hostNameLayout->addWidget(hostNameEdit);

    QHBoxLayout *dbNameLayout = new QHBoxLayout();

    dbNameEdit = new QLineEdit();
    dbNameLabel = new QLabel(tr("Database Name:"));

    dbNameLayout->addWidget(dbNameLabel);
    dbNameLayout->addWidget(dbNameEdit);

    QHBoxLayout *userNameLayout = new QHBoxLayout();

    userNameEdit = new QLineEdit();
    userNameLabel = new QLabel(tr("User Name:"));

    userNameLayout->addWidget(userNameLabel);
    userNameLayout->addWidget(userNameEdit);

    QHBoxLayout *passwordLayout = new QHBoxLayout();

    passwordEdit = new QLineEdit();
    passwordLabel = new QLabel(tr("Password:"));

    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordEdit);

    QHBoxLayout *testConnectionLayout = new QHBoxLayout();

    testConnectionBtn = new QPushButton(tr(" Test Connection "));

    connect(testConnectionBtn,SIGNAL(clicked()),this,SLOT(checkTestConnection()));
    //connect(testConnectionBtn,SIGNAL(clicked()),this,SLOT(checkTestConnection()));

    testConnectionLayout->addStretch(0);
    testConnectionLayout->addWidget(testConnectionBtn);

    vLayout->addWidget(sqlLabel);
    vLayout->addLayout(connectionNameLayout);
    vLayout->addLayout(hostNameLayout);
    vLayout->addLayout(dbNameLayout);
    vLayout->addLayout(userNameLayout);
    vLayout->addLayout(passwordLayout);
    vLayout->addLayout(testConnectionLayout);
    vLayout->addStretch(0);
}

void SQLConfigPage::checkTestConnection()
{
    QString ConName = connectionNameEdit->text().toLatin1();
    QString HostName = hostNameEdit->text().toLatin1();
    QString DBName = dbNameEdit->text().toLatin1();
    QString UserName = userNameEdit->text().toLatin1();
    QString Password = passwordEdit->text().toLatin1();
    bool b = testConnection(ConName,HostName,DBName,UserName,Password);
    qDebug() << b;
}

bool SQLConfigPage::testConnection(QString conName, QString hostName, QString dbName, QString userName, QString pass)
{
    QString m_ConName = conName;
    QString m_HostName = hostName;
    QString m_DBName = dbName;
    QString m_UserName = userName;
    QString m_Password = pass;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC",m_ConName);
    db.setHostName(m_HostName);
    db.setDatabaseName(m_DBName);
    db.setUserName(m_UserName);
    db.setPassword(m_Password);

    bool ok = db.open();
    if (!ok)
    {
        QString errString = db.lastError().text();

        QMessageBox *msg = new QMessageBox(this);
        msg->setText(errString);
        msg->exec();
    }
    return ok;
}
