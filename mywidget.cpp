#include "mywidget.h"
#include "qdebug.h"
MyWidget::MyWidget(QWidget *parent):QWidget(parent)
{
    this->setGeometry(100,100,400,400);

    QLabel *ll1 = new QLabel("userName",this); // ji yu  dang qian  chuang kou
    ll1->setGeometry(50,50,60,30);

    QLabel *ll2 = new QLabel("passWord",this); // ji yu  dang qian  chuang kou
    ll2->setGeometry(50,100,60,30);

    name = new QLineEdit(this);
    name->setGeometry(120,50,100,30);

    password = new QLineEdit(this);
    password->setEchoMode(QLineEdit::Password);
    password->setGeometry(120,100,100,30);

    login = new QPushButton("login",this);
    login->setGeometry(80,200,60,30);

    reg = new QPushButton("Reg",this);
    reg->setGeometry(150,200,60,30);    //tao lu  :  chuang jian dui  xiang  ,  zhi ding  wei zhi
    //guan lian xin hao
    connect(login,SIGNAL(clicked()),this,SLOT(on_login_clicked()));//this当前对象
    connect(reg,SIGNAL(clicked()),this,SLOT(on_reg_clicked()));

}
void MyWidget::on_login_clicked(){

    qDebug() << "login";
}
void MyWidget::on_reg_clicked(){

    qDebug() << "reg";
}



