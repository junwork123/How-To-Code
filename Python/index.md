파이썬 문법 및 유용한 코드를 모아놓은 곳입니다.

## INDEX

1. 문자열 관련 메소드
```python
# 문자열 교체
str.replace('new', 'old')

# 문자열 나눔
str = 'h e l l o'
str.split(' ')
>>> ['h','e','l','l','o']

# 문자열 연결
list = ['h','e','l','l','o']
''.join(list)
>>> hello

# 문자열 판단
'year2017'.isalnum()
>>> True

'year2017!!!'.isalnum()
>>> False

# 문자열 길이
len('hello')
>>> 5

# 문자열 검색
'hello'.find('l')
>>> 2

# find와 동일, 없을 때 예외를 발생
'hello'.index('l')
>>> 2

'l' in 'hello'
>>> True

'l' not in 'hello'
>>> False
```

---

## 2. 정규표현식(re모듈)

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

+ 주요 메소드
```python
# 동일한 구문을 많이 써야하는 경우 정규식 객체를 반환
c = re.compile('[0-9]')

# 문자열 전체에서 검색
re.search('[a-z]', '123abc45').start()
>>> 3
re.search('[a-z]', '123abc45').end()
>>> 4

re.search('[a-z]+', '123abc45').start()
>>> 3
re.search('[a-z]+', '123abc45').end()
>>> 6

# 문자열 전체에서 일치하는 모든 부분을 검색
re.findall('[a-z]','123abc45')
>>> ['a', 'b', 'c']
re.findall('[a-z]+','123abc45')
>>> ['abc']
```

---

## 참고자료
1. [파이썬 - 정규표현식 모듈](https://devanix.tistory.com/296)
2. [파이썬 str 문자열 객체 메소드 함수 정리](https://withcoding.com/74)
3. [파이썬 정규표현식(re) 사용법](https://greeksharifa.github.io/정규표현식(re)/2018/07/20/regex-usage-01-basic/)
4. [정규식 단어 경계 메타 문자의 정확한 이해](https://ohgyun.com/392)
