#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include<QTreeWidgetItem>
#include<QFile>
#include<QKeyEvent>
#include<QCoreApplication>
#include<QRandomGenerator>
#include<QDebug>
#include<QDataStream>
#include"stusql.h"
#include"dlg_addst.h"
#include"dlg_change.h"
#include"view.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //产生随机电话号码的函数声名
    QString getPhoneNumber();
    //产生随机微信的函数的声明
    QString getWeChat();


private slots:
    //主界面退出按钮
    void on_pushButton_clicked();
    //主界面模拟学生信息的按钮
    void on_btn_s_clicked();
   //主界面添加学生信息的按钮
    void on_btn_add_clicked();
   //主界面清空学生列表的按钮
    void on_btn_clear_clicked();
    //主界面删除学生的按钮
    void on_btn_delete_clicked();
   //主界面修改学生信息的按钮
    void on_btn_change_clicked();
   //主界面搜索学生信息的按钮
    void on_btn_search_clicked();
    //主界面查看学生年龄分布条形图的按钮
    void on_pushButton_2_clicked();

    //主界面刷新按钮
    void on_btn_update_clicked();

private:
    //主界面当进行一定的学生信息操作后刷新页面
    void update();

private:
    Ui::MainWindow *ui;
    login lo;
    stuSql*m_ptrStu;
    QStringList m_name;
    //添加
    Dlg_AddSt  m_dlgAddStu;
    //修改
    dlg_change  m_dlgchange;
    //条形图
    view *v;

};
#endif // MAINWINDOW_H
