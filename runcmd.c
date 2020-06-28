/*
Riyaz Walikar
https://ibreak.software
*/

#include <stdlib.h>
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

    char *command = PG_GETARG_TEXT_P(0);
    int cmdlen = VARSIZE(command) - VARHDRSZ;
    char *c = (char *) palloc(cmdlen + 1);
    int32 retval = 0;
    memcpy(c, VARDATA(command), cmdlen);

    c[cmdlen]='\0';

    retval = system(c);

    pfree(c);
    PG_RETURN_INT32(retval);
}