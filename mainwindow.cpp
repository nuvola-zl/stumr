#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include"login.h"
#include"stusql.h"
#include"dlg_change.h"
#include"view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   //先显示登录界面
    lo.show();
    //当接收到可登录的信号后进入到主窗口，登录界面隐藏
    auto  f=[&]()
    {
        this->show();
        lo.hide();
    };
    connect(&lo,&login::sendLogin,this,f);

   //建立左侧信息
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"学生管理系统";
    QTreeWidgetItem*pFather= new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pFather);
    l.clear();
    QStringList l1;
    l1<<"学生管理";
     QTreeWidgetItem*pChild1= new QTreeWidgetItem(pFather,l1);
    QStringList l2;
    l2<<"管理员管理系统";
     QTreeWidgetItem*pChild2= new QTreeWidgetItem(pFather,l2);
    pFather->addChild(pChild1);
     pFather->addChild(pChild2);
    //把所有的都展示出来
    ui->treeWidget->expandAll();

    m_ptrStu=stuSql::getinstance();
    //进入之后刷新界面
    update();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//退出按钮退出界面
void MainWindow::on_pushButton_clicked()
{
    this->close();

}

//产生随机电话号码的函数
QString  MainWindow::getPhoneNumber()
{
    //选择常用的开头
    QStringList prefixList = {"13", "14", "15", "16", "17", "18", "19"};
    int prefixIndex = QRandomGenerator::global()->bounded(prefixList.size());
    QString prefix = prefixList[prefixIndex];

    // 生成后9位随机数字
    QString suffix;
    for (int i = 0; i < 9; ++i) {
        int digit = QRandomGenerator::global()->bounded(10);
        suffix += QString::number(digit);
    }

    return prefix + suffix;
}
//生成随机微信号的函数
QString MainWindow::getWeChat()
{
    QString lastNames = "君不见黄河之水天上来";
    QString firstNames = "奔流到海不复回";
    QString symbols = "._-@#$%^&*()[]{}~`+=<>?";
    QString letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString numbers = "0123456789";

    QVector<QString> parts = {lastNames, firstNames, symbols, letters, numbers};
        QString chinese = QString("%1%2").arg(
            lastNames.at(QRandomGenerator::global()->bounded(lastNames.length())),
            firstNames.at(QRandomGenerator::global()->bounded(firstNames.length()))
            );
        int suffixLen = QRandomGenerator::global()->bounded(2, 6);
        QString suffix;
        for (int i = 0; i < suffixLen; ++i) {
            int charType = QRandomGenerator::global()->bounded(3);
            // 符号、字母、数字
            QString chars = (charType == 0) ? symbols : (charType == 1) ? letters : numbers;
            suffix += chars.at(QRandomGenerator::global()->bounded(chars.length()));
        }
        return chinese + suffix;
}
//模拟学生信息
void MainWindow::on_btn_s_clicked()
{


    //生成随机数


    QRandomGenerator c;
    QList<QString> l;
    l<<"陈曦"<<"林薇"<<"江楠"<<"陆瑶"<<
        "赵玥"<<"孙妍"<<"周彤"<<"吴悠"<<
        "郑琳"<<"王磊"<<"李哲"<<"张驰"<<
        "刘畅"<<"陈默"<<"林浩"<<"江宇"<<
        "孙雯"<<"周航"<<"吴凡"<<"郑楠"<<
        "王玥"<<"李薇"<<"张妍"<<"刘梅"<<
        "陈曦"<<"林哲"<<"江磊"<<"孙驰"<<
        "周瑶"<<"吴默"<<"郑宇"<<"王雯"<<
        "李航"<<"张凡"<<"刘楠"<<"陈妍"<<
         "林玥"<<"江薇"<<"孙哲"<<"周驰"<<
        "陈雨曦"<<"林晚薇"<<"江若楠"<<"陆思瑶"<<
        "赵嘉玥"<<"孙语妍"<<"周慕彤"<<"吴知悠"<<
        "郑思琳"<<"王梓磊"<<"李哲宁"<<"张亦驰"<<
        "刘语畅"<<"陈默轩"<<"林景浩"<<"江亦宇"<<
        "孙若雯"<<"周明航"<<"吴亦凡"<<"郑子楠"<<
        "王若玥"<<"李诗薇"<<"张思妍"<<"刘予畅"<<
        "陈雨桐"<<"林知夏"<<"江景然"<<"孙嘉航"<<
        "周语彤"<<"吴思默"<<"郑子轩"<<"王梓雯"<<
        "李哲宁"<<"张亦辰"<<"刘知遥"<<"陈慕妍"<<
        "林景玥"<<"江雨薇"<<"孙明哲"<<"周亦驰"<<
        "吴知夏"<<"郑思远"<<"王若轩"<<"李语然"<<
        "张思辰"<<"刘景航"<<"陈亦楠"<<"林予哲"<<
        "江慕瑶"<<"孙雨彤"<<"周思远"<<"吴梓轩"<<
        "郑知夏"<<"王语薇"<<"李亦驰"<<"张慕辰"<<
        "刘景然"<<"陈予瑶"<<"林思远"<<"江梓航"<<
        "孙语晨"<<"周亦楠"<<"吴知遥"<<"郑慕妍"<<
        "王景哲"<<"李雨辰"<<"张思瑶"<<"刘予薇"<<
        "陈知航"<<"林亦远"<<"江慕辰"<<"孙语彤"<<
         "周梓玥"<<"吴雨薇"<<"郑景驰"<<"王知夏";
    //生成一百个学生信息
    for(int i=0;i<100;i++)
    {
        auto grade=1;
        //班级是生成一到六
        auto iclass=c.bounded(1,7);
        //qDebug()<<"第"<<i<<iclass;
        StuInfo info;
        QString name;
        //获取QList中的数据
        name=l.at(i);
        //生成年龄从17到19
       auto age=c.bounded(17,20);
        info.name=name;
        info.age=age;
        info.grade=grade;
        info.iclass=iclass;
        //获取学号
        info.studentId=8209240+i;
        //调用函数生成电话和微信
        info.phone=getPhoneNumber();
        info.wechat=getWeChat();
       //把学生的信息添加到数据库中
       m_ptrStu->addStu(info);
    }
        //刷新界面
       update();
}

//实现添加学生信息
void MainWindow::on_btn_add_clicked()
{
    //调用函数让添加的时候内容为空值
    m_dlgAddStu.setType1();
    //等待用户操作
    m_dlgAddStu.exec();
    //更新页面
    update();

}

//清除学生信息
void MainWindow::on_btn_clear_clicked()
{


    //清除学生信息
    m_ptrStu->clearStu();

    update();
}

//进行一定的操作后刷新界面
void MainWindow::update()
{

   //清除界面上的内容
    ui->tableWidget->clear();
    //重新添加表头
     ui->tableWidget->setColumnCount(9);
    QStringList l;

    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setColumnWidth(0,62);
    ui->tableWidget->setColumnWidth(1,62);
    ui->tableWidget->setColumnWidth(2,62);
    ui->tableWidget->setColumnWidth(3,62);
    ui->tableWidget->setColumnWidth(4,62);
    ui->tableWidget->setColumnWidth(5,62);
    ui->tableWidget->setColumnWidth(6,62);
    ui->tableWidget->setColumnWidth(7,62);
    ui->tableWidget->setColumnWidth(8,62);


    //设置只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    //设置不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //更新下方学生数量
    auto cnt=m_ptrStu->getStuNum();
    ui->num_cnt->setText(QString("数量：%1").arg(cnt));
    //获取所有有学生的信息
    QList<StuInfo> ls=m_ptrStu->getPageStu(0,cnt);
    ui->tableWidget->setRowCount(cnt);
    //把信息重新加载到界面上
    for(int i=0;i<ls.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(ls[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(ls[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(ls[i].age)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ls[i].grade)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(ls[i].iclass)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(ls[i].studentId)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(ls[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(ls[i].wechat));
    }
}

//删除学生信息
void MainWindow::on_btn_delete_clicked()
{
    //获取当前的行数
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        int id=ui->tableWidget->item(i,1)->text().toUInt();
        //qDebug()<<id;
        m_ptrStu->deleteStu(id);
        QMessageBox::information(nullptr,"系统","删除成功");
        //删除之后重新加载页面
        update();

    }
    else{
        //没有选择某一行的话，给出提示
        QMessageBox::warning(nullptr,"删除","请选择要删除的学生");
        update();

    }
}

//修改学生信息
void MainWindow::on_btn_change_clicked()
{

    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        StuInfo info;

        info.id=ui->tableWidget->item(i,1)->text().toUInt();
        info.name=ui->tableWidget->item(i,2)->text();
        info.age=ui->tableWidget->item(i,3)->text().toUInt();
        info.grade=ui->tableWidget->item(i,4)->text().toUInt();
        info.iclass=ui->tableWidget->item(i,5)->text().toUInt();
        info.studentId=ui->tableWidget->item(i,6)->text().toUInt();
        info.phone=ui->tableWidget->item(i,7)->text();
        info.wechat=ui->tableWidget->item(i,8)->text();
        m_dlgchange.setType(info);



        //保持响应，持续监听和处理各种事件，直到关闭对话框
        m_dlgchange.exec();
        update();

    } else {
        //没有选择的话，给出提示
        QMessageBox::warning(this, "警告", "请先选择要修改的学生");
        update();
    }
}

//通过姓名查找学生
void MainWindow::on_btn_search_clicked()
{
    //获取输入的学生信息
    QString strName=ui->le_nameSearch->text();
    //判断是否为空
    if(strName.isEmpty())
    {
        //若为空给出提示
        QMessageBox::warning(nullptr,"警告","名字筛选为空");
        update();
        return;
    }
    //清除掉页面上的内容
    ui->tableWidget->clear();
    //重新加载页面上的内容
    ui->tableWidget->setColumnCount(9);
    QStringList l;
    //加载表头上的信息
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setColumnWidth(0,62);
    ui->tableWidget->setColumnWidth(1,62);
    ui->tableWidget->setColumnWidth(2,62);
    ui->tableWidget->setColumnWidth(3,62);
    ui->tableWidget->setColumnWidth(4,62);
    ui->tableWidget->setColumnWidth(5,62);
    ui->tableWidget->setColumnWidth(6,62);
    ui->tableWidget->setColumnWidth(7,62);
    ui->tableWidget->setColumnWidth(8,62);
    //设置只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //刷新学生的数量
    auto cnt=m_ptrStu->getStuNum();
    ui->num_cnt->setText(QString("数量：%1").arg(cnt));
    //获取所有的学生信息
    QList<StuInfo> ls=m_ptrStu->getPageStu(0,cnt);



    int index=0;
    for(int i=0;i<ls.size();i++)
    {
        //判断是否有被查找的索引
        if(!ls[i].name.contains(strName))
        {
            continue;
        }

        //如果有的话就加载到界面里面
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index+1)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(ls[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(ls[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(ls[i].age)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(ls[i].grade)));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(QString::number(ls[i].iclass)));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(QString::number(ls[i].studentId)));
        ui->tableWidget->setItem(index,7,new QTableWidgetItem(ls[i].phone));
        ui->tableWidget->setItem(index,8,new QTableWidgetItem(ls[i].wechat));
        index++;

    }

    //设置表格行数
     ui->tableWidget->setRowCount(index);

}


//查看学生年龄分布图
 void MainWindow::on_pushButton_2_clicked()
 {
     //展示条形图
     v=new view();
     v->show();
 }


//手动刷新界面
 void MainWindow::on_btn_update_clicked()
 {
     update();
 }

