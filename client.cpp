#include "client.h"
#include <iostream>

std::string Client::m_serverName = "defaultServerName";
int Client::m_clientNum = 0;

Client::Client(void)
{
	std::cout << "Calling default constructor ..." << std::endl;

	++m_clientNum;
	std::cout << "ServerName: " << m_serverName << std::endl;
	std::cout << "ClientNum: " << m_clientNum << std::endl;
	std::cout << std::endl;
}

Client::~Client(void)
{
	std::cout << "Calling destructor ..." << std::endl;

	--m_clientNum;
	std::cout << "ServerName: " << m_serverName << std::endl;
	std::cout << "ClientNum: " << m_clientNum << std::endl;
	std::cout << std::endl;
}

void Client::ChangeServerName(const std::string &newServerName)
{
	m_serverName = newServerName;
	std::cout << "NewServerName: " << m_serverName << std::endl;
	std::cout << std::endl;
}