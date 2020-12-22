* Draft: 2020-12-22 (Tue)

# 파이썬 코딩 스타일 가이드(Python Coding Style Guides)
## 왜 스타일 가이드가 필요한가?
코딩 스타일 가이드는 코드의 가독성을 높이기 위해서 필요합니다.

### 보이스카웃 룰 by 클린코드
> Always leave the campground cleaner than you found it.

> 캠프장에 왔을 때보다 더 깨끗히 하고 떠나라. 항상...

### 통일된 스타일의 필요성
* 지금 내가 짜는 코드는 (나를 포함해서) 다른 사람이 보게 됩니다.
* 다른 사람의 코드는 읽고 이해하기 힘든 경우가 많습니다.
* 그래서 자기만 알아볼 수 있는 스타일의 코드는 나쁩니다.
* 가독성이 떨어지는 자기만의 스타일이 아니라, 통일된 스타일이 있으면 코드의 가독성을 높일 수 있습니다.

## 파이썬 스타일 가이드
자세한 내용은 [파이썬 (doc) 스타일 가이드에 대한 정리](https://medium.com/@kkweon/%ED%8C%8C%EC%9D%B4%EC%8D%AC-doc-%EC%8A%A4%ED%83%80%EC%9D%BC-%EA%B0%80%EC%9D%B4%EB%93%9C%EC%97%90-%EB%8C%80%ED%95%9C-%EC%A0%95%EB%A6%AC-b6d27cd0a27c)을 참고하세요.

### PEP8
- 모든 스타일 가이드의 기초
- Guido van Rossum (파이썬 창시자)가 작성
- “Readability is everything”이라는 파이썬 철학이 담김

내용 요약은
* [PEP 8 파이썬 코딩 스타일](http://pythonstudy.xyz/python/article/511-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%BD%94%EB%94%A9-%EC%8A%A4%ED%83%80%EC%9D%BC)
* [파이썬 (doc) 스타일 가이드에 대한 정리](https://medium.com/@kkweon/%ED%8C%8C%EC%9D%B4%EC%8D%AC-doc-%EC%8A%A4%ED%83%80%EC%9D%BC-%EA%B0%80%EC%9D%B4%EB%93%9C%EC%97%90-%EB%8C%80%ED%95%9C-%EC%A0%95%EB%A6%AC-b6d27cd0a27c)
* [코드 스타일](https://python-guide-kr.readthedocs.io/ko/latest/writing/style.html#one-statement-per-line), [The Hitchhiker's Guide to Python](https://www.amazon.com/Hitchhikers-Guide-Python-Practices-Development/dp/1491933178/ref=as_li_ss_il?ie=UTF8&linkCode=li2&tag=bookforkind-20&linkId=804806ebdacaf3b56567347f3afbdbca), O'Reilly, Kenneth Reitz & Tanya Shulusser

전체 내용은
* [PEP 8 -- Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/)
를 참고하세요.

### [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)
- PEP8과 유사하나 차이는 Docstring 작성법을 더 깊히 다룸
- 구글 프로젝트 (예: TensorFlow) 때문에 자주 접하게 됨

### [numpydoc docstring guide](https://numpydoc.readthedocs.io/en/latest/format.html)
- PEP8과 유사하나 차이는 Docstring 작성법을 더 깊히 다룸

## 참고
* [PEP 8 파이썬 코딩 스타일](http://pythonstudy.xyz/python/article/511-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%BD%94%EB%94%A9-%EC%8A%A4%ED%83%80%EC%9D%BC)
* [파이썬 (doc) 스타일 가이드에 대한 정리](https://medium.com/@kkweon/%ED%8C%8C%EC%9D%B4%EC%8D%AC-doc-%EC%8A%A4%ED%83%80%EC%9D%BC-%EA%B0%80%EC%9D%B4%EB%93%9C%EC%97%90-%EB%8C%80%ED%95%9C-%EC%A0%95%EB%A6%AC-b6d27cd0a27c)
* [코드 스타일](https://python-guide-kr.readthedocs.io/ko/latest/writing/style.html#one-statement-per-line), [The Hitchhiker's Guide to Python](https://www.amazon.com/Hitchhikers-Guide-Python-Practices-Development/dp/1491933178/ref=as_li_ss_il?ie=UTF8&linkCode=li2&tag=bookforkind-20&linkId=804806ebdacaf3b56567347f3afbdbca), O'Reilly, Kenneth Reitz & Tanya Shulusser
* [PEP 8 -- Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/)
* [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html)
