#include "mywidget1.h"
#include "qgridlayout.h"//网格布局的头文件
#include <QHBoxLayout> //水平布局的头文件
#include "qdebug.h"
#include "qmessagebox.h"
#include "qstring.h"
#include "mydialog.h"
#include "qfile.h"
#include <QtSql>
//#include "mywidget2.h"
#include "mainview.h"
MyWidget1::MyWidget1(QWidget *parent):QWidget(parent)
{

     QLabel *ll1 = new QLabel("UserName");
     QLabel *ll2 = new QLabel("PassWord");
     name = new QLineEdit();
     password = new QLineEdit();
     password->setEchoMode(QLineEdit::Password);
     QPushButton *login = new QPushButton("login");
     QPushButton *reg = new QPushButton("reg");


     QGridLayout *grid = new QGridLayout();
     grid->addWidget(ll1,2,1);
     grid->addWidget(name,2,2,1,2);

     grid->addWidget(ll2,3,1);
     grid->addWidget(password,3,2,1,2);

     grid->addWidget(login,4,1);
     grid->addWidget(reg,4,3);

     grid->setRowStretch(0,1);
     grid->setRowStretch(5,1);

     grid->setColumnStretch(0,1);
     grid->setColumnStretch(6,1);

     QHBoxLayout *hlay = new QHBoxLayout;
     QLabel *hh = new QLabel("Login");
     hlay->addStretch(1);
     hlay->addWidget(hh);
     hlay->addStretch(1);
     grid->addLayout(hlay,1,1,1,3);


     this->setLayout(grid);

     connect(login,SIGNAL(clicked()),this,SLOT(on_login_clicked()));//this当前对象
     connect(reg,SIGNAL(clicked()),this,SLOT(on_reg_clicked()));


     db=QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("userDb1");
     if(!db.open())
     {
       qDebug()<<"database open error";
     }
     QSqlQuery q(db);
     if(q.exec("CREATE TABLE user1(id INT PRIMARY KEY,name VARCHAR(20),password VARCHAR(20))")==false)
     {
        qDebug()<<"creat table error";
     }
     q.exec("drop table tempTable");

     if(q.exec("create table tempTable(id int primary key,tempValue float,date int)")==false){
        qDebug()<<"creat table  temptable error";
     }
    //insert some datas for example

     QDateTime tt=QDateTime::currentDateTime();
     int dd=tt.toTime_t();

     QDateTime ss=QDateTime::fromTime_t(dd);
     qDebug()<<ss.time().hour();

     int hour=tt.time().hour();
     //turn to a time chuo (shijian chuo
     qDebug()<<"datetime="<<dd<<"time ---"<< hour;
     for(int i=hour;i>=0;i--)
     {
     QString sql=QString("insert into tempTable (tempValue,date) values ('%1','%2')").arg(10+i).arg(dd-i*3600);

     if(q.exec(sql))
         qDebug()<<"ok";
     else
         qDebug()<<"bu ok";
     }
     q.exec("select * from tempTable");
     while(q.next()){
        int n=q.value(2).toInt();
         qDebug()<<n/36000000;
        }
}


void MyWidget1::on_login_clicked(){

    qDebug() << "login";
    QString str = name->text();
    if(str.isEmpty()){
        QMessageBox::information(this,"warning","please input user's name");

    }else{
        if(password->text().isEmpty()){

            QMessageBox::information(this,"warning","please input password");

        }else{
           QSqlQuery q(db);
           //maybe the password is pass or not
           QString sql=QString("select * from user1 where name='%1' and password='%2'").arg(name->text()).arg(password->text());
           qDebug()<<sql;
           q.exec(sql);
           if(q.next()){
               this->hide();
                MainView *mv=new MainView(db);
                mv->show();

               qDebug()<<"login success";
//                break;
           }
           else
               QMessageBox::information(this,"tishi","input error");

           qDebug() << "UserName:"<<name->text()<<"PassWord"<<password->text();

        }

    }

    
}
void MyWidget1::on_reg_clicked(){

    this->hide();
    mydialog *mm=new mydialog;

    connect(mm,SIGNAL(sig(QString)),this,SLOT(on_updata(QString)));
    QString ss=mm->exec();

     qDebug() << ss;
//   if(!ss.isEmpty())
//        this-if(QString compare(ss[0],name)==0)>show();
     if(!ss.isEmpty())
     {

       QStringList mm=ss.split("-");
        //split data

       QSqlQuery q(db);

      q.exec("select * from user1");
      int s=0;
      while(q.next())
       {//bian li
         QString name=q.value(1).toString();
         //check the user,had the past name;
         qDebug()<<name<<"---"<<mm.at(0);

         if(QString::compare(mm.at(0),name)==0)
         {
              s=1;
              break ;
          }
       }
      if(s==1)
          QMessageBox::information(this,"tishi","this  name is used !");
      else
      {
       QString sql=QString("insert into user1  (name,password) values('%1','%2')").arg(mm.at(0)).arg(mm.at(1));

       qDebug()<< sql;
       if(q.exec(sql))
       {
           //information back to login demo

       }
       else
            qDebug()<<"no";
     }

      q.exec("select * from user1");

      while(q.next())
       {//bian li

         QString name=q.value(1).toString();

          qDebug()<< name;

       }

 }
    delete mm;
    this->show();
}
void MyWidget1::on_updata(QString ss){
    QStringList mm=ss.split("-");
//    qDebug()<<ss;
    name->setText(mm.at(0));
    password->setText(mm.at(1));
}

