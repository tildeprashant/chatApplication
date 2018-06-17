/*
 * ConnectionInfo.h
 *
 *  Created on: 04-Jun-2018
 *      Author: prashant
 */

#ifndef CONNECTIONINFO_H_
#define CONNECTIONINFO_H_

#include <stdint.h>


#define MAX_USER_NAME 10

typedef struct _ConnectionInfo
{
	char userName[MAX_USER_NAME];
	uint16_t ipAddress;
	uint32_t socket;
}ConnectionInfo;


#endif /* CONNECTIONINFO_H_ */
