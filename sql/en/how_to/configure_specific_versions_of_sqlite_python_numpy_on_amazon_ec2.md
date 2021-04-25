* Draft: 2021-04-07 (Wed)

# How to Configure Specific Versions of SQLite on Amazon EC2
In this document, the target is to install SQLite, but Python and Numpy are also installed as a bonus.

## Target versions
Say the target is to set up an environment with the following versions:
- Python 3.6.5
- sqlite 3.28
- numpy 1.13.3

## The commands to install the target versions

Step 1. Access an Amazon EC2 instance
```bash
aimldl@localmachine:~$ ./ssh-sqlite-python-numpy-t3a_2xlarge-ec2_seoul
  ...
ubuntu@ip-123-45-67-890:~$
```
For simplicity, the prompt `ubuntu@ip-123-45-67-890:~$` will be abbreviated to `$`.

Step 2. Download and install Anaconda
As of today, the most recent version of Anaconda is `Anaconda3-2020.11-Linux-x86_64.sh`.

```bash
$ wget https://repo.anaconda.com/archive/Anaconda3-2020.11-Linux-x86_64.sh
$ bash Anaconda3-2020.11-Linux-x86_64.sh
  ...
(base) $
```

Step 3. Create a Conda virtual environment
* In this example, the name of the virtual environment is `sqlite`.
* Note the Python version is specified.
```bash
(base) $ conda create -n sqlite python=3.6.5
(base) $ conda activate sqlite
(sqlite) $
```

Step 4. Install SQLite and Numpy with specific versions
```bash
(sqlite) $ conda install sqlite=3.28
(sqlite) $ conda install numpy=1.13.3
```

Step 5. Verify the installation
```bash
(sqlite) $ python --version
Python 3.6.5 :: Anaconda, Inc.
(sqlite) $ python -c 'import numpy; print(numpy.__version__)'
1.13.3
(sqlite) $ sqlite3 --version
3.28.0 2019-04-16 19:49:53 884b4b7e502b4e991677b53971277adfaf0a04a284f8e483e2553d0f83156b50
(sqlite) $ which sqlite3
/home/ubuntu/anaconda3/envs/sqlite/bin/sqlite3
(sqlite)$
```

## Run SQLite
```bash
(sqlite) $ sqlite3
SQLite version 3.28.0 2019-04-16 19:49:53
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
sqlite> .quit
(sqlite) $
```

### FAQs
#### Q: How can I add the sqlite3 module to Python?
A: You don't need to install sqlite3 module. It is included in the standard library (since Python 2.5).

#### Q: Difference between [sqlite] and [sqlite3] tags
A: Hans Passant Jun 8 '16 at 10:48
Sqlite has been on version 3 for the past 12 years. It is not useful, a synonym is appropriate. 

@HansPassant So in your line of reasoning sqlite3 should be a synonym of sqlite, right? 
– rene Jun 8 '16 at 10:57

@roaima yes, that is what is hard with version specific tags.
