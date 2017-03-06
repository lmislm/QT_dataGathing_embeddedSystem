#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include "qlineedit.h"
#include "qcheckbox.h"
class mydialog : public QDialog
{
    Q_OBJECT
public:
    mydialog(QWidget* parent=0);
    QLineEdit *name;
    QLineEdit *password;
    QCheckBox *ck[4];          //nadao suoyous
    QString sex;
    QString banji;
    QString fav;
    int flag;
    QString exec();

signals:
    void sig(QString);

private slots:
    void on_radio_clicked();
    void on_check_clicked();
    void on_combo_changed(QString);
    void on_Yes_clicked();
};

#endif // MYDIALOG_H
