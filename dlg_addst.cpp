#include "dlg_addst.h"
#include "ui_dlg_addst.h"
#include"stusql.h"
#include<QMessageBox>

Dlg_AddSt::Dlg_AddSt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_AddSt)
{
    ui->setupUi(this);
}

Dlg_AddSt::~Dlg_AddSt()
{
    delete ui;
}
//初始化添加的界面里面的数值
void Dlg_AddSt::setType1()
{
    //isUpdate=isAdd;
    ui->le_name->setText("");
    ui->spinBox->setValue(0);
    ui->le_grade->setText(0);
    ui->le_iclass->setText(0);
    ui->le_studentId->setText(0);
    ui->le_phone->setText("");
    ui->le_wechat->setText("");
}
//获取添加后的信息
void Dlg_AddSt::setType(StuInfo info)
{

    ui->le_name->setText(info.name);
    ui->spinBox->setValue(info.age);
    ui->le_grade->setText(QString::number(info.grade));
    ui->le_iclass->setText(QString::number(info.iclass));
    ui->le_studentId->setText(QString::number(info.studentId));
    ui->le_phone->setText(info.phone);
    ui->le_wechat->setText(info.wechat);

}
//添加信息后的保存
void Dlg_AddSt::on_btn_save_clicked()
{
    StuInfo info;
    auto  ptr=stuSql::getinstance();
    //获取输入的信息
    info.name=ui->le_name->text();
    info.age=ui->spinBox->text().toInt();
    info.grade=ui->le_grade->text().toInt();
    info.iclass=ui->le_iclass->text().toInt();
    info.studentId=ui->le_studentId->text().toInt();
    info.phone=ui->le_phone->text();
    info.wechat=ui->le_wechat->text();
    //把学生的信息添加上去
        ptr->addStu(info);
    //显示添加成功的信息
    QMessageBox::information(nullptr,"添加信息","存储成功");
        //关闭窗口
    this->close();
}

//添加时取消
void Dlg_AddSt::on_btn_cut_clicked()
{
    this->close();
}
