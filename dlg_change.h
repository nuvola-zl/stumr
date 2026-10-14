#ifndef DLG_CHANGE_H
#define DLG_CHANGE_H

#include <QDialog>
#include"stusql.h"

namespace Ui {
class dlg_change;
}

class dlg_change : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_change(QWidget *parent = nullptr);
    ~dlg_change();
    void setType(StuInfo info);

private slots:
    //修改的之后保存的槽函数
    void on_btn_csave_clicked();
//修改的时候取消的槽函数
    void on_btn_ccut_clicked();

private:
    Ui::dlg_change *ui;

};

#endif // DLG_CHANGE_H
