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
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p \"Digite Enter para continuar...\" saindo"
#endif

using namespace std;

#include "bits/stdc++.h"

#include "dominios.h"
#include "entidades.h"
#include "auxiliares.h"
#include "teste-dominios.h"
#include "teste-entidades.h"
#include "testes.h"
#include "interfaces.h"
#include "comandos.h"
#include "stubs.h"
#include "controladores.h"

#endif //TRABALHO__INC__H__