#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "basic.h"
#define BUFFERSIZE 200
class Message:public QObject{
    Q_OBJECT
public:
    char m_buffer[BUFFERSIZE];
    MOD m_mode;
    Message(){
        m_mode=NONE;
    }
public slots:
    inline void Reply_1(char* buffer,const int& size){
        Reply_2(buffer,size);
    }
signals:
    void Reply_2(char* buffer,const int& size);
};
#endif // MESSAGE_HPP
