파이썬 문법 및 유용한 코드를 모아놓은 곳입니다.

## INDEX
[1. 문자열 관련 메소드](#string)

[2. 리스트 관련 메소드](#list)

[3. 정규표현식(re모듈)](#re)

[4. List Comprehention](#compre)

[5. 유용한 함수](#useful)


### 문자열 관련 메소드<span id="string"></span>

```python
# 문자열 뒤집기
s = s[::-1]

# 문자열 교체(공백 or 특정문자제거)
s = s.replace(' ', '')

import re
s = re.sub(r'[^a-zA-Z0-9]','',s)

# 문자열 나눔
s = 'h e l l o'
s.split(' ')
= ['h','e','l','l','o']

# 문자열 연결
list = ['h','e','l','l','o']
''.join(list)
= hello

# 문자열 판단
'year2017'.isalnum()
= True

'year2017!!!'.isalnum()
= False

# 문자열 길이
len('hello')
= 5

# 문자열 검색
'hello'.find('l')
= 2

# find와 동일, 없을 때 예외를 발생
'hello'.index('l')
= 2

'l' in 'hello'
= True

'l' not in 'hello'
= False
```

---

### 리스트 관련 함수<span id="list"></span>

```python

# 리스트 뒤집기
l.reverse()

# List Comprehensions 방식으로 생성하기
l = [i * i for in range(10)
l = [i for i in L if i % 3 == 0)

# 리스트 안에 값 확인
print(5 in l)
print(5 not in l)

# 리스트 값 추가
l.append(val) # 값 추가

l.insert(index, val) # 값 추가

l.extend(iterable) # iterable 인자를 넘겨 리스트에 추가
l.extend(range(10,13)) # 10~12까지 

# 리스트 값 삭제
del(l[index]) # 특정 인덱스 삭제

del(l) # 리스트 자체 삭제

l.pop(index) # 특정 인덱스 위치의 값을 리턴하면서 삭제

l.remove(val) # 전달한 값을 삭제

l.clear() # 리스트 값 모두 삭제(빈 리스트 생성)

# 리스트 정렬
l.sort() # 오름차순 정렬
l.sort(reverse=True) # 내림차순 정렬

# 리스트 길이
len(l)

# 리스트 슬라이싱
l[::2] # 리스트에서 짝수번째만 가져옴
sum(sorted(nums)[::2]) # 리스트 정렬 후 짝수번째만 합치기

# 리스트 문자열 합치기
A = ["a", "b", "c"]
l = "".join(A)

# 리스트 내부 정렬
# 띄어쓰기 기준으로 나눈 뒤 사전식 정렬, 같을 경우 맨 앞 기준 정렬
l.sort(key=lambda x : l.split()[1:], l.split()[0]) 

# defaultDict를 탐색할 때 
# list()로 감싸줘야 key size changed 에러 발생 방지
for item in list(newDict):
    #----
```





### 정규표현식(re모듈)<span id="re"></span>


+ 주요 메소드
```python
import re

# 특수문자 제거
s = re.sub(r"[^a-zA-Z0-9]","",s)

# 동일한 구문을 많이 써야하는 경우 정규식 객체를 반환
c = re.compile('[0-9]')

# 문자열 전체에서 검색
re.search('[a-z]', '123abc45').start()
= 3
re.search('[a-z]', '123abc45').end()
= 4

re.search('[a-z]+', '123abc45').start()
= 3
re.search('[a-z]+', '123abc45').end()
= 6

# 문자열 전체에서 일치하는 모든 부분을 검색
re.findall('[a-z]','123abc45')
= ['a', 'b', 'c']
re.findall('[a-z]+','123abc45')
= ['abc']
```

+ 자주 쓰이는 예시

[Pp]ython : Python 혹은 python

[^aeiou] : 소문자 모음 제외

^abc : abc로 시작해야함

xyz$ : xyz로 종료되어야함

\d{3} : 숫자가 3개 있어야 함

\d+ : 숫자가 1개 이상

\d? : 숫자가 1개던지 없던지


+ 반복횟수

\* : 0회 이상 반복

\+ : 1회 이상 반복

? : 0회 or 1회

{m} : m회 반복

{m,n} : m회에서 n회까지 반복

+ 매칭조건
. : 줄바꿈 문자를 제외한 모든 문자와 매치됨

^ : 문자열의 시작과 매치

$ : 문자열의 마지막과 매치

[] : 문자 집합 중 하나 *ex : [0-9]*

| : 또는(or)을 의미

{} : 정규식을 그룹으로 묶음

+ 이스케이프 기호
\\ : 역슬래쉬 문자 자체

\\d : 모든 숫자 [0-9]

\\D : 숫자가 아닌 문자 [^0-9]

\\w : 숫자 또는 문자와 매치됨

\\W : 숫자 또는 문자가 아닌 것과 매치됨

\\b : 단어(숫자, 영문자의 연속)의 경계

\\B : 단어(숫자, 영문자의 연속)의 경계가 아닌 것

> *ex : Raindrops on roses, and whiskers on kittens.*
>
> 위 문장에서 단어의 경계, 즉 메타 문자 \b 는 아래와 같이 | 를 표시한 위치를 가리킨다.
>
> |Raindrops| |on| |roses|, |and| |whiskers| |on| |kittens|.
>
> 이 문장에서  /\bo.\b/ 를 매치시킨 결과는 다음과 같다.
>
> |Raindrops| _**|on|**_ |roses|, |and| |whiskers| _**|on|**_ |kittens|.
>
> 패턴이 단어의 경계 사이에 있는 o와 나머지 한 문자를 나타내기 때문이다.
>
> \B 는 \b와 반대로 동작하는데, 이것도 각 위치를 표시해보면 이해하기 쉽다.
>
> R|a|i|n|d|r _**|o|p|**_ s o|n r| _**o|s|**_ e|s, a|n|d w|h|i|s|k|e|r|s o|n k|i|t|t|e|n|s.


\\A : 문자열의 처음에만 일치

\\Z : 문자열의 끝에만 일치

\\s : 공백문자 [\\t\\n\\r\\f\\v]

\\S : 공백문자가 아닌 것 [^\\t\\n\\r\\f\\v]

+ 플래그
X, VERBOSE : 정규식 안의 공백을 무시

I, IGNORECATE : 대소문자를 구별하지 않는다.

### List Comprehention<span id="compre"></span>
```python

string1 = 'abc'
string2 = 'acc'

# 문자열에서 한글자씩 뽑아서 출력
char for char in string
= ['a', 'b', 'c']

# 문자열1에 있는 글자가 2에 있는지 출력
char in string2 for char in string
= [True, False, True]

# 문자열1에 있는 글자가 2에 몇개나 있는지 출력
sum(char in string2 for char in string)
= 2

```
### 유용한 함수<span id="useful"></span>
```python
# zip() = 두 개 이상의 시퀀스를 하나로 묶어서 튜플로 반환
# zip은 제너레이터를 반환하므로 출력 시 list(zip(x,y))형태로 사용

x = [1,2,3,4,5]
y = [a,b,c,d]
z = [ㄱ,ㄴ]

# zip 개별 접근 및 튜플 반환 확인
d = list(zip(x,y))
print(d)
= [(1,a), (2,b), (3,c), (4,d)]

d[0] 
= (1,a)

d[0][0]
= 1

d[0][0]

# 하나 묶기
list(zip(x))
= [(1,), (2,), (3,), (4,)]

# 3개 묶기
list(zip(x,y,z))
= [(1,a,ㄱ), (2,b,ㄴ)]

# ---------------------------------------

# 아스테리스크(*) : 시퀀스 언패킹 연산자
fruit = [apple, tomato, banana]
*fruit = apple, tomato, banana

# 앞의 파라미터 갯수만큼 넣고 나머지는 언패킹하여 b에 넣음
a, b, *c = [1,2,3,4]
print(a)
= 1
print(b) 
= 2
print(c)
= [3,4]

# 아스테리스크 2개(**)는 사전(Dictionary)과 같은 키/값 페어 연산에서 사용
info = {'year' : 2014, 'month' : 12, 'day' : 25}
newInfo1 = {'year' : 2021, **info}
newInfo2 = {**info, 'month' : 1, 'day' : 25}


```


### 파싱 라이브러리 BeautifulSoup4(bs4)<span id="bs4"></span>

아래 코드는 크롤링한 데이터를 Python파일와 같은 위치에 result.json을 만들어 저장하는 예제.(이준범님 코드)

내가 직접 만든 크롤러는 [NewsCralwer](https://github.com/MaliciousJ/NewsCrawler)를 참고하자.

여러 특성(제목, 날짜, 키워드분류 등)에 대한 분류가 가능하다.

```python
# parser.py
import requests
from bs4 import BeautifulSoup
import json
import os

# python파일의 위치
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

req = requests.get('https://beomi.github.io/beomi.github.io_old/')
html = req.text
soup = BeautifulSoup(html, 'html.parser')
my_titles = soup.select(
    'h3 > a'
    )

data = {}

for title in my_titles:
    data[title.text] = title.get('href')

with open(os.path.join(BASE_DIR, 'result.json'), 'w+') as json_file:
    json.dump(data, json_file)
```

---

## 참고자료
1. [파이썬 - 정규표현식 모듈](https://devanix.tistory.com/296)
2. [파이썬 str 문자열 객체 메소드 함수 정리](https://withcoding.com/74)
3. [파이썬 정규표현식(re) 사용법](https://greeksharifa.github.io/정규표현식(re)/2018/07/20/regex-usage-01-basic/)
4. [정규식 단어 경계 메타 문자의 정확한 이해](https://ohgyun.com/392)
5. [나만의 웹 크롤러 만들기 with Requests/BeautifulSoup](https://beomi.github.io/2017/01/20/HowToMakeWebCrawler/)
6. [파이썬 list 리스트 사용법 정리 (삽입, 삭제, 정렬)](https://withcoding.com/75)
