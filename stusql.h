#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
//包含相应的头文件
#include<QSqlDatabase>
//定义一个包含学生信息的结构体
struct StuInfo
{
    StuInfo() {}
    int id;
    QString name;
    quint8 age;
    quint16 grade;
    quint16 iclass;
    quint32 studentId;
    QString phone;
    QString wechat;
};


class stuSql : public QObject
{
    Q_OBJECT
public:
    //定义一个静态指针
    static stuSql*ptrstuSql;
    static stuSql*getinstance()
    {
        //初始化
         if(ptrstuSql==nullptr)
        {
            ptrstuSql=new stuSql;

         }
         return ptrstuSql;
    }


    explicit stuSql(QObject *parent = nullptr);

    //初始化
    void init();

    //查询学生数量；
    quint32 getStuNum();

    //查询第几页学生数据
    QList<StuInfo>getPageStu(quint32 page,quint32 pageNum);

    //添加学生
    bool addStu(StuInfo info);
       //删除学生
    bool deleteStu(int id);
    //清空学生表
    bool clearStu();
    //修改学生信息
    bool upDateStu(StuInfo info);
    //


    //获取学生的年龄和班级
    quint32 getStuAge(int age,int iclass );

public:
    //成员变量
    QSqlDatabase  m_db;
     static stuSql* m_instance;

signals:
};

#endif // STUSQL_H
