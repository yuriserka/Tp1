#pragma once

/**
 * @file includes.h
 * @author Yuri Serka e Thiago Matos
 * @date 19 de Abril de 2018
 * 
 * @brief todos os outros arquivos de cabeçalho se encontram aqui para facilitar
 * a inclusão.
 * 
 */

#ifdef _WIN32
/**
 * @brief comando de limpar a tela para windows
 * 
 */
#define CLEAR "cls"
/**
 * @brief comando para pausar o programa e esperar uma tecla ser pressioanda.
 * 
 */
#define PAUSE "pause"
#else
/**
 * @brief comando de limpar a tela para linux.
 * 
 */
#define CLEAR "clear"
/**
 * @brief comando para pausar o programa e esperar uma tecla ser pressionada.
 * 
 */
#define PAUSE "read -p \"Digite Enter para continuar...\" saindo"
#endif

using namespace std;