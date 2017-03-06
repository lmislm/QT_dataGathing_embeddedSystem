#include "mainview.h"
#include "qtablewidget.h" //split demo
#include "qpalette.h"  //change color header
#include "qpainter.h"
#include "tempview.h"
MainView::MainView(QSqlDatabase db,QWidget*parent):QWidget(parent)
{
    QTabWidget *tab=new QTabWidget(this);
    tab->setGeometry(10,10,300,200);
    char *titles[]={"温度","湿度","可燃气浓度"};

    code=QTextCodec::codecForLocale();// quan ju var
    for(int i=0;i<3;i++){
        if(i==0)
        {     //add the {} is very important
            page[0]=new TempView(this);
        //mainview object send todb
            ((TempView*)page[0])->db=db;
        }
        else
            page[i]=new QWidget(this);
        //add three pages
        tab->addTab(page[i],code->toUnicode(titles[i]));

    //change the background
//    QPalette pat1=page[0]->palette();
//    pat1.setColor(QPalette::Background,QColor(Qt::red));
//    page[0]->setPalette(pat1);
//
//    QPalette pat2=page[1]->palette();
//    pat2.setColor(QPalette::Background,QColor(Qt::blue));
//    page[1]->setPalette(pat2);
//     page[i]=new QWidget(this);
//     tab->addTab(page[i],code->toUnicode(titles[i]));
    }
//    pat1.setColor(QPalette::Background,QColor(Qt::red));
//    page[0]->setPalette(pat1);
}
//void MainView::paintEvent(QPaintEvent *){
//    QPainter painter(this);
//    painter.drawLine(QPoint(10,10),QPoint(100,100));
//    painter.drawLine(QPoint(100,10),QPoint(10,100));
//}

