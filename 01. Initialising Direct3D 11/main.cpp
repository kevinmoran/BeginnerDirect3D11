#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <d3d11_1.h>

#pragma comment(lib, "d3d11")
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
                                "01. Initialising Direct3D 11",
                                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                CW_USEDEFAULT, CW_USEDEFAULT,
                                initialWidth, 
                                initialHeight,
                                0, 0, hInstance, 0);

	if(!hwnd) {
        MessageBoxA(0, "CreateWindowEx failed", "Fatal Error", MB_OK);
		return GetLastError();
    }

    // Create D3D11 Device and Context
    ID3D11Device* baseDevice;
    ID3D11DeviceContext* baseDeviceContext;
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };

    HRESULT hResult = D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE, 
                                        0, D3D11_CREATE_DEVICE_BGRA_SUPPORT, 
                                        featureLevels, ARRAYSIZE(featureLevels), 
                                        D3D11_SDK_VERSION, &baseDevice, 
                                        0, &baseDeviceContext);
	if(FAILED(hResult)){
        MessageBoxA(0, "D3D11CreateDevice failed", "Fatal Error", MB_OK);
		return GetLastError();
    }
    
    // Get 1.1 interface of D3D11 Device and Context
    ID3D11Device1* d3d11Device;
    baseDevice->QueryInterface(__uuidof(ID3D11Device1), (void**)&d3d11Device);

    ID3D11DeviceContext1* d3d11DeviceContext;
    baseDeviceContext->QueryInterface(__uuidof(ID3D11DeviceContext1), (void**)&d3d11DeviceContext);

    // Get DXGI Adapter (needed to create Swap Chain)
    IDXGIDevice1* dxgiDevice;
    d3d11Device->QueryInterface(__uuidof(IDXGIDevice1), (void**)&dxgiDevice);

    IDXGIAdapter* dxgiAdapter;
    dxgiDevice->GetAdapter(&dxgiAdapter);

    IDXGIFactory2* dxgiFactory;
    dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), (void**)&dxgiFactory);

    // Create Swap Chain
    DXGI_SWAP_CHAIN_DESC1 d3d11SwapChainDesc;
    d3d11SwapChainDesc.Width = 0; // use window width
    d3d11SwapChainDesc.Height = 0; // use window height
    d3d11SwapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    d3d11SwapChainDesc.Stereo = FALSE;
    d3d11SwapChainDesc.SampleDesc.Count = 1;
    d3d11SwapChainDesc.SampleDesc.Quality = 0;
    d3d11SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    d3d11SwapChainDesc.BufferCount = 2;
    d3d11SwapChainDesc.Scaling = DXGI_SCALING_STRETCH;
    d3d11SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    d3d11SwapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
    d3d11SwapChainDesc.Flags = 0;

    IDXGISwapChain1* d3d11SwapChain;
    dxgiFactory->CreateSwapChainForHwnd(d3d11Device, hwnd, &d3d11SwapChainDesc, 0, 0, &d3d11SwapChain);

    // Create Framebuffer Render Target
    ID3D11Texture2D* d3d11FrameBuffer;
    d3d11SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&d3d11FrameBuffer);

    ID3D11RenderTargetView* d3dFrameBufferView;
    d3d11Device->CreateRenderTargetView(d3d11FrameBuffer, 0, &d3dFrameBufferView);

    // Main Loop
    global_isRunning = true;
    while(global_isRunning)
    {
        MSG message = {};
        while(PeekMessage(&message, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        FLOAT backgroundColor[4] = { 0.1f, 0.2f, 0.6f, 1.0f };
        d3d11DeviceContext->ClearRenderTargetView(d3dFrameBufferView, backgroundColor);

        d3d11SwapChain->Present(1, 0);
    }

	return 0;
}
