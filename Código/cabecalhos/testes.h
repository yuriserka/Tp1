#ifndef TRABALHO__TESTES__H__
#define TRABALHO__TESTES__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file testes.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de Abril de 2018
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
  void Execute() {
    SetUpTestes();
    RunTestes();
    Destroy();
  }

 private:
  TUDominios *teste_unidade_dominios_;
  TUEntidades *teste_unidade_entidades_;

  inline void SetUpTestes() {
    teste_unidade_dominios_ = new TUDominios();
    teste_unidade_entidades_ = new TUEntidades();
  }

  void RunTestes() {
    teste_unidade_dominios_->RunDominios();
    teste_unidade_entidades_->RunEntidades();
  }

  inline void Destroy() {
    delete teste_unidade_dominios_;
    delete teste_unidade_entidades_;
  }
};

#endif // TRABALHO__TESTES__H__

