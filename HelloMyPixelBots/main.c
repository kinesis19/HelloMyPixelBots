#include <stdio.h>
#include <Windows.h>

int main() {
    // �ܼ� â�� �ڵ��� ��������.
    HWND consoleWindow = GetConsoleWindow();
    // ���� â�� ��Ÿ���� ��������.
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    // ũ�� ���� �ڽ��� �ִ�ȭ �ڽ� ��Ÿ���� �����Ͽ� ũ�� ������ ��Ȱ��ȭ�ϱ�.
    style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
    // ������ ��Ÿ���� �����ϱ�.
    SetWindowLong(consoleWindow, GWL_STYLE, style);
    // �ܼ� â�� ������� 200 * 50 size�� �����ϱ�.
    system("mode con:cols=200 lines=50");



    return 0;
}
