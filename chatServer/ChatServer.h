/*
 * ChatServer.h
 *
 *  Created on: 04-Jun-2018
 *      Author: prashant
 */


#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#include<string>
#include<list>
#include "ConnectionInfo.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class ChatServer {
	bool m_isConnected;
	uint16_t m_serverPort;
	int m_serverSocket;
	struct sockaddr_in m_serverAddr;
	struct sockaddr_in m_clientAddr;
	std::list<ConnectionInfo> m_clientList;
	std::string m_serverIP;
	std::string m_serverHostName;

public:
	ChatServer();
	~ChatServer();
	bool isConnected() const;
	const std::string& getServerHostName() const;
	const std::string& getServerIp() const;
	bool initServer();
	void acceptConnection();
	uint16_t getServerPort() const;
};

#endif /* CHATSERVER_H_ */
