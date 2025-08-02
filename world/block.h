#ifndef BLOCK_H
#define BLOCK_H

typedef enum {
    BLOCK_AIR,
    BLOCK_GRASS,
    BLOCK_DIRT,
    BLOCK_STONE
    // Adicione mais blocos aqui
} BlockType;

typedef struct {
    BlockType type;
    // Futuramente: textura, resistência, etc.
} Block;

int is_block_transparent(BlockType type);
const char* get_block_name(BlockType type);

#endif
