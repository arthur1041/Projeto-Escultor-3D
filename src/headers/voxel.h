/**
 * @file voxel.h
 * @brief Declaração da estrutura Voxel.
 * 
 * Este arquivo contém a definição da estrutura Voxel, que representa um elemento
 * básico em uma matriz tridimensional utilizada pela classe Sculptor.
 */

#ifndef VOXEL_H
#define VOXEL_H

/**
 * @struct Voxel
 * @brief Estrutura para representar um voxel.
 * 
 * Um voxel é um elemento tridimensional que compõe a matriz utilizada pelo
 * objeto Sculptor. Cada voxel contém informações sobre cor, transparência
 * e visibilidade.
 */
struct Voxel {
    float r; ///< Componente vermelha da cor (0-1).
    float g; ///< Componente verde da cor (0-1).
    float b; ///< Componente azul da cor (0-1).
    float a; ///< Transparência do voxel (0-1).
    bool show; ///< Indica se o voxel está ativo (true) ou inativo (false).
};

#endif // VOXEL_H
