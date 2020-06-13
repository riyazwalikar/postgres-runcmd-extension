\echo Use "CREATE EXTENSION runcmd" to load this file. \quit

CREATE OR REPLACE FUNCTION pg_runcmd(char)
    RETURNS char
    AS 'MODULE_PATHNAME', 'pg_runcmd'
    LANGUAGE 'c';