#include <QCoreApplication>
#include "database.h"
#include <string.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    DataBase db;
    Person p;
    p.m_department=DA;
    p.m_grade=2015;
    p.m_id=2015011492;
    strcpy(p.m_name,"ZhangT");
    strcpy(p.m_sha,"26262266");
    p.m_root=SU;
    db.InsertPerson(p);
    Person q;
    db.GetPerson(2015011493,q);
    return a.exec();
}
