#include "dlg_change.h"
#include "ui_dlg_change.h"
#include<QMessageBox>

dlg_change::dlg_change(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_change)
{
    ui->setupUi(this);
}

dlg_change::~dlg_change()
{
    delete ui;
}
void dlg_change::setType(StuInfo info)
{
    ui->li_id->setText(QString::number(info.id));
    ui->le_name->setText(info.name);
    ui->spinBox->setValue(info.age);
    ui->le_grade->setText(QString::number(info.grade));
    ui->le_iclassl->setText(QString::number(info.iclass));
    ui->le_studentId->setText(QString::number(info.studentId));
    ui->le_phone->setText(info.phone);
    ui->weChat->setText(info.wechat);
}
//修改后保存
void dlg_change::on_btn_csave_clicked()
{

    StuInfo info;
    auto  ptr=stuSql::getinstance();
    //获取输入的信息
    info.id=ui->li_id->text().toUInt();
    info.name=ui->le_name->text();
    info.age=ui->spinBox->text().toInt();
    info.grade=ui->le_grade->text().toInt();
    info.iclass=ui->le_iclassl->text().toInt();
    info.studentId=ui->le_studentId->text().toInt();
    info.phone=ui->le_phone->text();
    info.wechat=ui->weChat->text();
    //按照输入的信息，来更新学生的信息
    ptr->upDateStu(info);

    //提示修改是否成功
    QMessageBox::information(nullptr,"修改信息","修改成功");

    //点击保存后能关闭修改界面
    this->close();
}


//修改时取消修改
void dlg_change::on_btn_ccut_clicked()
{
    this->close();
}

