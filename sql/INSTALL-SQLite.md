

* Draft: 2021-04-06 (Tue)

## How to Install SQLite on Ubuntu

## Overview of SQLite

Google search: how to install sqlite in ubuntu

SQLite

* is a cross-platform database management system
  * which is light yet powerful.

Major differences from other database management system include:

* SQLite does not need to run on a server

* All information is stored in a single file on disk.

SQLite

* is used by many small business systems and applications
  * Mozilla's Firefox browser
  * Google's Chrome browser
  * McAfee's anti-virus software

For details, refer to [How to Use SQLite in Ubuntu](https://smallbusiness.chron.com/use-sqlite-ubuntu-46774.html).

## Install SQLite on Ubuntu (18.04)

Reference: [How To Install and Use SQLite on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-sqlite-on-ubuntu-20-04)

### Install SQLite

```bash
$ sudo apt update
$ sudo apt install -y sqlite3
```

### Verify the installation

```bash
$ sqlite --version
```

### Start SQLite

```bash
$ sqlite3 target_database_name.db
sqlite>
```

### Exit SQLite

```sqlite
sqlite> .exit
$
```

## How to Use SQLite

Refer to [Quick Start Guide for SQLite](QUICK_START-SQLite.md). 