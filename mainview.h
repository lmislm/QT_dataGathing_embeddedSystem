#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QTextCodec>
#include <QtSql> 
class MainView : public QWidget
{
    Q_OBJECT
public:
    MainView(QSqlDatabase db,QWidget*parent=0);

    QWidget *page[3];
    QTextCodec *code;

    QSqlDatabase db;
};

#endif // MAINVIEW_H
