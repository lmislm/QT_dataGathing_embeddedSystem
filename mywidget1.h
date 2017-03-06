#ifndef MYWIDGET1_H
#define MYWIDGET1_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>


class MyWidget1 : public QWidget
{
    Q_OBJECT
public:
    MyWidget1(QWidget* parent = 0);
    QLineEdit *name;
    QLineEdit *password;
    QSqlDatabase db;
    //save the sql into local



private slots:
    void on_login_clicked();
    void on_reg_clicked();
    void on_updata(QString);
};

#endif // MYWIDGET1_H

