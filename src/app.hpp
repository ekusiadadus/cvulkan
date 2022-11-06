#ifndef APP_HPP
#define APP_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>

const std::vector<char*> validationLayers = {
    "VK_LAYER_LUNARG_standard_validation"
};

class App{
  public:
    void run();
  private:
    void initWindow();
    GLFWwindow *window;
    
    void mainLoop();
    
    void initVulkan();

    void cleanup();

    void createInstance();
    VkInstance instance;

    std::vector<const char*> getRequiredExtensions();
    bool checkValidationLayerSupport();
};

#endif
