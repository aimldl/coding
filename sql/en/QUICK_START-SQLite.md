* Draft: 2021-04-06 (Tue)

# Quick Start Guide for SQLite

## Prerequisite

Refer to [How to Install SQLite on Ubuntu](INSTALL-SQLite.md) to install SQLite.

## How to use SQLite

### Start SQLite

```bash
$ sqlite3 target_database_name.db
sqlite>
```

### Quit SQLite

```sqlite
sqlite> .exit
$
```

Inside `sqlite>` SQL commands must be entered.

## Quick guide to SQL commands

The following is a quick cycle of simple SQL commands. For details, learn SQL commands.

### Create a SQLite Database

```bash
$ sqlite3 sharks.db
  ...
sqlite>
```

### Create a SQLite Table

```sqlite
sqlite> CREATE TABLE sharks(id integer NOT NULL, name text NOT NULL, sharktype text NOT NULL, length integer NOT NULL);
```

### Insert values into the table

```sqlite
sqlite> INSERT INTO tablename VALUES(values go here);
```

For example,

```sqlite
sqlite> INSERT INTO sharks VALUES (1, "Sammy", "Greenland Shark", 427);
sqlite> INSERT INTO sharks VALUES (2, "Alyoshka", "Great White Shark", 600);
sqlite> INSERT INTO sharks VALUES (3, "Himari", "Megaladon", 1800);
```

### Read a table

```sqlite
sqlite> SELECT * FROM sharks;
```

## Next
The following three articles are basics
1. [How to Install SQLite on Amazon EC2](how_to/install_sqlite_on_amazon_ec2.md)
2. [How to Use SQLite3 Quickly](how_to/use_sqlite3_quickly.md)
3. [How to Use SQLite3 in Python 3](how_to/use_sqlite3_in_python3.md)

from
* [How To Install and Use SQLite on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-sqlite-on-ubuntu-20-04)
* [How To Use the sqlite3 Module in Python 3](https://www.digitalocean.com/community/tutorials/how-to-use-the-sqlite3-module-in-python-3), 2020-06-02, DavidMuller\
* [SQLite vs MySQL vs PostgreSQL: A Comparison Of Relational Database Management Systems](https://www.digitalocean.com/community/tutorials/sqlite-vs-mysql-vs-postgresql-a-comparison-of-relational-database-management-systems)
