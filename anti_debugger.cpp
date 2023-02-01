//////////////////////////////////////////
// Dont Forget Its Just Example.
//////////////////////////////////////////

//////////////////////////////////////////
// Example of Internal Debug Attach.
//////////////////////////////////////////

#include <windows.h>
#include <iostream>

int main() {
    BOOL isDebuggerPresent = FALSE;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebuggerPresent);
    if (isDebuggerPresent) {
        std::cout << "Debugger attached." << std::endl;
    } else {
        std::cout << "No debugger attached." << std::endl;
    }
    return 0;
}

//////////////////////////////////////////
// Example of erasing the PE header of a program from memory.
/////////////////////////////////////////

#include <Windows.h>
#include <iostream>

void ErasePEHeader(HMODULE hModule)
{
    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;
    PIMAGE_NT_HEADERS pNtHeaders = (PIMAGE_NT_HEADERS)((DWORD_PTR)hModule + pDosHeader->e_lfanew);

    DWORD headerSize = pNtHeaders->OptionalHeader.SizeOfHeaders;
    DWORD oldProtect;


    if (!VirtualProtect((LPVOID)hModule, headerSize, PAGE_EXECUTE_READWRITE, &oldProtect))
    {
        std::cerr << "VirtualProtect failed with error code: " << GetLastError() << std::endl;
        return;
    }

   
    memset((LPVOID)hModule, 0, headerSize);


    if (!VirtualProtect((LPVOID)hModule, headerSize, oldProtect, &oldProtect))
    {
        std::cerr << "VirtualProtect failed with error code: " << GetLastError() << std::endl;
        return;
    }
}

int main()
{
    // Get the base address of the application
    HMODULE hModule = GetModuleHandle(NULL);
    if (hModule == NULL)
    {
        std::cerr << "GetModuleHandle failed with error code: " << GetLastError() << std::endl;
        return 1;
    }

    // Erase the PE header
    ErasePEHeader(hModule);
    return 0;
}


//////////////////////////////////////////
// End.
//////////////////////////////////////////
