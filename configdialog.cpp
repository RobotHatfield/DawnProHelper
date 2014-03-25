#include "configdialog.h"
#include "configdialogpages.h"

#include <QtWidgets>

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent)
{
    this->setMinimumSize(400,250);

    QHBoxLayout *hLayout = new QHBoxLayout();

    contentsWidget = new QListWidget();
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(96, 84));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(128);
    contentsWidget->setSpacing(12);

    pagesWidget = new QStackedWidget();
    pagesWidget->addWidget(new GeneralConfigPage);
    pagesWidget->addWidget(new UpdateConfigPage);
    pagesWidget->addWidget(new SQLConfigPage);

    createIcons();
    contentsWidget->setCurrentRow(0);

    connect(contentsWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    hLayout->addWidget(contentsWidget);
    hLayout->addWidget(pagesWidget);

    btnLayout = new QHBoxLayout();

    okBtn = new QPushButton(tr("Ok"));
    applyBtn = new QPushButton(tr("Apply"));
    closeBtn = new QPushButton(tr("Close"));

    btnLayout->addStretch(0);
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(applyBtn);
    btnLayout->addWidget(closeBtn);

    connect(okBtn,SIGNAL(pressed()),this,SLOT(okBtnPress()));
    connect(applyBtn,SIGNAL(pressed()),this,SLOT(applyBtnPress()));
    connect(closeBtn,SIGNAL(pressed()),this,SLOT(close()));

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addLayout(hLayout);
    vLayout->addLayout(btnLayout);

}

void ConfigDialog::createIcons()
{
QListWidgetItem *configButton = new QListWidgetItem(contentsWidget);
configButton->setIcon(QIcon(":/images/config.png"));
configButton->setText(tr("General"));
configButton->setTextAlignment(Qt::AlignHCenter);
configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

QListWidgetItem *updateButton = new QListWidgetItem(contentsWidget);
updateButton->setIcon(QIcon(":/images/update.png"));
updateButton->setText(tr("Update"));
updateButton->setTextAlignment(Qt::AlignHCenter);
updateButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

QListWidgetItem *queryButton = new QListWidgetItem(contentsWidget);
queryButton->setIcon(QIcon(":/images/query.png"));
queryButton->setText(tr("Query"));
queryButton->setTextAlignment(Qt::AlignHCenter);
queryButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

connect(contentsWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
        this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}

void ConfigDialog::okBtnPress()
{
    applyBtnPress();
    this->close();
}

void ConfigDialog::applyBtnPress()
{
    //
}
