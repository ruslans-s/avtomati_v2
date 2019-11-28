#ifndef NASTORIKA_TEXT_H
#define NASTORIKA_TEXT_H

#include <QDialog>

namespace Ui {
class nastorika_text;
}

class nastorika_text : public QDialog
{
    Q_OBJECT

public:
    explicit nastorika_text(QWidget *parent = nullptr);
    ~nastorika_text();

private:
    Ui::nastorika_text *ui;
};

#endif // NASTORIKA_TEXT_H
