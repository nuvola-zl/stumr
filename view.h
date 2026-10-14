#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include"stusql.h"
class QChart;
class QBarSeries;
class QBarSet;
class QBarCategoryAxis;
class QValueAxis;
class QChartView;

namespace Ui {
class view;
}

class view : public QWidget
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = nullptr);
    ~view();

private:
    Ui::view *ui;
    QChart *chart;
    QBarSeries *series;
    stuSql sAgeGrade;
   //建立条形图
    void setupChart();
};

#endif // VIEW_H
