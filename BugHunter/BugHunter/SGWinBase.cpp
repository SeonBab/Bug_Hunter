#include "SGWinBase.h"
#include "BugHunter.h"

SGWinBase::SGWinBase(HINSTANCE hInstance) : hInst(hInstance)
{
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_BUGHUNTER, szWindowClass, MAX_LOADSTRING);

	m_hWnd = HWND();
	m_width = 0;
	m_height = 0;
}

ATOM SGWinBase::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BUGHUNTER));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_BUGHUNTER);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL SGWinBase::InitInstance(int nCmdShow)
{
	HWND hWnd = CreateWindowExW(0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

void SGWinBase::OnResize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void SGWinBase::OnClose()
{

}

//  용도: 주 창의 메시지를 처리합니다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	{
		SGWinBase* pNzWnd = (SGWinBase*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if (pNzWnd)
		{
			pNzWnd->OnResize(LOWORD(lParam), HIWORD(lParam));
		}
		break;
	}

	case WM_CLOSE:
	{
		SGWinBase* pNzWnd = (SGWinBase*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if (pNzWnd)
		{
			pNzWnd->OnClose();
		}
		DestroyWindow(hWnd);
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	}

	return NULL;
}