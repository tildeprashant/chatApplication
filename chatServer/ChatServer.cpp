/*
 * ChatServer.cpp
 *
 *  Created on: 04-Jun-2018
 *      Author: prashant
 */

#include "ChatServer.h"
#include <iostream>
#include <netdb.h>


ChatServer::ChatServer(): 	m_isConnected(false),
							m_serverHostName("localhost"),
							m_serverIP("127.0.0.1"),
							m_serverPort(9080),
							m_serverSocket(0){
	// TODO Auto-generated constructor stub

}

bool ChatServer::initServer() {
	struct sockaddr_in serverAddr, clientAddr;
	hostent *hPtr;
	bool ret=true;

	hPtr = gethostbyname(m_serverIP.c_str());

	std::cout<<"starting socket server..."<<std::endl;

	m_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(m_serverSocket<0){
		std::cerr << "Unable to open the socket";
		ret = false;
	}

	memset(&m_serverAddr, 0, sizeof(sockaddr_in));

	m_serverAddr.sin_family = AF_INET;
	bcopy((char *)hPtr->h_addr,
		      (char *)&m_serverAddr.sin_addr.s_addr,
			  hPtr->h_length);
	m_serverAddr.sin_port = htons(m_serverPort);

	//Avoid bind error if the socket was not close()'d last time;
	//setsockopt(serverSock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

	if(bind(m_serverSocket, (struct sockaddr *) &m_serverAddr, sizeof(sockaddr_in)) < 0){
		std::cerr << "Unable to bind";
		ret = false;
	}

	std::cout<<"socket server started at port: " << m_serverPort << std::endl;

	listen(m_serverSocket, 5);
	return ret;
}

bool ChatServer::isConnected() const {
	return m_isConnected;
}

const std::string& ChatServer::getServerHostName() const {
	return m_serverHostName;
}

const std::string& ChatServer::getServerIp() const {
	return m_serverIP;
}

void ChatServer::acceptConnection() {

	memset(&m_clientAddr, 0, sizeof(sockaddr_in));

	socklen_t cliSize =sizeof(m_clientAddr);
	while(true)
	{
		ConnectionInfo* pClientInfo=new ConnectionInfo;
		pClientInfo->socket = accept(m_serverSocket, (struct sockaddr *) &m_clientAddr, &cliSize);

		if( pClientInfo->socket < 0 ){
		std::cerr<<"error in accepting socket"<<std::endl;
		}
		else{
			//pthread_create
			char buff[256]={0};
			int n;
			n=read(pClientInfo->socket,buff,255);
			if(n<0){
				std::cerr<<"error reading from socket"<<std::endl;
			}
			cout<<"server: "<<buff<<endl;
		}
	}

}

uint16_t ChatServer::getServerPort() const {
	return m_serverPort;
}

ChatServer::~ChatServer() {
	// TODO Auto-generated destructor stub
}

