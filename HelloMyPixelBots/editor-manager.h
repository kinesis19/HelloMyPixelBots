#pragma once
typedef struct {
    char* command; // 입력 받은 API 저장 변수.
    int step; // 입력 받은 API의 Step 등의 상수 저장 변수.
} Command;

void Typing_API_To_Editor();