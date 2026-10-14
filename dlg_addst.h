#ifndef DLG_ADDST_H
#define DLG_ADDST_H
#include <QDialog>
#include"stusql.h"
namespace Ui {
class Dlg_AddSt;
}
class Dlg_AddSt : public QDialog
{
    Q_OBJECT

public:

    explicit Dlg_AddSt(QWidget *parent = nullptr);
    ~Dlg_AddSt();
    void setType(StuInfo info={});
    void setType1();

private slots:
    //添加学生的后保存的槽函数
    void on_btn_save_clicked();
//添加学生时取消的槽函数
    void on_btn_cut_clicked();

private:
    Ui::Dlg_AddSt *ui;


};

#endif // DLG_ADDST_H
