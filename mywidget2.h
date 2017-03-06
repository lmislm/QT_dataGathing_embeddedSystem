#ifndef MYWIDGET2_H
#define MYWIDGET2_H

#include <QWidget>
#include <qcheckbox.h>
#include <QTextCodec>
class MyWidget2 : public QWidget
{
    Q_OBJECT
public:

    MyWidget2(QWidget *parent = 0);
    QCheckBox *ck[4];
    QTextCodec *code;
private slots:
    //下拉列表、复选框
    void on_textchanged(QString);
    //radiobutton
    void on_radio_clicked();
    void on_check_clicked();
};

#endif // MYWIDGET2_H

