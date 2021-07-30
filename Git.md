Git 사용법에 대해서 정리한 문서입니다.
원글은 본문 하단에 링크로 첨부합니다.

## INDEX
[Git 커맨드 모음](#command)
[Git 오픈소스 활동기](#contribute)
[Git 빌드 자동화하기(Jenkins)](#jenkins)

## GGit 커맨드 모음<span id="command"></span>
원격 저장소 브랜치 삭제하기
git push origin --delete '브랜치명'

로컬 저장소 브랜치 삭제하기
git branch -d '브랜치명'


## Git 오픈소스 활동<span id="contribute"></span>

* 오픈소스를 먼저 fork를 하면 내 저장소에 저장된다.
이후 내 컴퓨터 한켠에 소중하게 당겨와본다
> git clone https://~~~

* 브랜치를 새로 만들어서 수정사항을 반영한다

(브랜치를 만들지 않아도 되지만 이력이 지저분해지거나 에러 발생시 저장소를 지워야할 수도 있다. 본인경험담..ㅠ)

master 브랜치에서
> git checkout (아이디-이슈명#1)

체크아웃하여 이동된 브랜치에서
> git add *

> git commit -m "명령문으로 짧고 간결하게 작성"

> git checkout master

체크아웃하여 이동된 master 브랜치에서
> git checkout merge (브랜치 명)

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

---

## 2. 빌드 자동화하기(Jenkins)<span id="jenkins"></span>

1. [젠킨스](https://jenkins.io/download/) 설치 및 계정 생성

2. Github에서 Setting → Developer Setting → Personal Access Tokens 접속 후 토큰생성('repo'와 'admin:repo_hook' 선택)

3. 젠킨스 대시보드에서 Jenkins 관리(Manage Jenkins) → 시스템 설정(Configure System) → Github 항목에서 add github server 선택

4. Name : 구별가능한 아무 이름, 

   API URL : 그대로 둠, 
   
   Credential : add 선택 (kind : secret text, secret : github 토큰값) 
   
   다됬다면 test connection으로 잘 연결되었는지 확인 후 저장

5. 젠킨스 대시보드에서 New Items → FreeStyle Project 고르고 생성

6. 생성한 젠킨스 프로젝트 '구성' → github project에 체크한 뒤 자동화할 프로젝트 url을 삽입(오래된 빌드 삭제 옵션도 체크하면 좋다)

7. 생성한 젠킨스 프로젝트 '구성' → 소스코드 관리 항목에서 Git 체크 / 4번과 같은 방법으로 등록 후 저장

   빌드 유발(Build Triggers)항목에서 GitHub hook trigger for GitScm Polling을 선택

8. 젠킨스 대시보드에서 Jenkins 관리(Manage Jenkins) → 시스템 설정(Configure System) → Jenkins Location 항목 이동

   외부에서 접근할 수 있는 도메인이나 IP 입력
   
9. 자동화할 Github 프로젝트의 설정 → Webhooks → 8번Jenkins 주소/github-webhook/입력

10. *여기까지가 자동 빌드 과정이며, 자동 배포 부분은 추후 작성예정입니다*




---

## 참고자료 

1. [Git 명령어 정리](https://medium.com/@joongwon/git-git-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%A0%95%EB%A6%AC-c25b421ecdbd)
2. [누구나 쉽게 이해할 수 있는 Git 입문](https://backlog.com/git-tutorial/kr/stepup/stepup1_1.html)
3. [Delete commits history with git commands](https://gist.github.com/heiswayi/350e2afda8cece810c0f6116dadbe651)
4. [깃허브로 취업하기](http://sujinlee.me/professional-github/)
5. [오픈소스 입문을 위한 아주 구체적인 가이드](https://bit.ly/2RulANs)
6. [gitHub와 Jenkins 연결하기](https://bcho.tistory.com/1237)
7. [[Jenkins] Github 프로젝트 연동, webhook, 자동배포 (3)](https://kutar37.tistory.com/entry/Jenkins-Github-%EC%97%B0%EB%8F%99-%EC%9E%90%EB%8F%99%EB%B0%B0%ED%8F%AC-3)
