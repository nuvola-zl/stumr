#include "stusql.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include<QCoreApplication>
stuSql*stuSql::ptrstuSql=nullptr;

stuSql::stuSql(QObject *parent)
    : QObject{parent}
{
    init();

}
//初始化数据库的连接
void stuSql::init()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        m_db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(QCoreApplication::applicationDirPath() + "/data.db");
    }
    if (!m_db.open()) {
        QMessageBox::warning(nullptr, "cannot", "have an error");
    }
}

//添加学生信息的实现
bool stuSql:: addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString str=QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')")
                      .arg(info.name)
                      .arg(info.age)
                      .arg(info.grade)
                      .arg(info.iclass)
                      .arg(info.studentId)
                      .arg(info.phone)
                      .arg(info.wechat);
    return sql.exec(str);
}


//获取学生数量
quint32 stuSql::  getStuNum()
{
      QSqlQuery sql(m_db);
    quint32  zeroNum=0;
      sql.exec("select count(id) from student;");
      while(sql.next())
      {
          zeroNum=sql.value(0).toUInt();
      }
      return zeroNum;
}
//获取某个年龄下某班的学生的个数
quint32 stuSql::getStuAge(int age,int iclass)
{
    QSqlQuery sql(m_db);
    //初始化个数为零
    quint32 studentCount = 0;
 QString query = QString("SELECT COUNT(id) FROM student WHERE age = %1 AND class = %2")
                     .arg(age)
                        .arg(iclass);
    if (sql.exec(query)) {
        if (sql.next()) {
            studentCount = sql.value(0).toUInt();
            qDebug() << "符合条件的学生数量:" << studentCount;
        }
    } else {
        qCritical() << "SQL执行失败:";
    }
    //返回学生数量
    return studentCount;


}
//获取某一页多少个学生的数量
QList<StuInfo> stuSql:: getPageStu(quint32 page,quint32 pageNum)
{
    QList<StuInfo> l;
    QSqlQuery sql(m_db);

    QString str=QString ("select * from student order by id limit %1 offset %2")
                      .arg(pageNum)
                      .arg(page*pageNum);
    sql.exec(str);
    StuInfo info;
    while(sql.next())
    {
        info.id=sql.value(0).toUInt();
         info. name=sql.value(1).toString();
         info. age=sql.value(2).toUInt();
          info.grade=sql.value(3).toUInt();
          info.iclass=sql.value(4).toUInt();
           info.studentId=sql.value(5).toUInt();
           info.phone=sql.value(6).toString();
            info.wechat=sql.value(7).toString();
           l.push_back(info);
    }
    return l;
}
//删除学生
  bool stuSql:: deleteStu(int id)
{
      QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1").arg(id));
}
//清空学生
bool stuSql:: clearStu()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from student");
    return sql.exec("delete from sqlite_sequence where name ='student'");
}
//修改学生
 bool stuSql:: upDateStu(StuInfo info)
{
     QSqlQuery sql(m_db);


     QString str=QString("update student set name ='%1' ,age=%2 ,grade=%3 ,"
                           "class=%4, studentid=%5 ,phone='%6', wechat='%7' where id=%8")
                       .arg(info.name)
                       .arg(info.age)
                       .arg(info.grade)
                       .arg(info.iclass)
                       .arg(info.studentId)
                       .arg(info.phone)
                       .arg(info.wechat)
                       .arg(info.id);
     return sql.exec(str);
}


