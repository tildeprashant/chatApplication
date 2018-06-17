#include "chatClient.h"
#include <string.h>
#include<iostream>
#include<cstdlib>
#include <arpa/inet.h>
#include<errno.h>

using namespace std;
/*
 * chatClient.cpp
 *
 *  Created on: 17-Jun-2018
 *      Author: prashant
 */

chatClient::chatClient() {

	bzero(&m_remoteSocketInfo,sizeof(sockaddr_in));
	m_serverPort=9080;
	m_socketHandle=0;
	m_pRemoteHost = "localhost";

}

void chatClient::init() {

	hostent *hPtr;
	hPtr = gethostbyname(m_pRemoteHost);

	if (hPtr == NULL){
	  cerr<<"ERROR, no such host"<<endl;
	  exit(0);
	}

	if((m_socketHandle = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		close(m_socketHandle);
		exit(EXIT_FAILURE);
	}

	m_remoteSocketInfo.sin_family = AF_INET;
	bcopy((char *)hPtr->h_addr, (char *)&m_remoteSocketInfo.sin_addr.s_addr, hPtr->h_length);

	m_remoteSocketInfo.sin_port = htons(m_serverPort);

	cout<<"client:"<<inet_ntoa(m_remoteSocketInfo.sin_addr)<<endl;

	if ( connect(m_socketHandle,(sockaddr *)&m_remoteSocketInfo,sizeof(m_remoteSocketInfo)) ){
		cerr<<"ERROR connecting: "<<errno<<endl;
	}
}

void chatClient::sendMessage(string msg) {
	char buffer[256];
	int n;
	bzero(buffer,256);
	strncpy(buffer,msg.c_str(),255);

	n = write(m_socketHandle,buffer,strlen(buffer));
	if (n < 0){
	cerr<<"ERROR writing to socket"<<endl;
	}

	bzero(buffer,256);
	n = read(m_socketHandle,buffer,255);
	if (n < 0){
		cerr<<"ERROR reading from socket"<<endl;
	}
	cout<<buffer<<endl;

}

chatClient::~chatClient() {
}




