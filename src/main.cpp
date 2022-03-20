// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include <commdlg.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ImGuiFileDialog.h"
#include "menu.h"
#include "imgui/imgui_internal.h"



// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//cfg
static char path[300] = "";
static char edit[32000] = "";
static char editstyle[16000] = "";
static char credit[128] = "ImConfigManager made by viwas45hu978ot"; 
std::string multiline;
std::string multilinestyle;

// Main code
int main(int, char**)
{

    std::ifstream readPathFile("path.txt");
    std::string line;
    if (readPathFile.is_open()) {
        std::string line;
        while (std::getline(readPathFile, line)) {
            strcpy_s(path, line.c_str());
        }
        readPathFile.close();
    }


    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    
    //HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("ImConfigManager"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX, 100, 100, 910, 600, NULL, NULL, wc.hInstance, NULL);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("ImConfigManager"), WS_EX_TRANSPARENT, 100, 100, 910, 600, NULL, NULL, wc.hInstance, NULL);
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 255, LWA_ALPHA);
    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;




    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.00f);



    std::ifstream t("style.toml");
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    strcpy_s(editstyle, str.c_str());
    // Main loop
    bool done = false;
    while (!done)
    {

        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();




        {
           
            //ImGui::SetNextWindowSize(ImVec2(900, 600));
            ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("Hello, world!", &show_demo_window, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
            //ImGui::StyleLoader::LoadFile("style.toml");
            //my stuff



            if (ImGui::Button("Browse"))
                ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cfg,.txt", ".");

            // display
            if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
            {
                // action if OK
                if (ImGuiFileDialog::Instance()->IsOk())
                {
                    std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

                    // action
                    strcpy_s(path, filePathName.c_str());              
                    
                    std::ifstream t(path);
                    std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());
                    strcpy_s(edit, str.c_str());
                }

                // close
                ImGuiFileDialog::Instance()->Close();
            }
            
            ImGui::SameLine();
            ImGui::PushItemWidth(-1);
            ImGui::InputText("     path", path, IM_ARRAYSIZE(path));

            if (ImGui::Button("Save"))
            {
                std::ofstream editFile(path);
                editFile << edit;
                editFile.close();
            }
            ImGui::SameLine();
            if (ImGui::Button("reload file"))
            {
                std::ifstream t(path);
                std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
                strcpy_s(edit, str.c_str());
            }
            ImGui::SameLine();
            ImGui::PushItemWidth(-300);



            ImGui::SameLine();
            ImGui::PushItemWidth(-140);
            static int style_idx = 0;
            if (ImGui::Combo("Style", &style_idx, "Dark\0Light\0Classic\0Red\0Green\0Blue\0Glass\0Custom\0"))
            {
                switch (style_idx)
                {
                case 0: settings::color = "Dark"; break;
                case 1: settings::color = "Light"; break;
                case 2: settings::color = "Classic"; break;
                case 3: settings::color = "Red"; break;
                case 4: settings::color = "Green"; break;
                case 5: settings::color = "Ocean"; break;
                case 6: settings::color = "Glass"; break;
                case 7: settings::color = "Custom"; break;
                }
                std::cout << settings::color;
                theme();
            }
            ImGui::SameLine();
            if (ImGui::Button("Style Editor"))
            {
                settings::style = !settings::style;
            }

            ImGui::PushItemWidth(-1);
            ImGui::InputTextMultiline("", edit, IM_ARRAYSIZE(edit),ImVec2(0,-23));
            
            if (ImGui::Button("About"))
            {
                settings::about = !settings::about;
            }
            if (settings::about)
            {
                ImGui::SetNextWindowSize(ImVec2(300, 100));
                ImGui::Begin("About", &settings::about, ImGuiWindowFlags_NoResize);
                ImGui::Text("Made by viwas45hu978ot using Dear ImGui");
                ImGui::Text("Github");
            }

            if (settings::style)
            {
                ImGui::SetNextWindowSize(ImVec2(500, 400));
                ImGui::Begin("Style Editor", &settings::style);
                if (ImGui::Button("Save")) {

                    std::ofstream StyleFile("style.toml");
                    StyleFile << editstyle;
                    StyleFile.close();
                }
                ImGui::SameLine();
                if (ImGui::Button("Load"))
                {
                    std::ifstream t("style.toml");
                    std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());
                    strcpy_s(editstyle, str.c_str());
                }
                ImGui::PushItemWidth(-1);
                ImGui::InputTextMultiline("       ", editstyle, IM_ARRAYSIZE(editstyle), ImVec2(0, -2));


                settings::color = "Custom";
                theme();
            }

            ImGui::End();
        }



        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * clear_color.w * 255.0f), (int)(clear_color.y * clear_color.w * 255.0f), (int)(clear_color.z * clear_color.w * 255.0f), (int)(clear_color.w * 255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
    std::ofstream pathFile("path.txt");
    pathFile << path;
    pathFile.close();
    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:

        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}