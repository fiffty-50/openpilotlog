#include "totalswidget.h"
#include "ui_totalswidget.h"
// Debug Makro
#define DEB(expr) \
    qDebug() << __PRETTY_FUNCTION__ << "\t" << expr

TotalsWidget::TotalsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TotalsWidget)
{
    ui->setupUi(this);
    auto data = Stat::totals();
    DEB("Filling Totals Line Edits...");
    //DEB("data: " << data);
    for (const auto &field : data) {
        auto line_edit = parent->findChild<QLineEdit *>(field.first + "LineEdit");
        line_edit->setText(field.second);
    }
    QSettings settings;
    QString name = settings.value("userdata/picfirstname").toString();
    if(!name.isEmpty()) {
        QString salutation = "Welcome to openPilotLog, " + name + QLatin1Char('!');
        ui->welcomeLabel->setText(salutation);
    }
}

TotalsWidget::~TotalsWidget()
{
    delete ui;
}
