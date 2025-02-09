#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "config.h"

int main() {
    toml_table_t* conf = config_load("config.toml");
    if (conf == NULL) {
        return 1;
    }
    toml_table_t* theme = toml_table_in(conf, "theme");
    if (!theme) {
        fprintf(stderr, "missing [theme]\n");
        return 1;
    }
    toml_datum_t font = toml_string_in(theme, "font");
    if (!font.ok) {
        fprintf(stderr, "cannot read theme.font\n");
        return 1;
    }
    float clear_color[4] = {0.0, 0.0f, 0.0f, 1.00f};
    toml_array_t* backdrop_array = toml_array_in(theme, "backdrop");
    if (!backdrop_array) {
        fprintf(stderr, "cannot read theme.backdrop\n");
        return 1;
    }
    for (int i = 0; i<4; i++) {
        toml_datum_t c = toml_int_at(backdrop_array, i);
        // if (!c.ok){
        //     fprintf(stderr, "cannot read theme.backdrop\n");
        //     return 1;
        // }
        clear_color[i] = (float)c.u.d;
    }

    printf("theme.font: %s\n", font.u.s);
    printf("theme.backdrop: { %f, %f, %f, %f }\n", clear_color[0], clear_color[1], clear_color[2], clear_color[3]);

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(1280, 800, "joytrack", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    int counter = 0;


    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some useful text.");
        if (ImGui::Button("Button")) {
            counter++;
        }
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);
        ImGui::ColorEdit3("clear color", clear_color);
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
