#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>
#include<iostream>
#include<vector>


int main() {
	glfwInit();
	
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan", nullptr, nullptr);

	uint32_t glfwExtensionCout = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCout);
	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCout);

	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = nullptr;
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_4;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();

	VkInstance instance = {};
	vkCreateInstance(&createInfo, nullptr, &instance);

	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	VkPhysicalDeviceProperties physicalDevice;
	for (const VkPhysicalDevice& device : devices)
	{
		vkGetPhysicalDeviceProperties(device, &physicalDevice);
	}

	while (glfwWindowShouldClose(window) == false) {
		glfwPollEvents();
	}
	

	return 1;
}