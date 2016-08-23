#include "client.h"
Client::Client(QTcpSocket* socket){
    m_socket=socket;
    m_user=new Person;
    m_message=new Message;
    m_message->m_mode=NONE;
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(Communicate()));
    connect(m_message,SIGNAL(Reply_2(char*,int)),this,SLOT(Reply_3(char*,int)));
}
void Client::Communicate(){
    m_socket->read(m_message->m_buffer,BUFFERSIZE);
    if(m_message->m_mode)
        GetMessage(*m_message);
    else{
        int temp;
        sscanf(m_message->m_buffer,"%d",&temp);
        m_message->m_mode=(MOD)temp;
        m_socket->write(ACK);
    }
}
void Client::Reply_3(char* buffer,int size){
    m_socket->write(buffer,size);
}
