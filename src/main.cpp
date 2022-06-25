#include "common.hpp"

int main()
{
    using namespace mezmerizxd;

    HANDLE g_main_thread = CreateThread(NULL, 0, [](LPVOID lpParameter) -> DWORD
        {
            g_mezmerizxd.Init();

            while (g_running) {
                if (GetAsyncKeyState(VK_END))
                    g_running = false;
                g_mezmerizxd.Update();
                std::this_thread::sleep_for(250ms);
            }

            return 0;
        }, NULL, 0, NULL);

    if (g_main_thread == NULL)
    {
        return 1;
    }

    WaitForSingleObject(g_main_thread, INFINITE);
    CloseHandle(g_main_thread);

    std::cout << "Thread Closed, now exiting...";

    return 0;
}