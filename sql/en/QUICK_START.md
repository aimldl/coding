* Draft: 2021-04-05 (Mon)

# Quick Start Guide

## Summary

Run MySQL

```bash
$ sudo mysql -uroot -p
Enter password:
```

and enter some basic SQL commands to test MySQL.

```sql
mysql> show databases;
mysql> use sample;
```



## Install a sample database

`bash_scripts/fetch_and_import_sample_database`

```bash
mkdir -p downloads
cd downloads/
wget https://download.hanbit.co.kr/exam/2231/source.zip
unzip source.zip
sudo mysql -uroot -p < sample.dump
# You must enter the password
```

## Run MySQL

```bash
$ sudo mysql -uroot -p
Enter password:
```

If the correct password is entered, the following message will be shown.

```bash
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 9
Server version: 5.7.33-0ubuntu0.18.04.1 (Ubuntu)

Copyright (c) 2000, 2021, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql>
```

Without the leading `sudo` command, the following error will occur even with the correct password.

```bash
$ mysql -uroot -p
Enter password: 
ERROR 1698 (28000): Access denied for user 'root'@'localhost'
$
```

## Check the existing databases

```bash
mysql> show databases;
```

```bash
+--------------------+
| Database           |
+--------------------+
  ...
| sample             |
  ...
+--------------------+
5 rows in set (0.01 sec)

mysql>
```

### Use a database

```sql
mysql> use sample;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> 
```

Note: the `SELECT` command will fail without running the `use` command.

```sql
mysql> SELECT * FROM sample21;
ERROR 1046 (3D000): No database selected
mysql> SELECT * FROM sample;
ERROR 1046 (3D000): No database selected
mysql>
```

### First SELECT command

```bash
mysql> SELECT * FROM sample21;
+------+-----------+------------+---------------------------+
| no   | name      | birthday   | address                   |
+------+-----------+------------+---------------------------+
|    1 | 박준용    | 1976-10-18 | 대구광역시 수성구         |
|    2 | 김재진    | NULL       | 대구광역시 동구           |
|    3 | 홍길동    | NULL       | 서울특별시 마포구         |
+------+-----------+------------+---------------------------+
3 rows in set (0.00 sec)

mysql> DESC sample21;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| no       | int(11)     | YES  |     | NULL    |       |
| name     | varchar(20) | YES  |     | NULL    |       |
| birthday | date        | YES  |     | NULL    |       |
| address  | varchar(40) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)
```



