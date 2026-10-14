#include "view.h"
#include "ui_view.h"
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QValueAxis>
view::view(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);
    //显示条形图
    setupChart();
}

view::~view()
{
    delete ui;
}
void view::setupChart()
{
    // 创建数据集合
    QBarSet *set0 = new QBarSet("17岁");
    QBarSet *set1 = new QBarSet("18岁");
    QBarSet *set2 = new QBarSet("19岁");

    // 添加数据
    *set0 << sAgeGrade.getStuAge(17,1) <<  sAgeGrade.getStuAge(17,2)
          <<  sAgeGrade.getStuAge(17,3)<<  sAgeGrade.getStuAge(17,4) <<
        sAgeGrade.getStuAge(17,5)<< sAgeGrade.getStuAge(17,6);
    *set1 << sAgeGrade.getStuAge(18,1) << sAgeGrade.getStuAge(18,2)
          << sAgeGrade.getStuAge(18,3) << sAgeGrade.getStuAge(18,4)
          << sAgeGrade.getStuAge(18,5)<<sAgeGrade.getStuAge(18,6);
    *set2 << sAgeGrade.getStuAge(19,1)<<  sAgeGrade.getStuAge(19,2)
          <<  sAgeGrade.getStuAge(19,3) <<  sAgeGrade.getStuAge(19,4)
          << sAgeGrade.getStuAge(19,5)<< sAgeGrade.getStuAge(19,6);
    //获取三个年龄的学生的数量
    int number17=0;
    int number18=0;
    int number19=0;

    for(int i=1;i<=6;i++)
    {
        number17+=sAgeGrade.getStuAge(17,i);
        number18+=sAgeGrade.getStuAge(18,i);
        number19+=sAgeGrade.getStuAge(19,i);
    }

     int numberAgeGrade=sAgeGrade.getStuNum();
    // 创建系列
    series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    // 创建图表
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("学生年龄分布图");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //算出学生年龄所占的百分比
    QString text17=QString("17岁占比: %1 %").arg((number17*100/numberAgeGrade));
    QString text18=QString("18岁占比: %1 %").arg((number18*100/numberAgeGrade));
    QString text19=QString("19岁占比: %1 %").arg((number19*100/numberAgeGrade));
    QGraphicsTextItem* textItem17 = new QGraphicsTextItem(text17, chart);
    //调好字体格式
    textItem17->setFont(QFont("微软雅黑", 10, QFont::Bold));
    textItem17->setDefaultTextColor(Qt::gray);
    //给出显示的位置
    textItem17->setPos(10,380);
    QGraphicsTextItem* textItem18= new QGraphicsTextItem(text18, chart);
    textItem18->setFont(QFont("微软雅黑", 10, QFont::Bold));
    textItem18->setDefaultTextColor(Qt::gray);
    textItem18->setPos(150,380);
    QGraphicsTextItem* textItem19 = new QGraphicsTextItem(text19, chart);
    textItem19->setFont(QFont("微软雅黑", 10, QFont::Bold));
    textItem19->setDefaultTextColor(Qt::gray);
    textItem19->setPos(280,380);
    // 创建坐标轴
    QStringList categories;
    categories << "一班" << "二班" << "三班" << "四班" << "五班"<<"六班";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();

    axisY->setRange(0, numberAgeGrade/10);
    axisY->setTitleText("人数");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图例
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // 获取设计器中提升的QChartView并设置图表
    QChartView *chartView = findChild<QChartView*>("chartView");
    if (chartView) {
        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    }
}
