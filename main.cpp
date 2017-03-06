#include "qapplication.h"
#include "qwidget.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "mywidget1.h"
#include "mywidget2.h"
int main(int argc,char ** argv){

       QApplication app(argc,argv);

            MyWidget1 mm;
            mm.show();

            //QWidget ww;

            //ww.setGeometry(200,100,300,200);
            //ww.setMinimumSize(300,200);
            //ww.setMaximumSize(300,200);

//            QLabel *ll1 = new QLabel("UserName");
//            QLabel *ll2 = new QLabel("PassWord");
//            ll1->setParent(&ww);
//            ll1->setGeometry(50,50,60,30);
//
//            ll2->setParent(&ww);
//            ll2->setGeometry(50,120,60,30);
//            QLineEdit *et1 = new QLineEdit();
//            QLineEdit *et2 = new QLineEdit();
//            et1->setParent(&ww);
//            et1->setGeometry(120,50,60,30);
//
//            et2->setParent(&ww);
//            et2->setGeometry(120,120,60,30);
//
//            QPushButton *btn1 = new QPushButton("Login");
//            QPushButton *btn2 = new QPushButton("Registe");
//
//            btn1->setParent(&ww);
//            btn1->setGeometry(80,200,60,30);
//
//            btn2->setParent(&ww);
//            btn2->setGeometry(150,200,60,30);
//
//            ww.show();
       return app.exec();
}

