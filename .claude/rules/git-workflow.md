# Git 워크플로우

## 추적되는 파일 (git에 포함)

- `Source/` — C++ 소스 코드
- `Content/` — 에셋 (블루프린트, 머티리얼, 레벨 등)
- `Config/` — 게임 설정 (.ini 파일)
- `DDD.uproject` — 프로젝트 디스크립터
- `CLAUDE.md`, `.claude/` — Claude Code 설정

## 무시되는 파일 (gitignore)

- `Binaries/` — 컴파일 결과물, 빌드 시 자동 생성
- `Intermediate/` — 빌드 중간 파일
- `DerivedDataCache/` — 에셋 캐시
- `Saved/` — 로그, 크래시 덤프, 임시 저장
- `*.sln` — Visual Studio가 자동 생성
- `.vs/` — IDE 개인 설정

## 다른 컴퓨터에서 클론 후 셋업

```bash
git clone <repo-url>
```

1. `DDD.uproject` 우클릭 → "Generate Visual Studio project files"
2. 생성된 `DDD.sln`을 Visual Studio로 열기
3. 빌드 (Development Editor | Win64)
4. `DDD.uproject` 더블클릭으로 에디터 실행

## Content/ 대용량 에셋 주의

바이너리 에셋(텍스처, 메시, 사운드)이 많아지면 Git LFS 도입을 고려:
```bash
git lfs track "*.uasset"
git lfs track "*.umap"
git lfs track "*.png"
git lfs track "*.wav"
```
