#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QLabel>
#include<QPixmap>


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


signals:
    //当登录被触发的时候的信号
    void sendLogin();


private slots:

   //登录页面的取消按钮的槽函数
    void on_exitButton_clicked();
   //登录页面的登录按钮的槽函数
    void on_setButton_clicked();

private:
    Ui::login *ui; 
};

#endif // LOGIN_H
