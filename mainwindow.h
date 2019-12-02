#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void textoutput(QString);
    void vivod(QString );
private slots:
    void on_pushButton_clicked();

    void on_action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_2_customContextMenuRequested(const QPoint &pos);

private:
     QVector<QVector<QChar>> Obraz;
      QVector<QChar> alph = {'p','i','n','a','e','v','b','o'};
    Ui::MainWindow *ui;
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
