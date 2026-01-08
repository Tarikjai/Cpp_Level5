#include <windows.h>
#pragma comment(lib, "winmm.lib")

int main() {
	PlaySound(TEXT("SystemExclamation"), NULL, SND_ALIAS);

}
