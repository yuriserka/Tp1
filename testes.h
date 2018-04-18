#ifndef VOC_CTRL_TESTES_H_
#define VOC_CTRL_TESTES_H_

#include "unit-test-dominios.h"
#include "unit-test-entidades.h"

#include <iostream>

using namespace std;

/**
 * @file Testes.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de kAbril de 2018
 *
 * @brief Realizará os testes de unidade das classes de dominio e das entidades.
 *
 * Neste arquivo está listada a classe responsável por rodar todos os testes de unidade.
 * */

/**
 * @brief Executará todos os testes de unidade de cada classe do sistema até o momento.
 *
 */
class Teste {
  public:

    /**
     * @brief roda todos os testes de unidade dos Dominios e das Entidades que estão definidos nos arquivos
     *  TUEndidades e TUDominios.
     *
     */
    void Execute();

  private:
    TUNome *teste_unidade_nome_;
    TUSobrenome *teste_unidade_sobrenome_;
    TUSenha *teste_unidade_senha_;
    TUAddress *teste_unidade_endereco_;
    TUEmail *teste_unidade_email_;
    TUData *teste_unidade_data_;
    TUTelefone *teste_unidade_telefone_;
    TUTextoDefinicao *teste_unidade_texto_definicao_;
    TUIdioma *teste_unidade_idioma_;
    TUPreferencia *teste_unidade_preferencia_;
    TULeitor *teste_unidade_leitor_;
    TUDesenvolvedor *teste_unidade_desenvolvedor_;
    TUAdministrador *teste_unidade_administrador_;
    TUVocabulario *teste_unidade_vocabulario_;
    TUTermo *teste_unidade_termo_;
    TUDefinicao * teste_unidade_definicao_;

    void RunTestes();

    void SetUpTestes();

    inline void Destroy() {
        delete teste_unidade_administrador_;
        delete teste_unidade_data_;
        delete teste_unidade_texto_definicao_;
        delete teste_unidade_desenvolvedor_;
        delete teste_unidade_email_;
        delete teste_unidade_endereco_;
        delete teste_unidade_idioma_;
        delete teste_unidade_leitor_;
        delete teste_unidade_nome_;
        delete teste_unidade_preferencia_;
        delete teste_unidade_senha_;
        delete teste_unidade_sobrenome_;
        delete teste_unidade_telefone_;
        delete teste_unidade_vocabulario_;
        delete teste_unidade_termo_;
        delete teste_unidade_definicao_;
    }
};

#endif // VOC_CTRL_TESTES_H_

