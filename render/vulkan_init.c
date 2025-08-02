// vulkan_init.c
#include "vulkan_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

VkDevice device = VK_NULL_HANDLE;
VkInstance instance = VK_NULL_HANDLE;

int init_vulkan() {
    // 1. Informações da aplicação
    VkApplicationInfo appInfo = {0};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Minecraft Clone";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // 2. Info para criação da instância
    VkInstanceCreateInfo createInfo = {0};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    
    // Aqui você pode adicionar extensões e camadas se precisar
    createInfo.enabledExtensionCount = 0;
    createInfo.ppEnabledExtensionNames = NULL;
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = NULL;

    VkResult result = vkCreateInstance(&createInfo, NULL, &instance);
    if (result != VK_SUCCESS) {
        fprintf(stderr, "Falha ao criar instância Vulkan: %d\n", result);
        return -1;
    }

    // Aqui você criaria o dispositivo lógico, filas, swapchain, etc.
    // Como exemplo mínimo, vamos deixar só a instanciação.

    return 0;
}

void cleanup_vulkan() {
    if (device != VK_NULL_HANDLE) {
        vkDestroyDevice(device, NULL);
        device = VK_NULL_HANDLE;
    }

    if (instance != VK_NULL_HANDLE) {
        vkDestroyInstance(instance, NULL);
        instance = VK_NULL_HANDLE;
    }
}
