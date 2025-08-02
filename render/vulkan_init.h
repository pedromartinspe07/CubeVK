#ifndef VULKAN_INIT_H
#define VULKAN_INIT_H

#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Inicializa a instância Vulkan, dispositivos e outros recursos necessários.
 * @return 0 em sucesso, valor negativo em erro.
 */
int init_vulkan();

/**
 * Libera recursos alocados pela Vulkan (device, instância, etc).
 */
void cleanup_vulkan();

// Instância Vulkan global (inicializada em vulkan_init.c)
extern VkInstance instance;

// Dispositivo lógico Vulkan global
extern VkDevice device;

#ifdef __cplusplus
}
#endif

#endif // VULKAN_INIT_H
