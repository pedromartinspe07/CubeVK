#ifndef RENDERER_H
#define RENDERER_H

#include "../world/chunk.h"  // ajuste o caminho conforme a estrutura do seu projeto

/**
 * Desenha o chunk fornecido na cena.
 * 
 * @param chunk Ponteiro para o chunk a ser desenhado.
 */
void draw_chunk(const Chunk* chunk);

/**
 * Atualiza a posição e orientação da câmera no renderer.
 * 
 * (Pode receber parâmetros no futuro, por exemplo posição da câmera)
 */
void update_camera(void);

#endif // RENDERER_H
