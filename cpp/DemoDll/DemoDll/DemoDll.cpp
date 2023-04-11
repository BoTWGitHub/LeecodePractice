#include "pch.h"
#include "DemoDll.h"
#include <string>
#include <Windows.h>

extern "C" int Fibonacci(const int n)
{
    if (n < 2)
    {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

extern "C" void MsgBox(char* msg)
{
    wchar_t wtext[20];
    mbstowcs(wtext, msg, strlen(msg) + 1);//Plus null
    LPWSTR ptr1 = wtext;

    char cap[] = "MsgBox From C";
    wchar_t cap_wstr[20];
    mbstowcs(cap_wstr, cap, strlen(cap) + 1);
    LPWSTR ptr2 = cap_wstr;
    MessageBox(0, ptr1, ptr2, MB_ICONINFORMATION);
}
