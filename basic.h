#ifndef BASIC_H
#define BASIC_H
#include <QObject>
#include <QCoreApplication>
#include <QDebug>
#include <QQueue>
#include <QString>
#define SIZE_C (sizeof(Course))
#define SIZE_P (sizeof(Person))
enum DATE{NON=0,MON,TUE,WED,THU,FRI,SAT,SUN};
enum LEV{USR=0,SU};
enum DEP{DA=0,EE,CS,MA,PH,CH};
const int MAX=10;
const int SIZE=128;
struct Course{
    char m_name[SIZE];
    int m_id;
    char m_teacher[SIZE];
    DATE m_day;
    int m_time;
    int m_max_size;
    int m_count;
};
struct Person{
    int m_id;
    char m_sha[36];
    char m_name[SIZE];
    LEV m_root;
    DEP m_department;
    int m_grade;
    int m_course_chosen;
    int m_courses_id[MAX];
};
typedef Person* PersonPtr;
Q_DECLARE_METATYPE(Person)
Q_DECLARE_METATYPE(Course)
const QString DAY_NAME[]={"","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
const QString DEP_NAME[]={
    "Department of Automation",
    "Electronic Engineering",
    "Computer Science",
    "Mathematica",
    "Physics"
    "Chemistry"
};
#endif // BASIC_H
