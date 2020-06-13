# Runcmd - A Postgres extension that allows command execution

This is a quick and hackish way of executing commands from within a Postgres database.

## Pre-reqs

You will need the header files, the extension build tools and the database cluster manager which can be setup (on Ubuntu) with

```
sudo apt-get install libpq-dev
sudo apt-get install postgresql-server-dev-all
sudo apt-get install postgresql-common
```

## Compiling and Installation

From the current directory where the code is present run

- `make USE_PGXS=1`
- `sudo make USE_PGXS=1 install` 

Then from within Postgres, run the following to setup the functions

```
CREATE EXTENSION runcmd;
```

## Important note

- This code is not complete. I created this as part of some random poking around Postgres and custom extensions.
- If you know how to get this working, please make a pull request or open an issue!