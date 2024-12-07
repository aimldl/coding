* Draft: 2021-04-14 (Wed)

# Papers

To create this table, [How to Create a Database and Tables](../how_to/create_database_and_tables.md) is referenced.

### Example2

#### `link2paper` table

```sql
CREATE TABLE link2paper (
  id INT NOT NULL AUTO_INCREMENT,
  created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  url2pdf varchar(1023) NOT NULL,
  url2abstract varchar(1023),
  description varchar(1023),
  author_list_id INT NOT NULL,
  PRIMARY KEY(id)
);
```

```mysql
mysql> CREATE TABLE link2paper (
    ->   id INT NOT NULL AUTO_INCREMENT,
    ->   url2pdf varchar(1023) NOT NULL,
    ->   url2abstract varchar(1023),
    ->   description varchar(1023),
    ->   author_list_id INT NOT NULL,
    ->   PRIMARY KEY(id)
    -> );
Query OK, 0 rows affected (0.01 sec)

mysql> 
```

[SQL ALTER TABLE Statement](https://www.w3schools.com/sql/sql_alter.asp)

```sql
ALTER TABLE link2paper
ADD created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP;
```

```sql
mysql> ALTER TABLE link2paper
    -> ADD created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP;
Query OK, 0 rows affected (0.03 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> 
```

#### `authors` table

```sql
CREATE TABLE authors(
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  email VARCHAR(255),
  link2homepage VARCHAR(1023),
  link2blog VARCHAR(1023),
  PRIMARY KEY (id),
  UNIQUE KEY email (email)
);
```

Add another column

```sql
ALTER TABLE authors
ADD created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP;
```

```mysql
mysql> CREATE TABLE authors(
    ->   id INT NOT NULL AUTO_INCREMENT,
    ->   name VARCHAR(255) NOT NULL,
    ->   email VARCHAR(255),
    ->   link2homepage VARCHAR(1023),
    ->   link2blog VARCHAR(1023),
    ->   PRIMARY KEY (id),
    ->   UNIQUE KEY email (email)
    -> );
Query OK, 0 rows affected (0.04 sec)

mysql>
mysql> ALTER TABLE authors
    -> ADD created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP;
Query OK, 0 rows affected (0.02 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> 
```

Insert a paper link. For the command, refer to [SQL INSERT INTO Statement](https://www.w3schools.com/sql/sql_insert.asp).

```sql
mysql> INSERT INTO link2paper (url2pdf, description, author_list_id) VALUES('https://static.googleusercontent.com/media/research.google.com/ja//pubs/archive/bcb15507f4b52991a0783013df4222240e942381.pdf', 'This paper is introduced in Kubeflow for Machine Learning. Katib is based on this work or Google Vizier', 1 );
Query OK, 1 row affected (0.00 sec)

mysql> 
mysql> SELECT * FROM link2paper;
+----+------------------------------------------------------------------------------------------------------------------------------+--------------+---------------------------------------------------------------------------------------------------------+----------------+---------------------+
| id | url2pdf                                                                                                                      | url2abstract | description                                                                                             | author_list_id | created_at          |
+----+------------------------------------------------------------------------------------------------------------------------------+--------------+---------------------------------------------------------------------------------------------------------+----------------+---------------------+
|  1 | https://static.googleusercontent.com/media/research.google.com/ja//pubs/archive/bcb15507f4b52991a0783013df4222240e942381.pdf | NULL         | This paper is introduced in Kubeflow for Machine Learning. Katib is based on this work or Google Vizier |              1 | 2021-04-14 01:59:54 |
+----+------------------------------------------------------------------------------------------------------------------------------+--------------+---------------------------------------------------------------------------------------------------------+----------------+---------------------+
1 row in set (0.00 sec)

mysql> 


```





#### TODO:

#### `tweets` table

```mysql
mysql> CREATE TABLE tweets(
    -> id INT NOT NULL AUTO_INCREMENT,
    -> user_id INT NOT NULL,
    -> tweet VARCHAR(300) NOT NULL,
    -> created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    -> PRIMARY KEY (id),
    -> CONSTRAINT tweets_user_id_fkey FOREIGN KEY (user_id) REFERENCES users(id)
    -> );
Query OK, 0 rows affected (0.06 sec)

mysql> 
```

#### Check the created tables

```mysql
mysql> SHOW TABLES;
+-------------------+
| Tables_in_miniter |
+-------------------+
| tweets            |
| users             |
| users_follow_list |
+-------------------+
3 rows in set (0.00 sec)

mysql> 
```

For details about each table, run the `EXPLAIN table_name` command.

```mysql
mysql> EXPLAIN users;
+-----------------+---------------+------+-----+-------------------+-----------------------------+
| Field           | Type          | Null | Key | Default           | Extra                       |
+-----------------+---------------+------+-----+-------------------+-----------------------------+
| id              | int(11)       | NO   | PRI | NULL              | auto_increment              |
| name            | varchar(255)  | NO   |     | NULL              |                             |
| email           | varchar(255)  | NO   | UNI | NULL              |                             |
| hashed_password | varchar(255)  | NO   |     | NULL              |                             |
| profile         | varchar(2000) | NO   |     | NULL              |                             |
| created_at      | timestamp     | NO   |     | CURRENT_TIMESTAMP |                             |
| updated_at      | timestamp     | YES  |     | NULL              | on update CURRENT_TIMESTAMP |
+-----------------+---------------+------+-----+-------------------+-----------------------------+
7 rows in set (0.00 sec)

mysql> 
```

```mysql
mysql> EXPLAIN users_follow_list;
+----------------+-----------+------+-----+-------------------+-------+
| Field          | Type      | Null | Key | Default           | Extra |
+----------------+-----------+------+-----+-------------------+-------+
| user_id        | int(11)   | NO   | PRI | NULL              |       |
| follow_user_id | int(11)   | NO   | PRI | NULL              |       |
| created_at     | timestamp | NO   |     | CURRENT_TIMESTAMP |       |
+----------------+-----------+------+-----+-------------------+-------+
3 rows in set (0.00 sec)

mysql> 
```

```mysql
mysql> EXPLAIN tweets;
+------------+--------------+------+-----+-------------------+----------------+
| Field      | Type         | Null | Key | Default           | Extra          |
+------------+--------------+------+-----+-------------------+----------------+
| id         | int(11)      | NO   | PRI | NULL              | auto_increment |
| user_id    | int(11)      | NO   | MUL | NULL              |                |
| tweet      | varchar(300) | NO   |     | NULL              |                |
| created_at | timestamp    | NO   |     | CURRENT_TIMESTAMP |                |
+------------+--------------+------+-----+-------------------+----------------+
4 rows in set (0.00 sec)

mysql> 
```

## 