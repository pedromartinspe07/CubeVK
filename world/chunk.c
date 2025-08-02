#include "chunk.h"
#include <stdlib.h>

void generate_chunk(Chunk* chunk) {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if (y == 0) {
                    chunk->blocks[x][y][z].type = BLOCK_STONE;
                } else if (y < 3) {
                    chunk->blocks[x][y][z].type = BLOCK_DIRT;
                } else if (y == 3) {
                    chunk->blocks[x][y][z].type = BLOCK_GRASS;
                } else {
                    chunk->blocks[x][y][z].type = BLOCK_AIR;
                }
            }
        }
    }
}

void break_block(Chunk* chunk, int x, int y, int z) {
    if (x >= 0 && x < CHUNK_SIZE &&
        y >= 0 && y < CHUNK_SIZE &&
        z >= 0 && z < CHUNK_SIZE) {
        chunk->blocks[x][y][z].type = BLOCK_AIR;
    }
}

void place_block(Chunk* chunk, int x, int y, int z, BlockType type) {
    if (x >= 0 && x < CHUNK_SIZE &&
        y >= 0 && y < CHUNK_SIZE &&
        z >= 0 && z < CHUNK_SIZE) {
        chunk->blocks[x][y][z].type = type;
    }
}
