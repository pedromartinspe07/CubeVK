#include "player.h"
#include "chunk.h"  // para Chunk e CHUNK_SIZE
#include <stdbool.h>
#include <math.h>   // para floorf()

// Verifica se as coordenadas estão dentro dos limites do chunk
static bool is_in_chunk_bounds(int x, int y, int z) {
    return (x >= 0 && x < CHUNK_SIZE &&
            y >= 0 && y < CHUNK_SIZE &&
            z >= 0 && z < CHUNK_SIZE);
}

/**
 * Move o jogador pela cena, se a posição destino for livre (bloco ar).
 * 
 * @param player Ponteiro para o jogador a ser movido.
 * @param dx Deslocamento no eixo X.
 * @param dy Deslocamento no eixo Y.
 * @param dz Deslocamento no eixo Z.
 * @param chunk Ponteiro para o chunk onde o jogador está.
 */
void move_player(Player* player, float dx, float dy, float dz, Chunk* chunk) {
    if (!player || !chunk) return;  // valida ponteiros

    float newX = player->x + dx;
    float newY = player->y + dy;
    float newZ = player->z + dz;

    // Converte para inteiro usando floor para considerar a posição no bloco correto
    int blockX = (int)floorf(newX);
    int blockY = (int)floorf(newY);
    int blockZ = (int)floorf(newZ);

    if (is_in_chunk_bounds(blockX, blockY, blockZ)) {
        BlockType bt = chunk->blocks[blockX][blockY][blockZ].type;
        if (bt == BLOCK_AIR) {
            // Atualiza a posição do jogador
            player->x = newX;
            player->y = newY;
            player->z = newZ;
        }
        // Aqui poderia tratar colisões com outros tipos de bloco
    }
}
