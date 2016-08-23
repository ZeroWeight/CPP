#ifndef CLIENT_H
#define CLIENT_H
#include "message.hpp"
class Client:public QObject{
    Q_OBJECT
private:
    QTcpSocket* m_socket;
    Person* m_user;
    Message* m_message;
private slots:
    void Communicate();
signals:
    void GetMessage(Message& message);
public:
    Client(QTcpSocket* socket);
public slots:
    void Reply_3(char* buffer,int size);
};
#endif // CLIENT_H
