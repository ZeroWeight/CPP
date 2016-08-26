#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
public:
	Client(void);
	~Client(void);
	static void ChangeServerName(const std::string &newServerName);

	static std::string m_serverName;
	static int m_clientNum;
};

#endif // CLIENT_H