// Handles11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/

#include <iostream>
#include <windows.h>
#include <winternl.h>
#pragma comment(lib, "ntdll.lib")
void ParseAccessMask(ACCESS_MASK accessMask) {
    if ((accessMask & GENERIC_READ) == GENERIC_READ) std::cout << "GENERIC_READ ";
    if ((accessMask & GENERIC_WRITE) == GENERIC_WRITE) std::cout << "GENERIC_WRITE ";
    if ((accessMask & GENERIC_EXECUTE) == GENERIC_EXECUTE) std::cout << "GENERIC_EXECUTE ";
    if ((accessMask & GENERIC_ALL) == GENERIC_ALL) std::cout << "GENERIC_ALL ";
    if ((accessMask & PROCESS_CREATE_PROCESS) == PROCESS_CREATE_PROCESS) std::cout << "PROCESS_CREATE_PROCESS ";
    if ((accessMask & PROCESS_TERMINATE) == PROCESS_TERMINATE) std::cout << "PROCESS_TERMINATE ";
    if ((accessMask & PROCESS_SUSPEND_RESUME) == PROCESS_SUSPEND_RESUME) std::cout << "PROCESS_SUSPEND_RESUME ";
    if ((accessMask & PROCESS_QUERY_INFORMATION) == PROCESS_QUERY_INFORMATION) std::cout << "PROCESS_QUERY_INFORMATION ";
    if ((accessMask & PROCESS_SET_INFORMATION) == PROCESS_SET_INFORMATION) std::cout << "PROCESS_SET_INFORMATION ";
    std::cout << std::endl;
}
int main() {
    HANDLE hProcess = GetCurrentProcess();
    ULONG returnLength = 0;
    PUBLIC_OBJECT_BASIC_INFORMATION obi;
    NTSTATUS status = NtQueryObject(
        hProcess,
        ObjectBasicInformation,
        &obi,
        sizeof(obi),
        &returnLength);
    if (NT_SUCCESS(status)) {
        std::cout << "Granted Access: " << std::hex << obi.GrantedAccess << std::endl;
        ParseAccessMask(obi.GrantedAccess);
    }
    else {
        std::cerr << "NtQueryObject failed with status: " << std::hex << status << std::endl;
    }
    CloseHandle(hProcess);
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
