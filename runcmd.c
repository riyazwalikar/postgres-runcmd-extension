/*
Riyaz Walikar
https://ibreak.software
*/

#include "postgres.h"
#include "fmgr.h"
#include <utils/builtins.h>


#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 128

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

void _PG_init(void);
void _PG_fini(void);

Datum pg_runcmd(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(pg_runcmd);


void _PG_init(void)
{
}

void _PG_fini(void)
{
}


Datum pg_runcmd(PG_FUNCTION_ARGS)
{

    char buf[BUFSIZE];
    char *command = TextDatumGetCString() //figure out how to pass command here?
    FILE *fp;

    if ((fp = popen(command, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        //printf("%s", buf);
    }

    if(pclose(fp))  {
        printf("Command not found or exited with error status\n");
        return -1;
    }

	return buf;
}