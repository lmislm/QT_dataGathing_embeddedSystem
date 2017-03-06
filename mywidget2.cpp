#include "mywidget2.h"
#include "QVBoxLayout"
#include "qcombobox.h"
#include "qradiobutton.h"
#include "qcheckbox.h"
#include "qdebug.h"
#include "QHBoxLayout" //shui ping bu ju
MyWidget2::MyWidget2(QWidget *parent):QWidget(parent)
{

    QVBoxLayout *vlay = new QVBoxLayout;
    QComboBox *cc = new QComboBox;
    cc->addItem("iot 1 class");
    cc->addItem("iot 2 class");
    cc->addItem("iot 3 class");

    vlay->addWidget(cc);
    //dan xuan kuang
    QRadioButton *r1 = new QRadioButton("male");
    QRadioButton *r2 = new QRadioButton("female");

    QHBoxLayout *hh = new QHBoxLayout;
    hh->addWidget(r1);
    hh->addWidget(r2);

    vlay->addLayout(hh);
    connect(r1,SIGNAL(clicked()),this,SLOT(on_radio_clicked()));
    connect(r2,SIGNAL(clicked()),this,SLOT(on_radio_clicked()));

    // bian ma
    code = QTextCodec::codecForLocale();
    char *names[4] = {"basketball","game","旅游","huaxue"};


    for(int i = 0; i < 4;i++){
        ck[i] = new QCheckBox(code->toUnicode(names[i]));
        connect(ck[i],SIGNAL(clicked()),this,SLOT(on_check_clicked()));
        vlay->addWidget(ck[i]);
    }



    this->setLayout(vlay);
    //下拉列表 索引行 改变时 调用
    connect(cc,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_textchanged(QString)));


}
void MyWidget2::on_check_clicked(){

    QString str;
    for(int j = 0; j < 4; j++){

        if(ck[j]->isChecked()){

            str += ck[j]->text()+"-";
        }
    }

    qDebug()<< str;
}
void MyWidget2::on_radio_clicked(){

    QRadioButton *rr = (QRadioButton*) sender(); // fan hui fa xin hao de dui xiang
    qDebug()<< rr->text();
}
void MyWidget2::on_textchanged(QString str){

    qDebug() << str;
}



