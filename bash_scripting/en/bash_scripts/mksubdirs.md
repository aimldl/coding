* Draft: 2021-01-09 (Sat)

# mksubdirs



## 개요

다음 같은 디렉토리 구조가 있을 때,

```bash
CURRENT_DIRECTORY
├── SUB_DIRECTORY_1
├── SUB_DIRECTORY_2
  ...
└── SUB_DIRECTORY_n
```

각 서브 디렉토리에 만들고 싶은 디렉토리 이름이 `new_directory_name`라고 합시다.

`mksubdirs` 명령어를 실행하면

```
$ mksubdirs new_directory_name
```

다음 같이 모든 서브 디렉토리에 원하는 디렉토리가 만들어집니다.

```bash
CURRENT_DIRECTORY
├── SUB_DIRECTORY_1
│   └── new_directory_name
├── SUB_DIRECTORY_2
│   └── new_directory_name
  ...
└── SUB_DIRECTORY_n
    └── new_directory_name
```

## 적용 예

`coding`이라는 디렉토리에 서브 디렉토리가 있습니다.

```bash
coding
├── _conventions
├── _tests
├── bash_scripting
├── c++
├── cuda
├── java
├── matlab
├── python
├── r
└── sql
```

 `coding`의 서브 디렉토리에는 다수의 하위 디렉토리가 있어서 꽤나 복잡한 디렉토리 구조를 가집니다.

모든 서브 디렉토리에 `en`이라는 디렉토리를 만들고 싶습니다. 즉, 

```
coding
├── _conventions
│   └── en
├── _tests
│   ├── en
   ...
├── bash_scripting
   ...
│   ├── en
   ...
├── c++
   ...
│   ├── en
   ...
├── cuda
│   ├── en
   ...
├── java
│   ├── en
   ...
├── matlab
   ...
│   ├── en
   ...
├── python
   ...
│   ├── en
   ...
├── r
│   └── en
└── sql
   ...
    ├── en
   ...
```

다음 명령어를 실행하면 됩니다.

```bash
$ mksubdirs en
```

그 결과는 

```bash
coding
├── _conventions
│   └── en
├── _tests
│   ├── en
│   └── memos
├── bash_scripting
│   ├── bash_scripts
│   ├── basics
│   ├── en
│   ├── how_to
│   └── troubleshoot
├── c++
│   ├── books
│   ├── data_structures_and_algorithms
│   ├── dropbox
│   ├── en
│   ├── exercise
│   ├── libraries
│   ├── old
│   ├── old_source_codes
│   ├── todos
│   ├── topics
│   └── troubleshoot
├── cuda
│   ├── en
│   ├── images
│   ├── old
│   └── troubleshoot
├── java
│   ├── en
│   ├── how_to
│   ├── images
│   ├── install
│   └── troubleshoot
├── matlab
│   ├── archive
│   ├── audio
│   ├── audioLabeler
│   ├── en
│   ├── images
│   ├── machine_learning
│   ├── troubleshoot
│   └── tutorials
├── python
│   ├── _matplotlib
│   ├── _numpy
│   ├── _packages
│   ├── _pandas
│   ├── archive
│   ├── en
│   ├── how_to
│   ├── images
│   └── troubleshoot
├── r
│   └── en
└── sql
    ├── bash_scripts
    ├── downloads
    ├── en
    ├── how_to
    ├── images
    ├── mysql_connector
    ├── practice
    ├── sql_commands
    ├── sqlalchemy
    ├── sqlpad
    └── troubleshoot
```

## 적용예

```bash
$ cd ~/github/tools
$ chmod +x mksubdirs
$ ./mksubdirs en
atom/
audacity/
automl/
dropbox/
ganttproject/
gimp/
git/
gomcam/
google_drive/
icanotes/
jupyter/
master_pdf_editor/
mecab-ipadic-neologd/
meld/
notepad++/
openshot/
oven/
pigeonhole/
projectlibre/
putty/
shotcut/
spyder/
sublime_text/
toggl/
typora/
vlc/
xmind/
zoom/
$
```



## 코드

```bash
#!/bin/bash
# mksubdirs
#   * Draft: 2021-01-09 (Sat)
#
#   make a sub-directory for all (immediate) sub-directories
#   Usage:
#     $ mksubdirs new_directory_name

NEW_DIRECTORY_NAME=$1
CURRENT_DIRECTORY=`pwd`

SUB_DIRECTORIES=`ls -d */`
for SUB_DIRECTORY in $SUB_DIRECTORIES; do
  printf "$SUB_DIRECTORY\n"
  cd $SUB_DIRECTORY
  mkdir -p $NEW_DIRECTORY_NAME
  cd $CURRENT_DIRECTORY
done
```

