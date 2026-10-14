#include "login.h"
#include "ui_login.h"
#include<QMessageBox>


login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}

void login::on_exitButton_clicked()
{
    //按退出按钮，退出界面
    this->close();

}

//登录按钮
void login::on_setButton_clicked()
{
    //点击登录后发送登录的信号
emit sendLogin();

}



