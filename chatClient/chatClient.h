/*
 * chatClient.h
 *
 *  Created on: 17-Jun-2018
 *      Author: prashant
 */

#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>

using namespace std;

class chatClient
{
	sockaddr_in m_remoteSocketInfo;

	uint32_t m_socketHandle;
	char *m_pRemoteHost;
	uint16_t m_serverPort;
public:
	chatClient();
	void sendMessage(string msg);
	~chatClient();
	void init();

};




#endif /* CHATCLIENT_H_ */
