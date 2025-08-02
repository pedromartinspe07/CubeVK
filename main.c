#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>  // usleep
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#include "render/vulkan_init.h"

static volatile bool running = true;

void handle_sigint(int sig) {
    (void)sig; // evitar warning unused
    running = false;
}

int main() {
    // Captura Ctrl+C para sair do loop de forma limpa
    signal(SIGINT, handle_sigint);

    if (init_vulkan() != 0) {
        fprintf(stderr, "Erro ao iniciar Vulkan\n");
        return 1;
    }

    printf("Vulkan iniciado com sucesso! Pressione Ctrl+C para sair.\n");

    // Loop básico do jogo
    while (running) {
        // Aqui você deve chamar as funções de update e render
        // Exemplo: update(); render();

        // Evitar consumir 100% da CPU (ajuste conforme necessário)
        SLEEP(16); // ~60 FPS
    }

    cleanup_vulkan();

    printf("Programa finalizado.\n");
    return 0;
}
