#pragma once
typedef struct {
    char* command[100]; // �Է� ���� API ���� ����. (��ɾ� ���� Maximum : 100)
    int step; // �Է� ���� API�� Step ���� ��� ���� ����.
} CommandList;

void Typing_API_To_Editor();