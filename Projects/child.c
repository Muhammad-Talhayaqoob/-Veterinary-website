#include <stdio.h>
#include <windows.h>
#define BUFFER 25
int main()
{
    HANDLE Read;
    CHAR buff[BUFFER];
    DWORD read;
    Read = GetStdHandle(STD_INPUT_HANDLE);
    if (ReadFile(Read, buff, BUFFER, &read, NULL))
    {
        printf("Child Read %s", buff);
    }
    return 0;
}