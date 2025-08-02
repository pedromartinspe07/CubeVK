#include "block.h"

// Função para retornar se o bloco é transparente (pode evoluir futuramente)
int is_block_transparent(BlockType type) {
    switch (type) {
        case BLOCK_AIR:
            return 1;
        default:
            return 0;
    }
}

// Função para obter o nome do bloco (útil para debug ou HUD futuramente)
const char* get_block_name(BlockType type) {
    switch (type) {
        case BLOCK_AIR: return "Ar";
        case BLOCK_GRASS: return "Grama";
        case BLOCK_DIRT: return "Terra";
        case BLOCK_STONE: return "Pedra";
        default: return "Desconhecido";
    }
}
