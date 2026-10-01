/*
 * @file ce_01_cores.c
 * @brief cores.
 * @author Douglas Bonilla 
 * @date 20/09/2026
 */



#include <stdio.h>
#include <windows.h>

int main() {
    SYSTEM_INFO sysInfo;

    GetSystemInfo(&sysInfo);

    printf("========================================\n");
    printf(" RECURSOS DEL PROCESADOR\n");
    printf("========================================\n\n");

    printf("Procesadores logicos: %lu\n",
           sysInfo.dwNumberOfProcessors);

    printf("\nNota:\n");
    printf("- Los procesadores logicos son los hilos de ejecucion\n");
    printf("  que Windows puede utilizar.\n");
    printf("- Para conocer los cores fisicos se puede utilizar\n");
    printf("  PowerShell con el comando:\n\n");

    printf("Get-CimInstance Win32_Processor | ");
    printf("Select-Object NumberOfCores, NumberOfLogicalProcessors\n");

    return 0;
}