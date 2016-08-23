#ifndef DATABASE_H
#define DATABASE_H
#include "basic.h"
#include <QSqlDatabase>
#include <QQueue>
class DataBase
{
private:
    QSqlDatabase m_database;
public:
    bool GetPerson(const int& id,Person &person);
    QQueue<Course> GetCourse(const Course &course);
    bool GetCourse(const int& id, Course &course);
    bool InsertPerson(const Person &person);
    bool InsertCourse(const Course &course);
    bool UpdatePerson(const int& id,const char sha[36]);
    bool UpdatePerson(const Person& person);
    bool UpdateCourse(const int& id,const int& count);
    bool UpdateCourse(const int& id,const DATE& day,const int& time);
    bool DeletePerson(const int &id);
    bool DeleteCourse(const int &id);
    DataBase();
public:
    bool DataBaseValid();
};

#endif // DATABASE_H
