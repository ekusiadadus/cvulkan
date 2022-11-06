#include"app.hpp"

void App::run() {
  initWindow();
  initVulkan();
  mainLoop();
}


void App::initVulkan(){
    createInstance();
}

void App::createInstance(){
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "CVulkan";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;
  createInfo.flags = 0;
  createInfo.enabledLayerCount = 0;
  createInfo.enabledExtensionCount = 0;

  if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS){
    throw std::runtime_error("failed to create instance!");
  }
}

void App::cleanup(){
  glfwDestroyWindow(window);
  glfwTerminate();
}

void App::mainLoop() {
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}

void App::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window = glfwCreateWindow(800, 600, "Vulkan", nullptr, nullptr);
}

std::vector<const char*> App::getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

  return extensions;
}

bool App::checkValidationLayers(){
  for(const auto& layerName : validationLayers){
    bool layerFound = false;
    for(const auto& layerProperties : availableLayers){
      if(strcmp(layerName, layerProperties.layerName) == 0){
        layerFound = true;
        break;
      }
    }
    if(!layerFound){
      return false;
    }
  }
  return true;
}



