#include "append.h"

void go(char *args, int length) {

    datap parser;
    BeaconDataParse(&parser, args, length);
    CHAR *text = BeaconDataExtract(&parser, NULL);
    CHAR *file = BeaconDataExtract(&parser, NULL);

    HANDLE hFile = KERNEL32$CreateFileA(file, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        ULONG dwLastError = KERNEL32$GetLastError();
        printf("CreateFileA failed with 0x%08lX (%lu)\n", dwLastError, dwLastError);
        return;
    }

    ULONG dwLastError = KERNEL32$GetLastError();
    
    KERNEL32$SetFilePointer(hFile, 0, NULL, FILE_END);
    ULONG numBytesWritten1 = 0;
    ULONG numBytesWritten2 = 0;
    BOOL success1 = KERNEL32$WriteFile(hFile, "\n", 1, &numBytesWritten1, NULL);
    if (!KERNEL32$WriteFile(hFile, text, MSVCRT$strlen(text), &numBytesWritten2, NULL)) {
        ULONG dwLastError = KERNEL32$GetLastError();
        printf("WriteFile failed with 0x%08lX (%lu)\n", dwLastError, dwLastError);
    }

    if (dwLastError == ERROR_ALREADY_EXISTS) {
        printf("Appending text to it\n");
    }
    else {
        printf("Created the file with text in it\n");
    }

    KERNEL32$CloseHandle(hFile);
    return;
}

