#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

typedef struct {
    float x, y, z;      // Posição do jogador no mundo
    float pitch, yaw;   // Rotação da câmera (vertical e horizontal)
} Player;

/**
 * Move o jogador no espaço 3D se a posição destino estiver livre.
 * 
 * @param player Ponteiro para o jogador.
 * @param dx Deslocamento no eixo X.
 * @param dy Deslocamento no eixo Y.
 * @param dz Deslocamento no eixo Z.
 * @param chunk Ponteiro para o chunk atual para verificar colisões.
 */
void move_player(Player* player, float dx, float dy, float dz, void* chunk);

#endif // PLAYER_H
