* Draft: 2021-04-07 (Wed)
# How to Use SQLite3 in Python 3

Reference: [How To Use the sqlite3 Module in Python 3](https://www.digitalocean.com/community/tutorials/how-to-use-the-sqlite3-module-in-python-3), 2020-06-02, DavidMuller

Step 1 — Creating a Connection to a SQLite Database

```bash
(sqlite) $ python
>>> import sqlite3
>>> connection = sqlite3.connect(‘aquarium.db');
>>> print(connection.total_changes)
0
>>> exit()
(sqlite)
```
`connection.total_changes` is the total number of database rows that have been changed by connection. Since we have not executed any SQL commands yet, 0 `total_changes` is correct.

Step 2 — Adding Data to the SQLite Database

```bash
>>> cursor = connection.cursor()
>>> cursor.execute('CREATE TABLE fish (name TEXT, species TEXT, tank_number INTEGER)')
<sqlite3.Cursor object at 0x7f2d74670e30>
>>> cursor.execute("INSERT INTO fish VALUES ('Sammy', 'shark', 1)")
<sqlite3.Cursor object at 0x7f2d74670e30>
>>> cursor.execute("INSERT INTO fish VALUES ('Jamie', 'cuttlefish', 7)")
<sqlite3.Cursor object at 0x7f2d74670e30>
>>> 
```

Step 3 — Reading Data from the SQLite Database

```bash
>>> rows = cursor.execute('SELECT * FROM sharks INNER JOIN endangered on sharks.id=endangered.id;').fetchall()
>>> print(rows)
[(1, 'Sammy', 'Greenland Shark', 427, 272, 1, 'near threatened'), (2, 'Alyoshka', 'Great White Shark', 600, 70, 2, 'not threatened')]
>>> 
```

Notice executing the SQL command is not enough to fetch the SQL output. 

```bash
>>> cursor.execute('SELECT * FROM sharks INNER JOIN endangered on sharks.id=endangered.id;')
<sqlite3.Cursor object at 0x7f99bbdc3e30>
```

```bash
>>> rows = cursor.execute('SELECT name, species, tank_number FROM fish').fetchall()
>>> print(rows)
[('Sammy', 'shark', 1), ('Jamie', 'cuttlefish', 7)]
```

```bash
>>> target_fish_name = 'Jamie'
>>> rows = cursor.execute(
... "SELECT name, species, tank_number FROM fish WHERE name = ?", (target_fish_name,),
... ).fetchall()
>>> print(rows)
[('Jamie', 'cuttlefish', 7)]
>>> 
```

```
Warning: Never use Python string operations to dynamically create a SQL statement string. Using Python string operations to assemble a SQL statement string leaves you vulnerable to SQL injection attacks. SQL injection attacks can be used to steal, alter, or otherwise modify data stored in your database. Always use the ? placeholder in your SQL statements to dynamically substitute values from your Python program. Pass a tuple of values as the second argument to Cursor.execute() to bind your values to the SQL statement. This substitution pattern is demonstrated here and in other parts of this tutorial as well.
```

Step 4 — Modifying Data in the SQLite Database

Let’s say, for example, that Sammy the shark was moved to tank number 2. 
```bash
>>> new_tank_number = 2
>>> moved_fish_name = 'Sammy'
>>> cursor.execute(
... "UPDATE fish SET tank_number = ? WHERE name = ?",
... (new_tank_number, moved_fish_name)
... )
<sqlite3.Cursor object at 0x7f2d74670e30>
>>> rows = cursor.execute("SELECT name, species, tank_number FROM fish").fetchall()
>>> print(rows)
[('Sammy', 'shark', 2), ('Jamie', 'cuttlefish', 7)]
```

Let’s say that Sammy the shark was released into the wild and no longer held by the aquarium.

```bash
>>> released_fish_name = 'Sammy'
>>> cursor.execute(
... "DELETE FROM fish WHERE name = ?",
... (released_fish_name,)
... )
<sqlite3.Cursor object at 0x7f2d74670e30>
>>> rows = cursor.execute("SELECT name, species, tank_number FROM fish").fetchall()
>>> print(rows)
[('Jamie', 'cuttlefish', 7)]
>>> 
```

Step 5 — Using with Statements For Automatic Cleanup
We can use a `with` statement to help us automatically close `Connection` and `Cursor` objects:

```bash
>>> from contextlib import closing
>>> 
>>> with closing(sqlite3.connect('aquarium.db')) as connection:
...   with closing(connection.cursor()) as cursor:
...     rows = cursor.execute('SELECT 1').fetchall()
...     print(rows)
... 
[(1,)]
```

My example to use sqlite3 with Python
```bash
(sqlite) $ python
>>> import sqlite3
>>> connection = sqlite3.connect('sharks.db');
>>> print(connection.total_changes)
0
>>> exit()
(sqlite)
```

```bash
(sqlite) $ python
>>> import sqlite3
>>> connection = sqlite3.connect('sharks.db');
>>> cursor = connection.cursor()
>>> rows = cursor.execute(“SELECT * FROM sharks INNER JOIN endangered on sharks.id=endangered.id;”).fetchall()
>>> print(rows)
[(1, 'Sammy', 'Greenland Shark', 427, 272, 1, 'near threatened'), (2, 'Alyoshka', 'Great White Shark', 600, 70, 2, 'not threatened')]
>>> 
```

Notice executing the SQL command is not enough to fetch the SQL output. 

```bash
>>> cursor.execute('SELECT * FROM sharks INNER JOIN endangered on sharks.id=endangered.id;')
<sqlite3.Cursor object at 0x7f99bbdc3e30>
```


