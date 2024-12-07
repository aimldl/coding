* Draft: 2021-04-07 (Wed)

# How to Use SQLite3 Quickly

The commands are equivalent up to “Step 6 — Deleting Information in SQLite”. 
After this part, the commands are slightly modified.

Step 2 — Creating a SQLite Database

```sqlite
sqlite> CREATE TABLE sharks(id integer NOT NULL, name text NOT NULL, sharktype text NOT NULL, length integer NOT NULL);
 
Inserting Values into Tables
sqlite> INSERT INTO sharks VALUES (1, 'Sammy', 'Greenland Shark', 427);
sqlite> INSERT INTO sharks VALUES (2, 'Alyoshka', 'Great White Shark', 600);
sqlite> INSERT INTO sharks VALUES (3, 'Himari', 'Megaladon', 1800);
 
Errors
sqlite> DESC sharks;
Error: near "DESC": syntax error
sqlite> INSERT INTO sharks VALUES (4, 'Faiza', 'Hammerhead Shark');
Error: table sharks has 4 columns but 3 values were supplied
```
 
Step 4 — Reading Tables in SQLite

```sqlite
sqlite> SELECT * FROM sharks;
1|Sammy|Greenland Shark|427
2|Alyoshka|Great White Shark|600
3|Himari|Megaladon|1800
sqlite> 

sqlite> SELECT * FROM sharks WHERE id IS 1;
1|Sammy|Greenland Shark|427
sqlite> SELECT * FROM sharks WHERE id=1;
1|Sammy|Greenland Shark|427
sqlite> SELECT * FROM sharks WHERE id==1;
1|Sammy|Greenland Shark|427
sqlite>
```

Step 5 — Updating Tables in SQLite

Adding Columns to SQLite Tables

```sqlite
sqlite> ALTER TABLE sharks ADD COLUMN age integer;
sqlite> SELECT * FROM sharks;
1|Sammy|Greenland Shark|427|
2|Alyoshka|Great White Shark|600|
3|Himari|Megaladon|1800|
sqlite> 
```

Updating Values in SQLite Tables

```sqlite
sqlite> UPDATE sharks SET age = 272 WHERE id = 1;
sqlite> UPDATE sharks SET age = 70 WHERE id = 2;
sqlite> UPDATE sharks SET age = 40 WHERE id = 3;
sqlite> SELECT * FROM sharks;
1|Sammy|Greenland Shark|427|272
2|Alyoshka|Great White Shark|600|70
3|Himari|Megaladon|1800|40
sqlite> 
```

Step 6 — Deleting Information in SQLite

```sqlite
sqlite> DELETE FROM sharks WHERE age <= 200;
sqlite> SELECT * FROM sharks;
1|Sammy|Greenland Shark|427|272
sqlite> 
```

Retrieve the sharks table.

```sqlite
sqlite> INSERT INTO sharks VALUES (2, 'Alyoshka', 'Great White Shark', 600, 70);
sqlite> INSERT INTO sharks VALUES (3, 'Himari', 'Megaladon', 1800, 40);
sqlite> SELECT * FROM sharks;
1|Sammy|Greenland Shark|427|272
2|Alyoshka|Great White Shark|600|70
3|Himari|Megaladon|1800|40
sqlite> 
```

Step 7 — Joining Information in SQLite

If you wanted to query data from two tables, you could use one of SQLite’s four join commands:

```sqlite
INNER JOIN
OUTER JOIN
LEFT JOIN
CROSS JOIN
```

Let’s create that second table “endangered”.

```sqlite
sqlite> CREATE TABLE endangered (id integer NOT NULL, status text NOT NULL);
sqlite> INSERT INTO endangered VALUES (1, 'near threatened');
sqlite> SELECT * FROM endangered;
1|near threatened
sqlite> 
```
INNER JOIN

```sqlite
sqlite> SELECT * FROM sharks INNER JOIN endangered;
1|Sammy|Greenland Shark|427|272|1|near threatened
1|Sammy|Greenland Shark|427|272|2|not threatened
2|Alyoshka|Great White Shark|600|70|1|near threatened
2|Alyoshka|Great White Shark|600|70|2|not threatened
3|Himari|Megaladon|1800|40|1|near threatened
3|Himari|Megaladon|1800|40|2|not threatened
sqlite> 

sqlite> SELECT * FROM sharks INNER JOIN endangered on sharks.id=endangered.id;
1|Sammy|Greenland Shark|427|272|1|near threatened
2|Alyoshka|Great White Shark|600|70|2|not threatened
sqlite> 
```

Note the second ID is repetitive. So let’s get rid of it.

```sqlite
sqlite> SELECT sharks.id, sharks.name, sharks.sharktype, sharks.length, sharks.age, endangered. status FROM sharks INNER JOIN endangered on sharks.id=endangered.id;
1|Sammy|Greenland Shark|427|272|near threatened
2|Alyoshka|Great White Shark|600|70|not threatened
sqlite> 
```

```sqlite
sqlite> .exit
(sqlite) $
```
