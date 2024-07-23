#pragma once
typedef struct {
    char* command[100]; // 입력 받은 API 저장 변수. (명령어 길이 Maximum : 100)
    int step; // 입력 받은 API의 Step 등의 상수 저장 변수.
} CommandList;

void Typing_API_To_Editor();