#include "database.h"
#include <stdlib.h>
#include <QSqlQuery>
#include <QList>
#include <QBitArray>
#include <QVariant>
#define ThrowException {qDebug()<<"Err";}
#define LISTLENGTH 200
DataBase::DataBase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("SelectCourse.db");
    m_database.setUserName("ZeroWeight");
    m_database.setPassword("zw0506");
    m_database.open();
    QStringList tables=m_database.tables();
    bool usr_exist=false;
    bool course_exist=false;
    foreach(QString str,tables)
    {
        if(str=="USR")
            usr_exist=true;
        if(str=="COURSE")
            course_exist=true;
    }
    QSqlQuery query(m_database);
    if(!usr_exist)
        if(!query.exec("CREATE TABLE USR(ID INTEGER PRIMARY KEY, NAME VARCHAR(128),"
                       "SHA VARCHAR(40), ROOT INTEGER, CHOSEN INTEGER,"
                       "GRADE INTEGER,DEPARTMENT INTEGER,"
                       "COURSES VARCHAR(200))"))
            ThrowException
    if(!course_exist)
        if(!query.exec("CREATE TABLE COURSE(ID INTEGER PRIMARY KEY ,NAME VARCHAR(128),"
                       "TEACHER VARCHAR(128),DAY INTEGER,TIME INTEGER,"
                       "MAX INTEGER,SELECTED INTEGER)"))
            ThrowException
}
bool DataBase::DataBaseValid()
{
    return m_database.isOpen()&&m_database.isValid();
}
//select
bool DataBase::GetPerson(const int &id, Person &person)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM USR WHERE ID = :id");
    query.bindValue(":id", id);
    bool res=query.exec();
    if(res){
        query.next();
        QByteArray temp=query.value(1).toByteArray();
        memcpy(person.m_name,temp.data(),SIZE);
        temp=query.value(2).toByteArray();
        memcpy(person.m_sha,temp.data(),36);
        person.m_root=(LEV)query.value(3).toInt();
        person.m_course_chosen=query.value(4).toInt();
        person.m_grade=query.value(5).toInt();
        person.m_department=(DEP)query.value(6).toInt();
        temp=query.value(7).toByteArray();
        sscanf(temp.data(),"%d %d %d %d %d %d %d %d %d %d",
                person.m_courses_id,person.m_courses_id+1,
                person.m_courses_id+2,person.m_courses_id+3,
                person.m_courses_id+4,person.m_courses_id+5,
                person.m_courses_id+6,person.m_courses_id+7,
                person.m_courses_id+8,person.m_courses_id+9);
    }
    return res;
}
QQueue<Course> DataBase::GetCourse(const Course &course)
{
    //multi
    QQueue<Course> pool;
    bool name=(course.m_name[0]!=0);
    bool teacher=(course.m_teacher[0]!=0);
    bool day=(course.m_day!=0);
    bool time=(course.m_time!=0);
    QSqlQuery query(m_database);
    //prepare and bind
    int temp=(name<<3)+(teacher<<2)+(day<<1)+time;
    switch(temp){
    case 0://0000
        ThrowException
        break;
    case 1://0001
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var");
        query.bindValue(":var", course.m_time);
        break;
    case 2://0010
        query.prepare("SELECT * FROM COURSE WHERE DAY = :var");
        query.bindValue(":var", course.m_day);
        break;
    case 3://0011
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND DAY = :var2");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", course.m_day);
        break;
    case 4://0100
        query.prepare("SELECT * FROM COURSE WHERE TEACHER = :var");
        query.bindValue(":var", QString(course.m_teacher));
        break;
    case 5://0101
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND TEACHER = :var2");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", QString(course.m_teacher));
        break;
    case 6://0110
        query.prepare("SELECT * FROM COURSE WHERE DAY = :var1 AND TEACHER = :var2");
        query.bindValue(":var1", course.m_day);
        query.bindValue(":var2", QString(course.m_teacher));
        break;
    case 7://0111
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND DAY = :var2 AND TEACHER = :var3");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", course.m_day);
        query.bindValue(":var3", QString(course.m_teacher));
        break;
    case 8://1000
        query.prepare("SELECT * FROM COURSE WHERE NAME = :var");
        query.bindValue(":var", QString(course.m_name));
        break;
    case 9://1001
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND NAME = :var2");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", QString(course.m_name));
        break;
    case 10://1010
        query.prepare("SELECT * FROM COURSE WHERE DAY = :var1 AND NAME = :var2");
        query.bindValue(":var1", course.m_day);
        query.bindValue(":var2", QString(course.m_name));
        break;
    case 11://1011
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND DAY = :var2 AND NAME = :var3");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", course.m_day);
        query.bindValue(":var3", QString(course.m_name));
        break;
    case 12://1100
        query.prepare("SELECT * FROM COURSE WHERE TEACHER = :var1 AND NAME = :var2");
        query.bindValue(":var1", QString(course.m_teacher));
        query.bindValue(":var2", QString(course.m_name));
        break;
    case 13://1101
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND TEACHER = :var2 AND NAME = :var3");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", QString(course.m_teacher));
        query.bindValue(":var3", QString(course.m_name));
        break;
    case 14://1110
        query.prepare("SELECT * FROM COURSE WHERE DAY = :var1 AND TEACHER = :var2 AND NAME = :var3");
        query.bindValue(":var1", course.m_day);
        query.bindValue(":var2", QString(course.m_teacher));
        query.bindValue(":var3", QString(course.m_name));
        break;
    case 15://1111
        query.prepare("SELECT * FROM COURSE WHERE TIME = :var1 AND DAY = :var2 AND TEACHER = :var3 AND NAME = :var4");
        query.bindValue(":var1", course.m_time);
        query.bindValue(":var2", course.m_day);
        query.bindValue(":var3", QString(course.m_teacher));
        query.bindValue(":var4", QString(course.m_name));
        break;
    }
    //exec
    if(!query.exec())
        return QQueue<Course>();
    else
        while(query.next()){
            Course res;
            res.m_id=query.value(0).toInt();
            res.m_day=(DATE)query.value(3).toInt();
            res.m_time=query.value(4).toInt();
            res.m_max_size=query.value(5).toInt();
            res.m_count=query.value(6).toInt();
            for(int i=0;i<SIZE;i++)
            {
                res.m_name[i]=query.value(1).toByteArray().data()[i];
                res.m_teacher[i]=query.value(2).toByteArray().data()[i];
            }
            pool.enqueue(res);
        }
    return pool;
}
bool DataBase::GetCourse(const int &id,Course &course)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM COURSE WHERE ID = :id");
    query.bindValue(":id", id);
    bool res=query.exec();
    if(res){
        query.next();
        course.m_id=id;
        course.m_day=(DATE)query.value(3).toInt();
        course.m_time=query.value(4).toInt();
        course.m_max_size=query.value(5).toInt();
        course.m_count=query.value(6).toInt();
        memcpy(course.m_name,query.value(1).toByteArray().data(),SIZE);
        memcpy(course.m_teacher,query.value(2).toByteArray().data(),SIZE);
    }
    return res;
}
//insert
bool DataBase::InsertPerson(const Person &person){
     QSqlQuery query(m_database);
     query.prepare("INSERT INTO USR VALUES(:var1,:var2,:var3,:var4,:var5,:var6,:var7,:var8)");
     query.bindValue(":var1",person.m_id);
     query.bindValue(":var2",QString(person.m_name));
     query.bindValue(":var3",QString(person.m_sha));
     query.bindValue(":var4",(int)person.m_root);
     query.bindValue(":var5",0);
     query.bindValue(":var6",person.m_grade);
     query.bindValue(":var7",(int)person.m_department);
     char* temp=new char[LISTLENGTH];
     sprintf(temp,"0 0 0 0 0 0 0 0 0 0");
     query.bindValue(":var8",QString(temp));
     return query.exec();
}
bool DataBase::InsertCourse(const Course &course){
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO COURSE VALUES(:var1,:var2,:var3,:var4,:var5,:var6,:var7)");
    query.bindValue(":var1",course.m_id);
    query.bindValue(":var2",QString(course.m_name));
    query.bindValue(":var3",QString(course.m_teacher));
    query.bindValue(":var4",course.m_day);
    query.bindValue(":var5",course.m_time);
    query.bindValue(":var6",course.m_max_size);
    query.bindValue(":var7",0);
    return query.exec();
}
//update
bool DataBase::UpdatePerson(const int& id,const char sha[36]){
    QSqlQuery query(m_database);
    query.prepare("UPDATE USR SET SHA = :var1 WHERE ID = :var2");
    query.bindValue(":var1",QString(sha));
    query.bindValue(":var2",id);
    return query.exec();
}
bool DataBase::UpdatePerson(const Person &person){
    QSqlQuery query(m_database);
    query.prepare("UPDATE USE SET CHOSEN = :var1 , COURSES = :var2 WHERE ID = :var3");
    query.bindValue(":var1",person.m_course_chosen);
    char* temp=new char[LISTLENGTH];
    sprintf(temp,"%d %d %d %d %d %d %d %d %d %d",
    person.m_courses_id[0],person.m_courses_id[1],
    person.m_courses_id[2],person.m_courses_id[3],
    person.m_courses_id[4],person.m_courses_id[5],
    person.m_courses_id[6],person.m_courses_id[7],
    person.m_courses_id[8],person.m_courses_id[9]);
    query.bindValue(":var2",QString(temp));
    query.bindValue(":var3",person.m_id);
    return query.exec();
}
bool DataBase::UpdateCourse(const int& id,const int& count){
    QSqlQuery query(m_database);
    query.prepare("UPDATE COURSE SET SELETED = :var1 WHERE ID = :var2");
    query.bindValue(":var1",count);
    query.bindValue(":var2",id);
    return query.exec();
}
bool DataBase::UpdateCourse(const int &id, const DATE &day, const int &time){
    QSqlQuery query(m_database);
    query.prepare("UPDATE COURSE SET DAY = :var1,TIME= :var2 WHERE ID = :var3");
    query.bindValue(":var1",day);
    query.bindValue(":var2",time);
    query.bindValue(":var3",id);
    return query.exec();
}
//delete
bool DataBase::DeletePerson(const int &id){
    QSqlQuery query(m_database);
    Person p;
    Course temp;
    if(GetPerson(id,p))
        for(int i=0;i<MAX;i++)
            if(GetCourse(p.m_courses_id[i],temp))
                UpdateCourse(id,--temp.m_count);
    else
        return false;
    query.prepare("DELETE FROM USR WHERE ID = :var");
    query.bindValue(":var", id);
    return query.exec();
}
bool DataBase::DeleteCourse(const int &id){
    QSqlQuery query(m_database);
    query.prepare("DELETE FROM COURSE WHERE ID = :var");
    query.bindValue(":var", id);
    return query.exec();
}
