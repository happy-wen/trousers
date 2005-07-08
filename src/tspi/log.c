
/*
 * Licensed Materials - Property of IBM
 *
 * trousers - An open source TCG Software Stack
 *
 * (C) Copyright International Business Machines Corp. 2004
 *
 */


#include <stdio.h>
#include <string.h>
#include "tsplog.h"

/*
 * LogBlobData()
 *
 *   Log a blob's data to the debugging stream
 *
 * szDescriptor - The APPID tag found in the caller's environment at build time
 * sizeOfBlob - The size of the data to log
 * blob - the data to log
 *
 */

void
LogBlobData(char *szDescriptor, unsigned long sizeOfBlob, unsigned char *blob)
{
	char temp[64];
	int i;

#ifndef TSS_DEBUG
#error Logging data to stdout in non-debugging context!
#endif

	memset(temp, 0, sizeof(temp));

	for (i = 0; (unsigned long)i < sizeOfBlob; i++) {
		if ((i > 0) && ((i % 16) == 0))	{
			fprintf(stdout, "%s\n", temp);
			memset(temp, 0, sizeof(temp));
		}
		snprintf(&temp[(i%16)*3], 4, "%.2X ", blob[i]);
	}
	fprintf(stdout, "%s\n", temp);
}


