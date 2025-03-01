#include<GLFW/glfw3.h>

int main() {
	glfwInit();
	
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan", nullptr, nullptr);

	while (glfwWindowShouldClose(window) == false) {
		glfwPollEvents();
	}
	

	return 1;
}