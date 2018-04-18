#ifndef VOC_CTRL_TUENTIDADES_H_
#define VOC_CTRL_TUENTIDADES_H_

#include "entidades.h"
#include "dominios.h"

using namespace std;

/**
 * @file unit-test-entidades.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de kAbril de 2018
 *
 * @brief Descrição de todas as classes de Teste de Unidade das classes de Entidade.
 *
 * Neste arquivo estão listadas as classes de Teste de Unidade do Entidade, ou seja,
 * as classes que irão verificar se o lançamento de exceções nas classes de Entidade está ok.
 * */

/**
 * @brief Testa um Leitor inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TULeitor {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado um Leitor inválido e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Leitor válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Leitor é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    Leitor *leitor_valido_, *leitor_invalido_;
    bool estado_;

    const Nome knome_valido_ = Nome("Mion");
    const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
    const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
    const Email kemail_valido_ = Email("Sopedrada@gmail.com");

    inline void SetUp() {
        leitor_valido_ = new Leitor(knome_valido_, ksobrenome_valido_, ksenha_valida_, kemail_valido_);
        estado_ = true;
    }

    inline void Destroy() {
      delete leitor_invalido_;
      delete leitor_valido_;
    }

    void SuccessTest();
    void FailTest();
};

/**
 * @brief Testa um Desenvolvedor inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TUDesenvolvedor {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado um Desenvolvedor inválido e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Desenvolvedor válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Desenvolvedor é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    Desenvolvedor *desenvolvedor_valido, *desenvolvedor_invalido;
    bool estado_;

    const Nome knome_valido_ = Nome("Mion");
    const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
    const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
    const Email kemail_valido_ = Email("Sopedrada@gmail.com");
    const Data kdata_valida_ = Data("10/10/2001");

    inline void SetUp() {
        desenvolvedor_valido = new Desenvolvedor(knome_valido_, ksobrenome_valido_, ksenha_valida_, kemail_valido_, kdata_valida_);
        estado_ = true;
    }

    inline void Destroy() {
      delete desenvolvedor_valido;
      delete desenvolvedor_invalido;
    }

    void SuccessTest();
    void FailTest();
};

/**
 * @brief Testa um Administrador inválido e um válido, para verificar o lançamento de exceções.
 *
 */
class TUAdministrador {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado um Administrador inválido e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Administrador válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Administrador é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    Administrador *admin_valido, *admin_invalido;
    bool estado_;

    const Nome knome_valido_ = Nome("Mion");
    const Sobrenome ksobrenome_valido_ = Sobrenome("Limonada");
    const Senha ksenha_invalida_ = Senha("Mion1234"), ksenha_valida_ = Senha("Mn45s3x5");
    const Email kemail_valido_ = Email("Sopedrada@gmail.com");
    const Data kdata_valida_ = Data("10/10/2001");
    const Telefone telefone_valido = Telefone("61 98432-1015");
    const Address kendereco_valido_ = Address("QNA 1 casa 10");

    inline void SetUp() {
        admin_valido = new Administrador(knome_valido_, ksobrenome_valido_, ksenha_valida_,
                                         kemail_valido_, kdata_valida_, telefone_valido, kendereco_valido_);
        estado_ = true;
    }

    inline void Destroy() {
      delete admin_valido;
      delete admin_invalido;
    }

    void SuccessTest();
    void FailTest();
};


/**
 * @brief Testa apenas um Vocabulário válido, para verificar o lançamento de exceções.
 *
 */
class TUVocabulario {
  public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado um Vocabulário válido e verificado se as exceções estão sendo
     * lançadas como previsto e verificando se o que foi Setado é igual
     * ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Vocabulário é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    VocabularioControlado *valido_;
    const Nome knome_valido_ = Nome("Vocab");
    const Idioma kidioma_valido_ = Idioma("POR");
    const Data kdata_valida_ = Data("10/10/2015");
    bool estado_;

    inline void SetUp() {
      valido_ = new VocabularioControlado(knome_valido_, kidioma_valido_, kdata_valida_);
      estado_ = true;
    }

    inline void Destroy() {
      delete valido_;
    }

    void SuccessTest();
    void FailTest();
};

/**
 * @brief Testa apenas um Termo válido, para verificar o lançamento de exceções.
 *
 */
class TUTermo {
  public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado um Termo válido e verificado se as exceções estão sendo
     * lançadas como previsto e verificando se o que foi Setado é igual
     * ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Termo é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    Termo *valido_;
    const Nome knome_valido_ = Nome("Termo");
    const ClasseDoTermo kclasse_valida_ = ClasseDoTermo("PT");
    const Data kdata_valida_ = Data("10/10/2015");
    bool estado_;

    inline void SetUp() {
      valido_ = new Termo(knome_valido_, kclasse_valida_, kdata_valida_);
      estado_ = true;
    }

    inline void Destroy() {
      delete valido_;
    }

    void SuccessTest();
    void FailTest();
};

/**
 * @brief Testa apenas uma Definição válida, para verificar o lançamento de exceções.
 *
 */
class TUDefinicao {
  public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * É passado uma Definição válida e verificado se as exceções estão sendo
     * lançadas como previsto e verificando se o que foi Setado é igual
     * ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e a Defininção é válida.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    Definicao *valido_;
    const TextoDefinicao kdefinicao_valida_ = TextoDefinicao("Rave é daora");
    const Data kdata_valida_ = Data("10/10/2015");
    bool estado_;

    inline void SetUp() {
      valido_ = new Definicao(kdefinicao_valida_, kdata_valida_);
      estado_ = true;
    }

    inline void Destroy() {
      delete valido_;
    }

    void SuccessTest();
    void FailTest();
};

#endif // VOC_CTRL_TUENTIDADES_H_
