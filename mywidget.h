#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"

class MyWidget : public QWidget // ji cheng
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0); //0 --> NULL
    QLineEdit *name;
    QLineEdit *password;
    QPushButton *login;
    QPushButton *reg;

private slots:
    virtual void on_login_clicked();
    virtual void on_reg_clicked();
};
#endif // MYWIDGET_H

