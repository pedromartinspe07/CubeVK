#ifndef CHUNK_H
#define CHUNK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "block.h" // Deve definir Block e BlockType

#define CHUNK_SIZE 16

// Estrutura que representa um chunk 3D de blocos
typedef struct Chunk {
    Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
} Chunk;

/**
 * Gera os blocos dentro do chunk (ex: terreno inicial).
 * @param chunk Ponteiro para o chunk a ser gerado.
 */
void generate_chunk(Chunk* chunk);

/**
 * Remove um bloco em uma posição específica do chunk.
 * @param chunk Ponteiro para o chunk.
 * @param x Coordenada X (0 <= x < CHUNK_SIZE).
 * @param y Coordenada Y (0 <= y < CHUNK_SIZE).
 * @param z Coordenada Z (0 <= z < CHUNK_SIZE).
 */
void break_block(Chunk* chunk, int x, int y, int z);

/**
 * Coloca um bloco do tipo especificado em uma posição do chunk.
 * @param chunk Ponteiro para o chunk.
 * @param x Coordenada X (0 <= x < CHUNK_SIZE).
 * @param y Coordenada Y (0 <= y < CHUNK_SIZE).
 * @param z Coordenada Z (0 <= z < CHUNK_SIZE).
 * @param type Tipo do bloco a ser colocado.
 */
void place_block(Chunk* chunk, int x, int y, int z, BlockType type);

#ifdef __cplusplus
}
#endif

#endif // CHUNK_H
