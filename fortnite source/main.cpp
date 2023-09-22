#ifndef MAIN_CPP
#define MAIN_CPP

#include "stdafx.hpp"
#include <Windows.h>







constexpr long kConsoleStyle = WS_EX_TOOLWINDOW;
constexpr int kConsoleColor1 = 70;
constexpr int kConsoleColor2 = 78;
void __cdecl Sync_all(void*)
{
    while (true)
    {
      
        GetEntity();
        //GetWeapon();
        //GetWeaponCache();
        //pre_start_ploop();
        //loop_loot();
      
    }
  

}




DWORD GetProcessId(LPCWSTR processName) {
    HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    DWORD procID = NULL;

    if (handle == INVALID_HANDLE_VALUE)
        return procID;

    PROCESSENTRY32W entry = { 0 };
    entry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(handle, &entry)) {
        if (!_wcsicmp(processName, entry.szExeFile)) {
            procID = entry.th32ProcessID;
        }
        else while (Process32NextW(handle, &entry)) {
            if (!_wcsicmp(processName, entry.szExeFile)) {
                procID = entry.th32ProcessID;
            }
        }
    }

    CloseHandle(handle);
    return procID;
}

bool isProcessRunning(const char* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe32)) {
        CloseHandle(hSnapshot);
        return false;
    }

    while (Process32Next(hSnapshot, &pe32)) {
        if (_stricmp(pe32.szExeFile, processName) == 0) {
            CloseHandle(hSnapshot);
            return true;
        }
    }

    CloseHandle(hSnapshot);
    return false;
}


struct HandleDisposer
{
    using pointer = HANDLE;
    void operator()(HANDLE handle) const
    {
        if (handle != NULL || handle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(handle);
        }
    }
};
using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;

static std::uint32_t _GetProcessId(std::string process_name) {
    PROCESSENTRY32 processentry;
    const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

    if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
        return 0;

    processentry.dwSize = sizeof(MODULEENTRY32);

    while (Process32Next(snapshot_handle.get(), &processentry) == TRUE) {
        if (process_name.compare(processentry.szExeFile) == 0)
            return processentry.th32ProcessID;
    }
    return 0;
}

void displayErrorMessage() {
   
    const char* errorMessage = _XOR_("Error : EAC (Easy Anti-Cheat) detected in your game !\nPlay on BE (BattleEye)");
    MessageBox(NULL, errorMessage, _XOR_("AC DETECTION"), MB_OK | MB_ICONERROR);
    system(_XOR_("taskkill /f /im FortniteClient-Win64-Shipping.exe"));
    exit(0);
}



auto main() -> int {

    SetConsoleTitleA(_XOR_("같같같같같같같같같같같같같같같같같같같같같같같같같같�"));
  
        
            Controller::XboxController* Player1 = new Controller::XboxController(1);
            MouseController::Init();


             
            //DriverVar::ProcID = _GetProcessId("FortniteClient-Win64-Shipping.exe");
        


            ctx->initialize();
            DriverVar::ProcID = GetProcessId(_XOR_(L"FortniteClient-Win64-Shipping.exe"));
            ctx->attach(DriverVar::ProcID);
            DriverVar::module = ctx->get_process_base();

            std::cout << "R0NDOMIZE" << DriverVar::module;
           /* if (driver->Init(FALSE)) {
                driver->Attach(DriverVar::ProcID);
                DriverVar::module = driver->GetModuleBase(L"FortniteClient-Win64-Shipping.exe");
            };*/
        

            if (!DriverVar::module)
            {
                Beep(100, 100);
            }
            SetupWindow();
            DirectXInit(MyWnd);

            HANDLE handle = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Sync_all, nullptr, NULL, nullptr);

   /*         _beginthread(bone_exploit, 0, bone_exploit);
            _beginthread(loop_exploit, 0, loop_exploit);*/



            if (handle) {
                CloseHandle(handle);
            }

           MainLoop();
        
}

#endif // !MAIN_CPP