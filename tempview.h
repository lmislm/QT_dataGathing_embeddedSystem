#ifndef TEMPVIEW_H
#define TEMPVIEW_H

#include <QWidget>
#include <QVector>   //tell the contain
// input a database
#include <QtSql>

class TempView : public QWidget
{
public:
    TempView(QWidget*parent=0);
    void paintEvent(QPaintEvent *);
    QVector<QPoint> points; //save all the points
    QSqlDatabase db;
};

#endif // TEMPVIEW_H
