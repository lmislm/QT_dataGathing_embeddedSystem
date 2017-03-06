#include "mydialog.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "qtextcodec.h"
#include "qcheckbox.h"
#include "qradiobutton.h"
#include "qcombobox.h"
#include "qlineedit.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
mydialog::mydialog(QWidget*parent):QDialog(parent)
{
    QGridLayout *grid=new QGridLayout;
        grid->setRowStretch(0,1);
        grid->setRowStretch(8,1);
        grid->setColumnStretch(0,1);
        grid->setColumnStretch(4,1);

        QTextCodec *code=QTextCodec::codecForLocale();
        QLabel *ll1=new QLabel(code->toUnicode("用户名"));
        QLabel *ll2=new QLabel(code->toUnicode("密码"));
        QLabel *ll3=new QLabel(code->toUnicode("性别"));
        QLabel *ll4=new QLabel(code->toUnicode("班级"));
        QLabel *ll5=new QLabel(code->toUnicode("爱好"));
        grid->addWidget(ll1,1,1);
        grid->addWidget(ll2,2,1);
        grid->addWidget(ll3,3,1);
        grid->addWidget(ll4,4,1);
        grid->addWidget(ll5,5,1);
        name=new QLineEdit();
        password=new QLineEdit();
        password->setEchoMode(QLineEdit::Password);
        grid->addWidget(name,1,2,1,2);
        grid->addWidget(password,2,2,1,2);


        QComboBox *com=new QComboBox;
        com->addItem("iot-1-class");
        com->addItem("iot-2-class");
        com->addItem("iot-2-class");

         grid->addWidget(com,4,2,1,2);
         banji="iot-1-class";
         connect(com,SIGNAL(currentIndexChanged(QString)),
                 this,SLOT(on_combo_changed(QString)));
         QRadioButton *r1=new QRadioButton(code->toUnicode("男"));
         QRadioButton *r2=new QRadioButton(code->toUnicode("女"));
         grid->addWidget(r1,3,2);
         grid->addWidget(r2,3,3);

         connect(r1,SIGNAL(clicked()),this,SLOT(on_radio_clicked()));
         connect(r2,SIGNAL(clicked()),this,SLOT(on_radio_clicked()));
         r1->setChecked(true);
         sex="男";

         //xing qu aihao
         char *name[]={"洗澡","打球","打斗斗","玩蛇"};
         for(int i=0;i<4;i++){
            ck[i]=new QCheckBox(code->toUnicode(name[i]));
            connect(ck[i],SIGNAL(clicked()),
                this,SLOT(on_check_clicked()));

         }
         grid->addWidget(ck[0],5,2);
         grid->addWidget(ck[1],5,3);
         grid->addWidget(ck[2],6,2);
         grid->addWidget(ck[3],6,3);
         fav="";

         QPushButton *ok=new QPushButton(code->toUnicode("确定"));
         QPushButton *cancel=new QPushButton(code->toUnicode("取消"));
         grid->addWidget(ok,7,1);
         grid->addWidget(cancel,7,3);

         connect(ok,SIGNAL(clicked()),this,
                 SLOT(on_Yes_clicked()));
         connect(cancel,SIGNAL(clicked()),this,
                 SLOT(close()));
        flag =0;

        this->setLayout(grid);
}
void mydialog::on_Yes_clicked(){
    if(name->text().isEmpty() | password->text().isEmpty()||
       fav.isEmpty())
        QMessageBox::information(this,"tishi",
                                 "please input completely");
    else{
        flag = 1;
        this->close();
    }
}
//void mydialog::close(){
//
//}
QString mydialog::exec(){ //
    QDialog::exec();
    if(this->flag==1){
        QString ss=name->text()+"-"+password->text()+"-"+sex
        +"-"+banji+"-"+fav;
//        return name->text()+"-"+pass->text()+"-"+sex
//                +"-"+banji+"-"+fav;
        emit(sig(ss));
        return ss;
    }
    return QString(NULL);
}
void mydialog::on_radio_clicked(){
    QString ss=((QRadioButton*)sender())->text();
    this->sex=ss;
}
void mydialog::on_check_clicked(){
    QString ss;
    for(int i=0;i<4;i++){
        if(ck[i]->isChecked()){
            ss+= ck[i]->text()+"-";
        }
    }
    fav=ss;
//    //chai fen zi fuchuang
//    QStringList mm=ss.split("-");
//    for(int i=0;i<mm.size();i++)
//        qDebug()<<mm.at(i);
}
void mydialog::on_combo_changed(QString ss){
    banji=ss;
}
