#include "nastorika_text.h"
#include "ui_nastorika_text.h"

nastorika_text::nastorika_text(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nastorika_text)
{
    ui->setupUi(this);
}

nastorika_text::~nastorika_text()
{
    delete ui;
}
