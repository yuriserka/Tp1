#ifndef TRABALHO__INC__H__
#define TRABALHO__INC__H__

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

#include <bits/stdc++.h>

#include "dominios.h"
#include "entidades.h"
#include "auxiliares.h"
#include "sqlite3.h"
#include "sql.h"
#include "teste-dominios.h"
#include "teste-entidades.h"
#include "testes.h"
#include "interfaces.h"
#include "comandos.h"
#include "servicos.h"
//#include "stubs.h"
#include "controladores.h"

#endif //TRABALHO__INC__H__