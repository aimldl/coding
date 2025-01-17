* Rev.2: 2020-08-07 (Fri)
* Rev.1: 2020-08-06 (Thu)
* Rev.1: 2020-05-21 (Thu)
* Draft: 2020-03-25 (Wed)

# How to Install Oracle JDK on Ubuntu Linux 18.04
## Purpose
* XMind 8 Pro fails to launch. To make this program work, Ubuntu's default OpenJDK is removed and Oracle JDK is installed.
* H2O.ai's open-source AutoML requires Java. I prefer Oracle JDK.

## Prerequisite
As of 2020-08-07 (Fri), the standard installation of Ubuntu 18.04 does not install the default Java Runtime Environment or Open JRE which used to install by default.
### Check the existing Open JRE or JDK

```bash
$ java

Command 'java' not found, but can be installed with:

sudo apt install default-jre            
sudo apt install openjdk-11-jre-headless
sudo apt install openjdk-8-jre-headless
Install Oracle JDK on Ubuntu 18.04 directly from the Oracle website
$
```

### Check the preinstalled JRE version
If your Ubuntu 18.04 has an existing Open JRE, remove the JRE from the machine. You can check the preinstalled Java version as follows.
```bash
$ java -version
java version "12.0.2" 2019-07-16
Java(TM) SE Runtime Environment (build 12.0.2+10)
Java HotSpot(TM) 64-Bit Server VM (build 12.0.2+10, mixed mode, sharing)
$
```
or
```bash
$ sudo dpkg --list | grep -i jdk
ii  oracle-java14-installer                    14.0.2-1~linuxuprising1                          amd64        Oracle Java(TM) Development Kit (JDK) 14
ii  oracle-java14-set-default                  14.0.2-1~linuxuprising1                          amd64        Set Oracle JDK 14 as default Java
$
```

### Remove the existing OpenJRE
[TODO: add the command]


### Check the preinstalled JDK version
```bash
$ javac --version
```
The standard installation of Ubuntu 18.04 does not come with Open JDK.
```bash
$ javac --version
Command 'javac' not found, but can be installed with:

sudo apt install default-jdk            
sudo apt install openjdk-11-jdk-headless
sudo apt install ecj                    
sudo apt install openjdk-8-jdk-headless 
$
```

### Remove the existing OpenJDK
* Google search: ubuntu linux 18.04  How to remove OpenJDK and install Oracle JDK

```bash
$ sudo apt-get purge openjdk*
```
or
```bash
$ sudo apt-get purge openjdk-\*
```
and then run:
```bash
$ sudo apt autoremove
```

For other related commands, refer to [How to remove openjdk-8-jdk from Ubuntu 16.04 (Xenial Xerus)](https://www.howtoinstall.co/en/ubuntu/xenial/openjdk-8-jdk?action=remove).

## Installation
Before going further, ensure to remove the existing JRE/JDK because the version conflict is tricky to deal with. The installation options are two-fold:
* Option 1: installation with apt
* Option 2: installation from a Java repository
* Option 3: manual installation

Option 1 & 2 are easier, but the installation fails as the 3rd party repository stopped to support many Java versions.

### Option 1: installation with apt

```bash
$ sudo apt search oracle-java
정렬중... 완료
전체 텍스트 검색... 완료
oracle-java11-installer-local/bionic,now 11.0.8-1~linuxuprising0 amd64 [설치됨]
  Oracle Java(TM) Development Kit (JDK) 11

oracle-java11-set-default-local/bionic 11.0.8-1~linuxuprising0 amd64
  Set Oracle JDK 11 as default Java

oracle-java14-installer/bionic 14.0.2-1~linuxuprising1 amd64
  Oracle Java(TM) Development Kit (JDK) 14

oracle-java14-set-default/bionic 14.0.2-1~linuxuprising1 amd64
  Set Oracle JDK 14 as default Java
$
```

### Option 2: installation from a Java repository
This option used to work nicely and many tutorials on the web assumes to add the 3rd party Java repository.
A repo `linuxuprising/java` used to work, but it does not work any more. This means many installation tutorials on web is no longer valid.

Anyways, there are three steps to install Java from a 3rd party repository.
* Step 1: Add the Java repository
* Step 2: Update apt
* Step 3: Install Official JDK

In step 1, different versions have different Java repository. In step 3, the command varies with the different version. For example,
* version 11: `oracle-java11-installer-local`

  ...
  
* version 14: `oracle-java14-installer-local`

### ppa:linuxuprising/java
This 3rd party repository says to support Java 11 and 14 installer. But Java 11 fails. For details, refer to `Install Java 11`.
```bash
$ sudo add-apt-repository ppa:linuxuprising/java
 Oracle Java 11 (LTS) and 14 installer for Ubuntu (20.04, 19.10, 18.04, 16.04 and 14.04), Linux Mint and Debian.
  ...
 About Oracle Java 10, 12 and 13: These versions have reached the end of public updates, therefore they are longer available for download.
  ...
$
```
Even thought the above command fails, it is left here for the future reference.

#### Install Java 14
```bash
$ sudo add-apt-repository ppa:linuxuprising/java
$ sudo apt update
$ sudo apt install oracle-java14-installer-local
```
For details, refer to [How To Install Oracle Java 14 (JDK 14) On Ubuntu, Debian Or Linux Mint From APT PPA Repository](https://www.linuxuprising.com/2020/03/how-to-install-oracle-java-14-jdk14-on.html).

#### Install Java 11
```bash
$ sudo add-apt-repository ppa:linuxuprising/java
$ sudo apt update
$ sudo apt install oracle-java11-installer-local
```
Notice the last command is not `sudo apt install oracle-java11-installer` which is given in many Java installation tutorials.

For details, refer to [New Oracle Java 11 Installer For Ubuntu, Debian Or Linux Mint (Using Local Oracle Java .tar.gz)](https://www.linuxuprising.com/2019/06/new-oracle-java-11-installer-for-ubuntu.html).

As of 2020-08-07 (Fri), the installation command fails to work. 
```bash
$ sudo apt install oracle-java11-installer-local
  ...
E.g.:
sudo mkdir -p /var/cache/oracle-jdk11-installer-local
sudo cp jdk-11.0.4_linux-x64_bin.tar.gz /var/cache/oracle-jdk11-installer-local/
sha256sum mismatch jdk-11.0.8_linux-x64_bin.tar.gz
Oracle JDK 11 is NOT installed.
dpkg: error processing package oracle-java11-installer-local (--configure):
 installed oracle-java11-installer-local package post-installation script subprocess returned error exit status 1
E: Sub-process /usr/bin/dpkg returned an error code (1)
$
```
Well, this command is executed right after the fresh Ubuntu installation. Something must be wrong with the repository.

### Option 3: manual installation
#### Step 1. Download Oracle JDK directly from Oracle website.
Download "Linux Debian Package" from
* [Java SE Development Kit 14 Downloads](https://www.oracle.com/java/technologies/javase-jdk14-downloads.html)
* [Java SE Development Kit 13 Downloads](https://www.oracle.com/java/technologies/javase-jdk13-downloads.html)
  ...
* [Java SE Development Kit 8 Downloads](https://www.oracle.com/java/technologies/javase-jdk8-downloads.html) (An example of an older link)


### Install the .deb File
[jdk-14_linux-x64_bin.deb](https://www.oracle.com/java/technologies/javase-jdk14-downloads.html#license-lightbox). 
```bash
$ sudo dpkg -i jdk-14_linux-x64_bin.deb 
  ...
Selecting previously unselected package jdk-14.
(데이터베이스 읽는중 ...현재 217860개의 파일과 디렉터리가 설치되어 있습니다.)
Preparing to unpack jdk-14_linux-x64_bin.deb ...
Unpacking jdk-14 (14-1) ...
Configuring jdk-14 (14-1) ...
$
```

## Archive

2020-05-21 (Thu)

The above method failed. So I've followed.

Google search: how to install java in ubuntu 18.04 docker container

* [How To Install Java On Ubuntu 18.04](https://phoenixnap.com/kb/how-to-install-java-ubuntu)

* The following link looks useful to install java inside a Docker container.
  * [Docker: install Java8 automatically on ubuntu/debian](https://newfivefour.com/docker-java8-auto-install.html)

### Remove the unwanted existing Oracle Java version
Say my target jar file fails to run with the following error
```bash
$ java -jar h2o.jar 
Only Java 8, 9, 10, 11, 12 and 13 are supported, system version is 14.0.2
$
```
while my current java is version 14.
```bash
$ java --version
java 14.0.2 2020-07-14
Java(TM) SE Runtime Environment (build 14.0.2+12-46)
Java HotSpot(TM) 64-Bit Server VM (build 14.0.2+12-46, mixed mode, sharing)
$
```
Let's remove the unsupported version of 14.

First, check the current version
```bash
$ sudo dpkg --list | grep -i jdk
ii  oracle-java14-installer                    14.0.2-1~linuxuprising1                          amd64        Oracle Java(TM) Development Kit (JDK) 14
ii  oracle-java14-set-default                  14.0.2-1~linuxuprising1                          amd64        Set Oracle JDK 14 as default Java
$
```
and uninstall 
```bash
$ sudo apt-get purge oracle-java14-installer
  ...
$ sudo apt-get autoremove
  ...
$
```
To double-check,nothing is left in the machine.
```bash
$ sudo dpkg --list | grep -i jdk
$
```
For details, refer to [How to uninstall Oracle JDK in Ubuntu 16.04 LTS [duplicate]](https://askubuntu.com/questions/850729/how-to-uninstall-oracle-jdk-in-ubuntu-16-04-lts). 


## References

* [remove-openjdk-and-install-oracle-jdk on ubuntu](https://flicsdb.com/remove-openjdk-and-install-oracle-jdk-on-ubuntu/) August 4, 2019 by [zshaik](https://flicsdb.com/author/zshaik/). 
* [How to Install Oracle Java 12 in Ubuntu 18.04 / 16.04](https://laptrinhx.com/how-to-install-oracle-java-12-in-ubuntu-18-04-16-04-2045321107/), 2019-03-25


## Summary

Remove OpenJDK and install Official JDK

Step 1. Remove OpenJDK first

```bash
$ sudo apt-get purge openjdk*
```

Step 2. Add the repository for Official JDK and update

```bash
$ sudo add-apt-repository ppa:linuxuprising/java
$ sudo apt-get update
```

Step 3. Install Official JDK

  $ sudo apt-get install -y oracle-java12-installer

