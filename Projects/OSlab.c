#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BUFFER 25
int main()
{
    HANDLE Read, Write;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    char message[BUFFER] = "Hello World";
    DWORD written;
    SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    ZeroMemory(&pi, sizeof(pi));
    if (!CreatePipe(&Read, &Write, &sa, 0))
    {
        fprintf(stderr, "Failed");
        return 1;
    }
    GetStartupInfo(&si);
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si.hStdInput = Read;
    si.dwFlags = STARTF_USESTDHANDLES;
    SetHandleInformation(Write, HANDLE_FLAG_INHERIT, 0);
    CreateProcess(NULL, "E:\\Bushra Data\\OS LAB\\aChild\\Debug\\child.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    CloseHandle(Read);
    if (!WriteFile(Write, message, BUFFER, &written, NULL))
        fprintf(stderr, "Write Failed");
    CloseHandle(Write);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}