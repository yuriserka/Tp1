#ifndef TRABALHO__TUENTIDADES__H__
#define TRABALHO__TUENTIDADES__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file teste-entidades.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de Abril de 2018
 *
 * @brief Descrição de todas as classes de Teste de Unidade das classes de Entidade.
 *
 * Neste arquivo estão listadas as classes de Teste de Unidade do Entidade, ou seja,
 * as classes que irão verificar se o lançamento de exceções nas classes de Entidade está ok.
 * */

/**
 * @brief Classe de Teste Base para as classes de Entidade.
 */
class TUBaseEntidades {
 public:
  /**
   * @brief roda os casos de falha e de sucesso dos testes de unidade.
   * @return 1 se tudo estiver ok.
   * @return 0 se acontecer algum erro.
   */
  int Run() {
    SetUp();
    CasoSucesso();
    CasoFalha();
    Destroy();
    return estado_;
  }

  /**
   * @brief Destrutor do objeto TUBaseEntidades
   * 
   */
  virtual ~TUBaseEntidades() = default;

 protected:
  /**
  * @brief representa se foi sucesso ou falha.
  *
  * */
  int estado_;

 private:
  virtual void SetUp() = 0;
  virtual void Destroy() = 0;
  virtual void CasoSucesso() = 0;
  virtual void CasoFalha() = 0;
};

/**
 * @brief Testa um Leitor inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TULeitor : public TUBaseEntidades {
 private:
  Leitor *leitor_valido_, *leitor_invalido_;

  const Nome knome_valido_ = Nome("Mion");
  const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
  const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
  const Email kemail_valido_ = Email("Sopedrada@gmail.com");

  inline void SetUp() override {
    leitor_valido_ = new Leitor(knome_valido_, ksobrenome_valido_, ksenha_valida_, kemail_valido_);
    estado_ = 1;
  }

  inline void Destroy() override {
    delete leitor_invalido_;
    delete leitor_valido_;
  }

  void CasoSucesso() override;
  void CasoFalha() override;
};

/**
 * @brief Testa um Desenvolvedor inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TUDesenvolvedor : public TUBaseEntidades {
 private:
  Desenvolvedor *desenvolvedor_valido, *desenvolvedor_invalido;

  const Nome knome_valido_ = Nome("Mion");
  const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
  const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
  const Email kemail_valido_ = Email("Sopedrada@gmail.com");
  const Data kdata_valida_ = Data("10/10/2001");

  inline void SetUp() override {
    desenvolvedor_valido =
        new Desenvolvedor(knome_valido_, ksobrenome_valido_, ksenha_valida_, kemail_valido_, kdata_valida_);
    estado_ = 1;
  }

  inline void Destroy() override {
    delete desenvolvedor_valido;
    delete desenvolvedor_invalido;
  }

  void CasoSucesso() override;
  void CasoFalha() override;
};

/**
 * @brief Testa um Administrador inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TUAdministrador : public TUBaseEntidades {
 private:
  Administrador *admin_valido, *admin_invalido;

  const Nome knome_valido_ = Nome("Mion");
  const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
  const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
  const Email kemail_valido_ = Email("Sopedrada@gmail.com");
  const Data kdata_valida_ = Data("10/10/2001");
  const Telefone telefone_valido = Telefone("61 98432-1015");
  const Address kendereco_valido_ = Address("QNA 1 casa 10");

  inline void SetUp() override {
    admin_valido = new Administrador(knome_valido_, ksobrenome_valido_, ksenha_valida_,
                                     kemail_valido_, kdata_valida_, telefone_valido, kendereco_valido_);
    estado_ = 1;
  }

  inline void Destroy() override {
    delete admin_valido;
    delete admin_invalido;
  }

  void CasoSucesso() override;
  void CasoFalha() override;
};

/**
 * @brief Testa apenas um Vocabulário válido, para verificar o lançamento de exceções.
 *
 */
class TUVocabulario {
 public:

  /**
   * @brief roda os casos de falha e de sucesso dos testes de unidade.
   * @return 1 se tudo estiver ok.
   * @return 0 se acontecer algum erro.
   */
  int Run() {
    SetUp();
    CasoSucesso();
    Destroy();
    return estado_;
  }

 private:
  int estado_;
  VocabularioControlado *valido_;

  const Nome knome_valido_ = Nome("Vocab");
  const Idioma kidioma_valido_ = Idioma("POR");
  const Data kdata_valida_ = Data("10/10/2015");

  inline void SetUp() {
    valido_ = new VocabularioControlado(knome_valido_, kidioma_valido_, kdata_valida_);
    estado_ = 1;
  }

  inline void Destroy() {
    delete valido_;
  }

  void CasoSucesso();
};

/**
 * @brief Testa apenas um Termo válido, para verificar o lançamento de exceções.
 *
 */
class TUTermo {
 public:

  /**
   * @brief roda os casos de falha e de sucesso dos testes de unidade.
   * @return 1 se tudo estiver ok.
   * @return 0 se acontecer algum erro.
   */
  int Run() {
    SetUp();
    CasoSucesso();
    Destroy();
    return estado_;
  }

 private:
  Termo *valido_;

  int estado_;
  const Nome knome_valido_ = Nome("Termo");
  const ClasseDoTermo kclasse_valida_ = ClasseDoTermo("PT");
  const Data kdata_valida_ = Data("10/10/2015");

  inline void SetUp() {
    valido_ = new Termo(knome_valido_, kclasse_valida_, kdata_valida_);
    estado_ = 1;
  }

  inline void Destroy() {
    delete valido_;
  }

  void CasoSucesso();
};

/**
 * @brief Testa apenas uma Definição válida, para verificar o lançamento de exceções.
 *
 */
class TUDefinicao {
 public:

  /**
   * @brief roda os casos de falha e de sucesso dos testes de unidade.
   * @return 1 se tudo estiver ok.
   * @return 0 se acontecer algum erro.
   */
  int Run() {
    SetUp();
    CasoSucesso();
    Destroy();
    return estado_;
  }

 private:
  Definicao *valido_;

  int estado_;
  const TextoDefinicao kdefinicao_valida_ = TextoDefinicao("Rave é daora");
  const Data kdata_valida_ = Data("10/10/2015");

  inline void SetUp() {
    valido_ = new Definicao(kdefinicao_valida_, kdata_valida_);
    estado_ = 1;
  }

  inline void Destroy() {
    delete valido_;
  }

  void CasoSucesso();
};

/**
 * @brief Executa todos os testes referentes as Entidades.
 * 
 */
class TUEntidades {
 public:
  /**
   * @brief Roda os cassos de teste das classes de entidades.
   * 
   */
  void RunEntidades();

 private:
  TULeitor *teste_unidade_leitor_;
  TUDesenvolvedor *teste_unidade_desenvolvedor_;
  TUAdministrador *teste_unidade_administrador_;
  TUVocabulario *teste_unidade_vocabulario_;
  TUTermo *teste_unidade_termo_;
  TUDefinicao *teste_unidade_definicao_;

  void SetUpEntidades() {
    teste_unidade_administrador_ = new TUAdministrador();
    teste_unidade_definicao_ = new TUDefinicao();
    teste_unidade_desenvolvedor_ = new TUDesenvolvedor();
    teste_unidade_leitor_ = new TULeitor();
    teste_unidade_termo_ = new TUTermo();
    teste_unidade_vocabulario_ = new TUVocabulario();
  }

  void DestroyEntidades() {
    delete teste_unidade_vocabulario_;
    delete teste_unidade_termo_;
    delete teste_unidade_leitor_;
    delete teste_unidade_desenvolvedor_;
    delete teste_unidade_definicao_;
    delete teste_unidade_administrador_;
  }
};

#endif // TRABALHO__TUENTIDADES__H__
