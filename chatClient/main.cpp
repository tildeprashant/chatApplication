/*
 * main.cpp
 *
 *  Created on: 17-Jun-2018
 *      Author: prashant
 */

#include"chatClient.h"

int main()
{
	chatClient client;
	client.init();
	client.sendMessage("hello, how are you");
}


