#pragma once

#include "targetver.h"

// 헤더를 최소한으로 include하고, 안전하게 동작할 수 있도록 옵션 설정
#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// Windows 헤더 파일
#include <windows.h>