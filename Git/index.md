Git 사용법에 대해서 정리한 문서입니다.
원글은 본문 하단에 링크로 첨부합니다.

## INDEX
1. [case : 오픈소스에 기여하기](#contribute)

## case : 오픈소스에 기여하기<span id="contribute"></span>

* 오픈소스를 먼저 fork를 하면 내 저장소에 저장된다.
이후 내 컴퓨터 한켠에 소중하게 당겨와본다
> git clone https://~~~

* 브랜치를 새로 만들어서 수정사항을 반영한다

(브랜치를 만들지 않아도 되지만 이력이 지저분해지거나 에러 발생시 저장소를 지워야할 수도 있다. 본인경험담..ㅠ)
> git branch -b (아이디-이슈명#1)
> git add *
> git commit -m "명령문으로 짧고 간결하게 작성"

*※ 브랜치 명은 각각 다를 수 있음!*

*※ 커밋 메시지에 대한 원칙은 [여기](https://meetup.toast.com/posts/106)에서 참조*

* 내가 수정한 것을 반영하고 싶다면 PR(Pull request)를 해야한다.

해당 오픈소스 저장소에 가서 Pull Request 항목으로 가서 반영요청을 한다.

요청을 했다면 리뷰어들이 수락할때까지 기다리면 된다.

* 한편, 저장소가 업데이트 되어 내 로컬 저장소와 동기화 시킬 필요가 있을 때에는 
fetch / pull 명령어를 쓴다
> git fetch

원격 저장소에서 합치지 않고 지역 브랜치로 변경 사항 가져오기
> git fetch <원격 저장소>

원격 저장소에서 변경 사항을 가져와 현재 브랜치에 합치기
> git pull <원격 저장소>

origin 저장소에서 변경 사항을 가져와 현재 브랜치에 합치기
> git pull

* case 2 : ---

---

## 참고자료 

1. [Git 명령어 정리](https://medium.com/@joongwon/git-git-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%A0%95%EB%A6%AC-c25b421ecdbd)
2. [누구나 쉽게 이해할 수 있는 Git 입문](https://backlog.com/git-tutorial/kr/stepup/stepup1_1.html)
3. [Delete commits history with git commands](https://gist.github.com/heiswayi/350e2afda8cece810c0f6116dadbe651)
4. [깃허브로 취업하기](http://sujinlee.me/professional-github/)
5. [오픈소스 입문을 위한 아주 구체적인 가이드](https://bit.ly/2RulANs)
