#include "ChatServer.h"

/*
 * main.cpp
 *
 *  Created on: 17-Jun-2018
 *      Author: prashant
 */




int main()
{
	ChatServer server;
	server.initServer();
	server.acceptConnection();
}
