// BugHunter.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "INC_Windows.h"
#include "BugHunter.h"

// Test
#include "SGWinBase.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    SGWinBase test(hInstance);

    test.MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!test.InitInstance(nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}