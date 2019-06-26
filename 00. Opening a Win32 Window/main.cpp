#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

static bool global_isRunning = true;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    LRESULT result = 0;
    switch(msg)
    {
        case WM_KEYDOWN:
        {
            if(wparam == VK_ESCAPE)
                global_isRunning = false;
            break;
        }
        case WM_DESTROY:
        {
            global_isRunning = false;
            PostQuitMessage(0);
            break;
        }
        default:
            result = DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSEX winClass = {};
    winClass.cbSize = sizeof(WNDCLASSEX);
    winClass.style = CS_HREDRAW | CS_VREDRAW;
    winClass.lpfnWndProc = &WndProc;
    winClass.hInstance = hInstance;
    winClass.hIcon = LoadIcon(0, IDI_APPLICATION);
    winClass.hCursor = LoadCursor(0, IDC_ARROW);
    winClass.lpszClassName = "MyWindowClass";
    winClass.hIconSm = LoadIcon(0, IDI_APPLICATION);

    if(!RegisterClassEx(&winClass)) {
        MessageBoxA(0, "RegisterClassEx failed", "Fatal Error", MB_OK);
        return GetLastError();
    }

    RECT initialRect = { 0, 0, 1024, 768 };
    AdjustWindowRectEx(&initialRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_OVERLAPPEDWINDOW);
    LONG initialWidth = initialRect.right - initialRect.left;
    LONG initialHeight = initialRect.bottom - initialRect.top;

    HWND hwnd = CreateWindowEx( WS_EX_OVERLAPPEDWINDOW,
                                winClass.lpszClassName,
                                "00. Opening a Win32 Window",
                                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                CW_USEDEFAULT, CW_USEDEFAULT,
                                initialWidth, 
                                initialHeight,
                                0, 0, hInstance, 0);

    if(!hwnd) {
        MessageBoxA(0, "CreateWindowEx failed", "Fatal Error", MB_OK);
        return GetLastError();
    }

    global_isRunning = true;
    while(global_isRunning)
    {
        MSG message = {};
        while(PeekMessage(&message, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        Sleep(1);
    }

    return 0;
}
