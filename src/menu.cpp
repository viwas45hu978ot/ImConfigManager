/*
Copyright (c) 2022, viwas45hu978ot
All rights reserved.
*/



#include <string>
#include "menu.h"
#include <iostream>
#include "imgui/imgui.h"
#include "imguistyleloader.h"

void menu()
{

}

void theme()
{
	if (settings::color == "Dark")
		ImGui::StyleColorsDark();
	else if (settings::color == "Light")
		ImGui::StyleColorsLight();
	else if (settings::color == "Classic")
		ImGui::StyleColorsClassic();
	else if (settings::color == "Red")
	{
		ImGuiStyle& style = ImGui::GetStyle();

		style.FrameRounding = 0.f;
		style.WindowRounding = 0.f;

		style.Colors[ImGuiCol_TableHeaderBg] = ImColor(255, 0, 0, 80);
		style.Colors[ImGuiCol_TableRowBg] = ImColor(0, 0, 0, 0);
		style.Colors[ImGuiCol_TableRowBgAlt] = ImColor(255, 0, 0, 18);

		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);

		style.Colors[ImGuiCol_Button] = ImColor(155, 0, 0, 255);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(155, 86, 86, 255);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(155, 86, 86, 255);

		style.Colors[ImGuiCol_FrameBg] = ImColor(155, 0, 0, 255);
		style.Colors[ImGuiCol_FrameBgHovered] = ImColor(110, 0, 0, 255);

		style.Colors[ImGuiCol_TitleBg] = ImColor(110, 0, 0, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(110, 0, 0, 255);

		style.Colors[ImGuiCol_HeaderHovered] = ImColor(110, 0, 0, 255);
		style.Colors[ImGuiCol_HeaderActive] = ImColor(155, 0, 0, 255);
		style.Colors[ImGuiCol_Header] = ImColor(155, 0, 0, 255);

		style.Colors[ImGuiCol_ResizeGrip] = ImColor(155, 0, 0, 255);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(110, 0, 0, 255);
		style.Colors[ImGuiCol_ResizeGripActive] = ImColor(110, 0, 0, 255);

		style.Colors[ImGuiCol_Separator] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorActive] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorHovered] = ImColor(1, 1, 1, 0);
	}
	else if (settings::color == "Green")
	{
		ImGuiStyle& style = ImGui::GetStyle();

		style.FrameRounding = 0.f;
		style.WindowRounding = 0.f;

		style.Colors[ImGuiCol_TableHeaderBg] = ImColor(0, 255, 0, 80);
		style.Colors[ImGuiCol_TableRowBg] = ImColor(0, 0, 0, 0);
		style.Colors[ImGuiCol_TableRowBgAlt] = ImColor(0, 255, 0, 18);

		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);

		style.Colors[ImGuiCol_Button] = ImColor(0, 155, 0, 255);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(86, 155, 86, 255);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(86, 155, 86, 255);

		style.Colors[ImGuiCol_FrameBg] = ImColor(0, 155, 0, 255);
		style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 110, 0, 255);
		style.Colors[ImGuiCol_FrameBgHovered] = ImColor(0, 110, 0, 255);

		style.Colors[ImGuiCol_TitleBg] = ImColor(0, 110, 0, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 110, 0, 255);

		style.Colors[ImGuiCol_HeaderHovered] = ImColor(0, 110, 0, 255);
		style.Colors[ImGuiCol_HeaderActive] = ImColor(0, 155, 0, 255);
		style.Colors[ImGuiCol_Header] = ImColor(0, 155, 0, 255);

		style.Colors[ImGuiCol_ResizeGrip] = ImColor(0, 155, 0, 255);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(0, 110, 0, 255);
		style.Colors[ImGuiCol_ResizeGripActive] = ImColor(0, 110, 0, 255);

		style.Colors[ImGuiCol_Separator] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorActive] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorHovered] = ImColor(1, 1, 1, 0);
	}
	else if (settings::color == "Ocean")
	{
		ImGuiStyle& style = ImGui::GetStyle();

		style.FrameRounding = 0.f;
		style.WindowRounding = 0.f;

		style.Colors[ImGuiCol_TableHeaderBg] = ImColor(80, 200, 255, 80);
		style.Colors[ImGuiCol_TableRowBg] = ImColor(0, 0, 0, 0);
		style.Colors[ImGuiCol_TableRowBgAlt] = ImColor(80, 200, 255, 18);

		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.16f, 0.94f);

		style.Colors[ImGuiCol_Button] = ImColor(60, 160, 215, 255);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(100, 200, 235, 255);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(100, 200, 235, 255);

		style.Colors[ImGuiCol_FrameBg] = ImColor(60, 160, 215, 255);
		style.Colors[ImGuiCol_FrameBgActive] = ImColor(100, 200, 235, 255);
		style.Colors[ImGuiCol_FrameBgHovered] = ImColor(100, 200, 235, 255);

		style.Colors[ImGuiCol_TitleBg] = ImColor(60, 160, 215, 200);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(100, 200, 235, 200);

		style.Colors[ImGuiCol_HeaderHovered] = ImColor(100, 200, 235, 255);
		style.Colors[ImGuiCol_HeaderActive] = ImColor(100, 200, 235, 255);
		style.Colors[ImGuiCol_Header] = ImColor(60, 160, 215, 255);

		style.Colors[ImGuiCol_ResizeGrip] = ImColor(60, 160, 215, 255);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(100, 200, 235, 255);
		style.Colors[ImGuiCol_ResizeGripActive] = ImColor(100, 200, 235, 255);

		style.Colors[ImGuiCol_Separator] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorActive] = ImColor(1, 1, 1, 0);
		style.Colors[ImGuiCol_SeparatorHovered] = ImColor(1, 1, 1, 0);
	}
	else if (settings::color == "Glass")
	{
	ImGuiStyle& style = ImGui::GetStyle();

	style.FrameRounding = 5.f;
	style.WindowRounding = 5.f;
	
	style.Colors[ImGuiCol_TableHeaderBg] = ImColor(200, 200, 205, 80);
	style.Colors[ImGuiCol_TableRowBg] = ImColor(0, 0, 0, 0);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImColor(200, 200, 205, 18);

	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.44f);
	style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.26f, 0.50f);

	style.Colors[ImGuiCol_Button] = ImColor(110, 110, 115, 170);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(140, 140, 155, 170);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(140, 140, 155, 170);

	style.Colors[ImGuiCol_FrameBg] = ImColor(110, 110, 115, 170);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(140, 140, 155, 170);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(140, 140, 155, 170);

	style.Colors[ImGuiCol_TitleBg] = ImColor(110, 110, 115, 170);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(140, 140, 155, 170);

	style.Colors[ImGuiCol_HeaderHovered] = ImColor(200, 200, 205, 170);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(200, 200, 205, 170);
	style.Colors[ImGuiCol_Header] = ImColor(110, 110, 115, 170);

	style.Colors[ImGuiCol_ResizeGrip] = ImColor(110, 110, 115, 170);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(140, 140, 155, 170);
	style.Colors[ImGuiCol_ResizeGripActive] = ImColor(140, 140, 155, 170);

	style.Colors[ImGuiCol_Separator] = ImColor(1, 1, 1, 0);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(1, 1, 1, 0);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(1, 1, 1, 0);
	}
	else if (settings::color == "Custom")
	{
	
	ImStyle::StyleLoader::LoadFile("style.toml");
	}

}