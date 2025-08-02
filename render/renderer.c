#include "renderer.h"
#include <stdbool.h>
#include <stdio.h>  // para printf

// Enum para as faces do bloco
typedef enum {
    FACE_TOP,
    FACE_BOTTOM,
    FACE_FRONT,
    FACE_BACK,
    FACE_LEFT,
    FACE_RIGHT
} Face;

// Função de desenho stub para uma face do bloco
static void draw_face(int x, int y, int z, Face face) {
    const char* face_names[] = {
        "TOP", "BOTTOM", "FRONT", "BACK", "LEFT", "RIGHT"
    };
    printf("Desenhando face %s do bloco em (%d, %d, %d)\n", face_names[face], x, y, z);
}

// Verifica se o bloco é ar
static bool is_air(Block block) {
    return block.type == BLOCK_AIR;
}

// Verifica se a posição está dentro dos limites do chunk
static bool is_in_bounds(int x, int y, int z) {
    return (x >= 0 && x < CHUNK_SIZE &&
            y >= 0 && y < CHUNK_SIZE &&
            z >= 0 && z < CHUNK_SIZE);
}

/**
 * Renderiza as faces visíveis do chunk.
 * Apenas as faces que estão adjacentes a blocos de ar são desenhadas.
 */
void draw_chunk(const Chunk* chunk) {
    if (!chunk) return;

    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                Block block = chunk->blocks[x][y][z];

                if (is_air(block)) {
                    continue; // Não renderiza blocos de ar
                }

                // Checar cada face para decidir se deve desenhar
                if (!is_in_bounds(x, y + 1, z) || is_air(chunk->blocks[x][y + 1][z])) {
                    draw_face(x, y, z, FACE_TOP);
                }
                if (!is_in_bounds(x, y - 1, z) || is_air(chunk->blocks[x][y - 1][z])) {
                    draw_face(x, y, z, FACE_BOTTOM);
                }
                if (!is_in_bounds(x, y, z + 1) || is_air(chunk->blocks[x][y][z + 1])) {
                    draw_face(x, y, z, FACE_FRONT);
                }
                if (!is_in_bounds(x, y, z - 1) || is_air(chunk->blocks[x][y][z - 1])) {
                    draw_face(x, y, z, FACE_BACK);
                }
                if (!is_in_bounds(x - 1, y, z) || is_air(chunk->blocks[x - 1][y][z])) {
                    draw_face(x, y, z, FACE_LEFT);
                }
                if (!is_in_bounds(x + 1, y, z) || is_air(chunk->blocks[x + 1][y][z])) {
                    draw_face(x, y, z, FACE_RIGHT);
                }
            }
        }
    }
}
