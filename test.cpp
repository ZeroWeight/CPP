#include "client.h"
#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "ServerName: " << Client::m_serverName << std::endl;
	std::cout << "ClientNum: " << Client::m_clientNum << std::endl;
	std::cout << std::endl;

	Client::ChangeServerName("host0");

	Client client1;
	client1.ChangeServerName("host1");

	Client *client2 = new Client;
	client2->ChangeServerName("host2");
	delete client2;

	return 0;
}