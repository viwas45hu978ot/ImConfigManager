/*
Copyright (c) 2022, viwas45hu978ot
All rights reserved.
*/

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"

//#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ImGuiFileDialog.h"
#include "menu.h"
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include "GLFW/glfw3.h"
#include "discord/discord.h"


//cfg
static char path[300] = "";
static char edit[320000] = "";
static char editstyle[16000] = "";
static char credit[128] = "ImConfigManager made by viwas45hu978ot";
std::string multiline;
std::string multilinestyle;

struct DiscordState {
    discord::User currentUser;

    std::unique_ptr<discord::Core> core;
};


// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main(int, char**)
{
    //discord
    DiscordState state{};

    discord::Core* core{};
    auto result = discord::Core::Create(955129964850737193, DiscordCreateFlags_NoRequireDiscord, &core);
    state.core.reset(core);
    if (!state.core) {
        std::cout << "Failed to instantiate discord core! (err " << static_cast<int>(result)
            << ")\n";
        std::exit(-1);
    }



    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    

    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImConfigManager", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.00f);


    std::ifstream readPathFile("path.txt");
    std::string line;
    if (readPathFile.is_open()) {
        std::string line;
        while (std::getline(readPathFile, line)) {
            strcpy_s(path, line.c_str());
        }
        readPathFile.close();
    }

    std::ifstream t("style.toml");
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    strcpy_s(editstyle, str.c_str());

    //discord
    discord::Activity activity{};
    activity.SetApplicationId(955129964850737193);
    activity.SetDetails("Editing Configs");
    activity.SetState("https://github.com/viwas45hu978ot/ImConfigManager");
    activity.SetType(discord::ActivityType::Playing);
    state.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
        std::cout << ((result == discord::Result::Ok) ? "Succeeded" : "Failed")
            << " updating activity!\n";
        });
    
    state.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
        std::cout << ((result == discord::Result::Ok) ? "Succeeded" : "Failed")
            << " updating activity!\n";
        });



    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        //imgui

        

                  //ImGui::SetNextWindowSize(ImVec2(900, 600));
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("Hello, world!", &show_demo_window, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
        
        //ImGui::StyleLoader::LoadFile("style.toml");
        //my stuff
        state.core->RunCallbacks();


        if (ImGui::Button("Browse"))
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cfg,.txt,.conf", ".");

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
        ImGui::InputTextMultiline("", edit, IM_ARRAYSIZE(edit), ImVec2(0, -23));

        if (ImGui::Button("About"))
        {
            settings::about = !settings::about;
        }
        if (settings::about)
        {
            ImGui::SetNextWindowSize(ImVec2(400, 100));
            ImGui::Begin("About", &settings::about, ImGuiWindowFlags_NoResize);
            ImGui::Text("Made by viwas45hu978ot using Dear ImGui");
            ImGui::Text("https://github.com/viwas45hu978ot/ImConfigManager");

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









        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        // If you are using this code with non-legacy OpenGL header/contexts (which you should not, prefer using imgui_impl_opengl3.cpp!!),
        // you may need to backup/reset/restore other state, e.g. for current shader using the commented lines below.
        //GLint last_program;
        //glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
        //glUseProgram(0);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        //glUseProgram(last_program);

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    std::ofstream pathFile("path.txt");
    pathFile << path;
    pathFile.close();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}