#include <cstdio>
#include <cstring>
#include <Windows.h>

class clip{
private:
    HANDLE hClip;
    char* str;
    char buf[4096];
public:
    clip() {
        OpenClipboard(NULL);
        hClip = GetClipboardData(CF_TEXT);
        if (hClip != NULL) {
            str = (char*)GlobalLock(hClip);
            printf("%s\n",str);
            GlobalUnlock(hClip);
        }
        strcpy(buf, str);
        CloseClipboard();
    }
    void main();
};

void clip::main() {
    OpenClipboard(NULL);
    hClip = GetClipboardData(CF_TEXT);
    if (hClip != NULL) {
        str = (char*)GlobalLock(hClip);
        if (strcmp(buf, str) != 0) {
            printf("%s\n", str);
            strcpy(buf, str);
        }
        GlobalUnlock(hClip);
    }
    CloseClipboard();
}

int main()
{
    clip c;
    while (1) {
        Sleep(1000);
        c.main();
    }
    return 0;
}
