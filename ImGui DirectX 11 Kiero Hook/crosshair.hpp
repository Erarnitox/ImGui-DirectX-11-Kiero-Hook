#pragma once

#include "includes.h"

//ChatGPT generated code: (thanks chad gippidy!)
void RenderCrosshair(ImVec2 screen_size) {
    // Disable ImGui's window background and decorations
    ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0)); // Transparent background
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);     // No border
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0)); // No padding
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);      // No corner rounding

    ImGui::Begin("Crosshair", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                                      ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoInputs);

    // Calculate center of the screen
    ImVec2 center = ImVec2(screen_size.x * 0.5f, screen_size.y * 0.5f);

    // Crosshair dimensions
    float crosshairSize = 10.0f; // Length of each arm of the crosshair
    float thickness = 2.0f;     // Thickness of the crosshair lines
    ImU32 color = IM_COL32(255, 0, 0, 255); // Red color

    // Draw horizontal line
    ImGui::GetWindowDrawList()->AddLine(
        ImVec2(center.x - crosshairSize, center.y), 
        ImVec2(center.x + crosshairSize, center.y), 
        color, thickness);

    // Draw vertical line
    ImGui::GetWindowDrawList()->AddLine(
        ImVec2(center.x, center.y - crosshairSize), 
        ImVec2(center.x, center.y + crosshairSize), 
        color, thickness);

    ImGui::End();
    ImGui::PopStyleVar(3);
    ImGui::PopStyleColor(1);
}