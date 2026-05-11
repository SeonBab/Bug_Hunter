#pragma once

#include "INC_Windows.h"

#define MAX_LOADSTRING 100

// 함수 선언
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class SGWinBase
{
public:
	SGWinBase(HINSTANCE hInstance);
	~SGWinBase() = default;

	//  용도: 창 클래스를 등록합니다.
	ATOM MyRegisterClass(HINSTANCE hInstance);


	//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
	//
	//   주석:
	//
	//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
	//        주 프로그램 창을 만든 다음 표시합니다.
	BOOL InitInstance(int nCmdShow);

protected:
	virtual void OnResize(int width, int height);
	virtual void OnClose();

private:
	HINSTANCE hInst;						// 현재 인스턴스입니다.
	WCHAR szTitle[MAX_LOADSTRING];          // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];    // 기본 창 클래스 이름입니다.

	HWND m_hWnd;
	int m_width;
	int m_height;

protected:
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
};

