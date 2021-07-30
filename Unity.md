1. VS Code에서 유니티 자동완성이 먹통일때
- Edit->Preferences->External Tools 탭에 들어가면 유니티 에디터를 확인할 수 있습니다. 여기에서 VSCode로 제대로 잡혀 있는지 확인해야 합니다.
- Ctrl-Shift-P를 통해 명령 창을 열고, Omni: Select Project를 입력하세요.
  (Select Project로만 입력해도 뜰 거예요)
  현재 열린 프로젝트를 선택하는 명령어로, 이를 실행하면 현재 열려 있는 폴더의 프로젝트를 선택하게 됩니다.

- 이동
```Unity
    void Update()
    {
        // h = Input.GetAxis("Horizontal");
        // v = Input.GetAxis("Vertical");
        // Move2D(h,v);
        // if(Input.GetKeyDown(KeyCode.R))
        //     Rotate();
        
    }
    protected void Move2D(float h, float v){
        Vector2 moveDir = Vector2.up * v + Vector2.right * h;
        tr.Translate(moveDir.normalized * moveSpeed * Time.deltaTime, Space.Self);
    }
```

- 텔레포트
transform.position = new vector3 (x, y, z);

- UI 비율 (https://solution94.tistory.com/76)
Canvas에 Canvas Renderer 넣고 렌더 모드를 Screen Space - Camera로 변경
카메라도 Projection 값을 Orthographic으로 변경
