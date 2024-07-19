#include <stdio.h>
#include <Windows.h>

int main() {
    // 콘솔 창의 핸들을 가져오기.
    HWND consoleWindow = GetConsoleWindow();
    // 현재 창의 스타일을 가져오기.
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    // 크기 조절 박스와 최대화 박스 스타일을 제거하여 크기 조절을 비활성화하기.
    style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
    // 수정된 스타일을 설정하기.
    SetWindowLong(consoleWindow, GWL_STYLE, style);
    // 콘솔 창의 사이즈는 200 * 50 size로 지정하기.
    system("mode con:cols=200 lines=50");



    return 0;
}
