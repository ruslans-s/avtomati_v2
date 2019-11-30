#include "nastorika_text.h"
#include "ui_nastorika_text.h"
#include "mainwindow.h"
nastorika_text::nastorika_text(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nastorika_text)
{
    ui->setupUi(this);
}

nastorika_text::~nastorika_text()
{

    delete ui;
     //MainWindow.vivod("Конец");
}

void nastorika_text::on_pushButton_clicked()
{
    QString tempstring;
   ui->listWidget->addItem(ui->textsize->text());
}
