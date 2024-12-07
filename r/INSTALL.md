* Draft: 2019-04-18 (Thu)

# Ubuntu에 R 및 패키지 설치하기

구글 검색: how to install r on ubuntu
참고 문서: Download and Install R in Ubuntu, https://www.r-bloggers.com/download-and-install-r-in-ubuntu/

## 터미널에서 설치하기
(1) 우분투에서 터미널 열기 Ctrl+Alt+T
(2) $ sudo apt-get update 
(3) sudo apt-get install -y r-base

## 설치 확인 하기
구글 검색: ubuntu r
참고 문서: How To Install R on Ubuntu 18.04, https://www.digitalocean.com/community/tutorials/how-to-install-r-on-ubuntu-18-04

(4) R 시작하기
$ R

R version 3.4.4 (2018-03-15) -- "Someone to Lean On"
Copyright (C) 2018 The R Foundation for Statistical Computing
Platform: x86_64-pc-linux-gnu (64-bit)

R은 자유 소프트웨어이며, 어떠한 형태의 보증없이 배포됩니다.
또한, 일정한 조건하에서 이것을 재배포 할 수 있습니다.
배포와 관련된 상세한 내용은 'license()' 또는 'licence()'을 통하여 확인할 수 있습니다.

R은 많은 기여자들이 참여하는 공동프로젝트입니다.
'contributors()'라고 입력하시면 이에 대한 더 많은 정보를 확인하실 수 있습니다.
그리고, R 또는 R 패키지들을 출판물에 인용하는 방법에 대해서는 'citation()'을 통해 확인하시길 부탁드립니다.

'demo()'를 입력하신다면 몇가지 데모를 보실 수 있으며, 'help()'를 입력하시면 온라인 도움말을 이용하실 수 있습니다.
또한, 'help.start()'의 입력을 통하여 HTML 브라우저에 의한 도움말을 사용하실수 있습니다
R의 종료를 원하시면 'q()'을 입력해주세요.

> 

(5) R 끝내기
> q()
> Save workspace image? [y/n/c]: n
> $

## 패키지 설치하기

참고 문서: Installing R Packages, http://jtleek.com/modules/01_DataScientistToolbox/02_09_installingRPackages/#4
Base R을 설치했지만, package를 설치해야 합니다. 주요 위치는 CRAN으로 설치 가능한 패키지는 아래와 같이 볼 수 있습니다.

> a<-available.packages()
> head( rownames(a),3)
> [1] "A3"     "abbyyR" "abc"   
> head( rownames(a),5)
> [1] "A3"       "abbyyR"   "abc"      "abc.data" "ABC.RAP" 

### 설치한 패키지 로딩하기
library(ggplot2)
로딩 후에 가능한 함수를 볼 수 있습니다.
search()

### 여러개의 패키지 설치하기

아래 처럼 실행하면, 2번째부터 설치가 불가능하다.
> install.packages("stringr","tfdatasets", "keras")
> Warning in install.packages("stringr", "tfdatasets", "keras") :
> 'lib = "tfdatasets"' is not writable
> Would you like to use a personal library instead?  (y/n)
>

문제: not writable일 경우, $ sudo R로 실행하면 된다.
$ R
...
> install.packages("stringr")
> Installing package into '/usr/local/lib/R/site-library'
> (as 'lib' is unspecified)
> Warning in install.packages("stringr") :
> 'lib = "/usr/local/lib/R/site-library"' is not writable
> Would you like to use a personal library instead?  (y/n) 
>

$ sudo R

> install.packages("stringr")