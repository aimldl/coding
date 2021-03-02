
* Rev.2: 2020-04-24 (Fri)
* Rev.1: 2020-01-07 (Tue)
* Draft: 2019-11-19 (Tue)

# Bash Shell Scripting

#### Default value for Command Line Arguments

```bash
variable_string=${1:-"String type default value"}
variable_integer=${2:-1}
variable_float=${3:-0.99}

echo ${variable_string}
echo ${variable_integer}
echo ${variable_float}
```

#### [Bash if elif else Statment](https://tecadmin.net/tutorial/bash-scripting/bash-if-else-statement/)

```bash
if [condition]
then
    //if block code
else
   // else block code
fi
```
Examples
```bash
#!/bin/bash
 read -p "Enter numeric value: " myvar
if [ $myvar -gt 10 ]
then
    echo "Value is greater than 10"
fi
```

#### [Bash – Check If Two Strings are Equal](https://tecadmin.net/tutorial/bash/examples/check-if-two-strings-are-equal/)

If strings are equal, use ==; otherwise, use !=.
```bash
#!/bin/bash
 
str1="Hello Bash"
str2="Hello Bash"
 
if [ "$str1" == "$str2" ]; then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi
```
#### [Bash Shell Find Out If a Variable Is Empty Or Not](https://www.cyberciti.biz/faq/unix-linux-bash-script-check-if-variable-is-empty/)
Lots of ways to find out if a variable is empty or not is explained in the above link.

Example code snippet.
```bash
  DIR_DATASET="~/wav2vec/dataset"
  DIR_SUBTASK=${1}  # e.g. train-clean-100
  DIRECTORY="${DIR_DATASET}/LibriSpeech/${DIR_SUBTASK}"
  TASK=${2}  # e.g. train
  if [ ! -z $TASK ];then  # if not empty
    DIR_TASK="${DIR_DATASET}/LibriSpeech-wav/${TASK}"
  fi
```

There are many other options. Refer to [Bash Shell Find Out If a Variable Is Empty Or Not](https://www.cyberciti.biz/faq/unix-linux-bash-script-check-if-variable-is-empty/). Some excerpts from this document are below.

```bash
if [ -z "$var" ]
then
      echo "\$var is empty"
else
      echo "\$var is NOT empty"
fi
```

```bash
if test -z "$var" 
then
      echo "\$var is empty"
else
      echo "\$var is NOT empty"
fi
```

```bash
[ -z "$var" ] && echo "Empty"
[ -z "$var" ] && echo "Empty" || echo "Not empty"
```

```bash
[[ -z "$var" ]] && echo "Empty"
[[ -z "$var" ]] && echo "Empty" || echo "Not empty"
```

```bash
## Check if $var is set using ! i.e. check if expr is false ##
[ ! -z "$var" ] || echo "Empty"
[ ! -z "$var" ] && echo "Not empty" || echo "Empty"
 
[[ ! -z "$var" ]] || echo "Empty"
[[ ! -z "$var" ]] && echo "Not empty" || echo "Empty"
```

#### [How to Check if a File or Directory Exists in Bash](https://linuxize.com/post/bash-check-if-file-exists/)

##### Check if File Exist

```bash
if test -f "$FILE"; then
    echo "$FILE exist"
else 
    echo "$FILE does not exist"
fi
```

```bash
if [ -f "$FILE" ]; then
    echo "$FILE exist"
else 
    echo "$FILE does not exist"
fi
```

```bash
if [[ -f "$FILE" ]]; then
    echo "$FILE exist"
else 
    echo "$FILE does not exist"
fi
```

##### Check if File does Not Exist 

```bash
if [ ! -f "$FILE" ]; then
    echo "$FILE does not exist"
fi
```

```bash
[ ! -f /etc/docker ] && echo "$FILE does not exist"
```

##### Check if a directory exists

```bash
if [ -d "$DIRECTORY" ]; then
    echo "$DIRECTORY does exist"
fi
```

```bash
[ -d "$DIRECTORY" ] && echo "$DIRECTORY does exist"
```

##### Check if a directory doesn't exist 

```bash
if [ ! -d "$DIRECTORY" ]; then
    echo "$DIRECTORY does not exist"
fi
```

Note space between `"$DIRECTORY"` and `]` is a must. Without it, the following error occurs.

```bash
line n: [: missing `]'
```

The above commands can be used in a function as follows.


```bash
safe_mkdir() {
  # Make a directory if it doesn't exist.
  DIRECTORY=$1
  if [ ! -d "$DIRECTORY" ]; then
    mkdir -p $DIRECTORY
  fi
}
```

Usage
```bash
safe_mkdir '../logs'
```

```bash
safe_cd() {
  DIRECTORY=$1
  if [ ! -d $DIRECTORY ]; then
    mkdir $DIRECTORY
  fi
  run "cd $DIRECTORY"
}
```
Usage
```bash
safe_cd '../downloads'
```


##### Check if Multiple Files Exist 

Instead of using complicated nested if/else constructs you can use `-a` (or `&&` with `[[`) to test if multiple files exist:

```bash
if [ -f /etc/resolv.conf -a -f /etc/hosts ]; then
    echo "Both files exist."
fi
```

```bash
if [[ -f /etc/resolv.conf && -f /etc/hosts ]]; then
    echo "Both files exist."
fi
```

