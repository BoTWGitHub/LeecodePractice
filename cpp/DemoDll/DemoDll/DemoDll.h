#pragma once

#ifdef DEMODLL_EXPORTS
#define DEMODLL_API __declspec(dllexport)
#else
#define DEMODLL_API __declspec(dllimport)
#endif

extern "C" DEMODLL_API int Fibonacci(const int);
extern "C" DEMODLL_API void MsgBox(char*);
