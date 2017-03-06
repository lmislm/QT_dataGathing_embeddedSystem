#include "tempview.h"
#include "qpainter.h"
#include "qdebug.h"
#include "mywidget1.h"
#include <QPoint>

TempView::TempView(QWidget*parent):QWidget(parent)
{

}
  //extern int  n;
void TempView::paintEvent(QPaintEvent *){
    QPainter pp(this);
    //QTextCodec *code=QTextCodec::codecForLocale();
    //point from the left and up begin
    pp.drawText(QPoint(10,10),"temp");
    pp.drawLine(QPoint(10,10),QPoint(10,150));
    pp.drawLine(QPoint(10,10),QPoint(15,15));
    pp.drawLine(QPoint(10,10),QPoint(5,15));
    //pp.setBrush(Qt::black);    hard point
    //pp.drawElipse(QPoint(70,90),2,2);    
    pp.drawLine(QPoint(10,80),QPoint(150,80));//mid line
    pp.drawLine(QPoint(145,75),QPoint(150,80));//up jiantou
    pp.drawLine(QPoint(145,85),QPoint(150,80));//down jiantou

    //pp.drawLine(QPoint(20,n),QPoint(25,n));

    char *ynum[]={"40","30","20","10","","-10","-20","-30","-40"};//,"-20","-30","-40"
    for(int n=40;n<130;n+=10)
    {
        pp.drawText(QPoint(10,n),ynum[(n-40)/10]);
        pp.drawText(QPoint(n,80),ynum[(n-40)/20]);
    }
//    for(int j=20;j<150;j+=10)
//        pp.drawLine(QPoint(10,j),QPoint(15,j));   //10 to 15 is the long of kedu
//        pp.drawText(QPoint(15,j),ynum[(j-10)/20]);

//    for(int i=20;i<150;i+=10)
//        pp.drawLine(QPoint(i,75),QPoint(i,80));

    //third jian tou
    pp.drawLine(QPoint(5,145),QPoint(10,150));
    pp.drawLine(QPoint(15,145),QPoint(10,150));
    // begin check the table;
    QSqlQuery q(db);

    points.clear();

    q.exec("select * from tempTable");

    while(q.next())
    {


        //change the float to int
        int t1=(int)q.value(1).toFloat();

        int t2=q.value(2).toInt();

        QDateTime qt=QDateTime::fromTime_t(t2);
        int b=qt.time().hour();
        qDebug()<<b;

         QPoint p1=QPoint(10+10*b,80-t1);    //原点(10,80),每格刻度10，QPoint
         //insert the painter;
         points.append(p1);


    }
    //check the point numbers
      for(int i=0;i<points.size()-1;i++)
       {
             pp.drawLine(points.at(i),points.at(i+1));
       }
//

//    pp.drawLine(QPoint(100,10),QPoint(10,100));
}
