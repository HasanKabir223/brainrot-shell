#include <stdio.h>
#include<windows.h>

int main(){

    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);
    
    char command[] = "Notepad.exe";

    printf("brainrot:");
    BOOL success = CreateProcessA(
        NULL,
        command,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    // waits for the child process (external program) to finish

    /*
    WaitForSingleObject is enabling the foreground execution - (waits)
    */
    // WaitForSingleObject(pi.hProcess, INFINITE);

    // we no longer need the reference of the process , so we just release it
    // CloseHandle(pi.hProcess);

    // we are also releasing the Thread along the process
    // CloseHandle(pi.hProcess);

    if (success) {
        printf("Process created!\n");
        printf("PID: %lu\n", pi.dwProcessId); // pi.dwProcessId gives the Process Id
    } 
    else {
        printf("Failed to create process.\n");
    }

    return 0;
}