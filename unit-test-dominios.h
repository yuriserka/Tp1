#ifndef VOC_CTRL_TUDOMINIOS_H_
#define VOC_CTRL_TUDOMINIOS_H_

#include "dominios.h"

using namespace std;

/**
 * @file unit-test-dominios.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de kAbril de 2018
 *
 * @brief Descrição de todas as classes de Teste de Unidade das classes de Domínio.
 *
 * Neste arquivo estão listadas as classes de Teste de Unidade do Domínio, ou seja,
 * as classes que irão verificar se o lançamento de exceções nas classes de Dominio está ok.
 * */

/**
 * @brief Testa vários nomes inválidos e um nome válido, para verificar o lançamento de exceções.
 *
 */
class TUNome {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários Nomes inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Nome válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Nome é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string knome_invalido_1_ = "";
    const string knome_invalido_2_ = "axt";
    const string knome_invalido_3_ = "abcdefghijklmnopqrstuvwxyz";
    const string knome_invalido_4_ = "30anos";
    const string knome_invalido_5_ = "xeSq33";
    const string knome_valido_ = "Matheus";

    Nome *nome_;
    bool estado_;

    inline void SetUp() {
        nome_ = new Nome();
        estado_ = true;
    }

    inline void Destroy() {
        delete nome_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa vários Sobrenomes inválidos e um sobrenome válido, para verificar o lançamento de exceções.
 *
 */
class TUSobrenome {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários Sobrenomes inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Sobrenome válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Sobrenome é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string ksobrenome_invalido_1_ = "oliveira";
    const string ksobrenome_invalido_2_ = "Gadf256";
    const string ksobrenome_invalido_3_ = "açlmalksljgjopadgsgjoppogj";
    const string ksobrenome_invalido_4_ = "";
    const string ksobrenome_invalido_5_ = "21Mdebraco";
    const string ksobrenome_valido_ = "Vieira";

    Sobrenome *sobrenome_;
    bool estado_;

    inline void SetUp() {
        sobrenome_ = new Sobrenome();
        estado_ = true;
    }

    inline void Destroy() {
        delete sobrenome_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa várias senhas inválidas e uma senha válida, para verificar o lançamento de exceções.
 *
 */
class TUSenha {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados várias Senhas inválidas e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também uma Senha válida e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e a Senha é válida.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string ksenha_invalida_1_ = "1l2zx35h";
    const string ksenha_invalida_2_ = "AAAAAAA";
    const string ksenha_invalida_3_ = "1b";
    const string ksenha_invalida_4_ = "abc57";
    const string ksenha_invalida_5_ = "1l2zx35hasdasgagahh42";
    const string ksenha_invalida_6_ = "B1r1.com";
    const string ksenha_valida_ = "Yh4uw0ed";

    Senha *senha_;
    bool estado_;

    inline void SetUp() {
        senha_ = new Senha();
        estado_ = true;
    }

    inline void Destroy() {
        delete senha_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa vários e-mails inválidos e um e-mail válido, para verificar o lançamento de exceções.
 *
 */
class TUEmail {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários Emails inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Email válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Email é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kemail_invalido_1_ = "lekdoido@110.com";
    const string kemail_invalido_2_ = "";
    const string kemail_invalido_3_ = "kkeae@@do.com";
    const string kemail_invalido_4_ = "teste4@gmail.com.";
    const string kemail_invalido_5_ = ".teste5@gmail.com";
    const string kemail_invalido_6_ = "teste6@gmail.com-";
    const string kemail_invalido_7_ = "teste7@-gmail.com.";
    const string kemail_invalido_8_ = "teste8.@gmail.com";
    const string kemail_valido_ = "jeremias@hotmail.com";

    Email *email_;
    bool estado_;

    inline void SetUp() {
        email_ = new Email();
        estado_ = true;
    }

    inline void Destroy() {
        delete email_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa várias datas inválidas e uma data válida, para verificar o lançamento de exceções.
 *
 */
class TUData {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados várias Datas inválidas e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também uma Data válida e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e a Data é válida.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kdata_invalida_1_ = "31/02/2018";
    const string kdata_invalida_2_ = "31/04/1980";
    const string kdata_invalida_3_ = "01/01/2110";
    const string kdata_invalida_4_ = "258/325/2001";
    const string kdata_valida_ = "12/10/1950";

    Data *data_;
    bool estado_;

    inline void SetUp() {
        data_ = new Data();
        estado_ = true;
    }

    inline void Destroy() {
        delete data_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa vários telefones inválidos e um telefone válido, para verificar o lançamento de exceções.
 *
 */
class TUTelefone {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários Telefones inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um Telefone válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o Telefone é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string ktelefone_invalido_1_ = "61 984s2-2584";
    const string ktelefone_invalido_2_ = "h9 98482-2584";
    const string ktelefone_invalido_3_ = "619 984s2-2584";
    const string ktelefone_invalido_4_ = "61 984s288-2584";
    const string ktelefone_invalido_5_ = "61999984s2-2584";
    const string ktelefone_invalido_6_ = "61 99812-258l";
    const string telefone_valido = "61 98354-3214";

    Telefone *telefone_;
    bool estado_;

    inline void SetUp() {
        telefone_ = new Telefone();
        estado_ = true;
    }

    inline void Destroy() {
        delete telefone_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa vários endereços inválidos e um endereço válido, para verificar o lançamento de exceções.
 *
 */
class TUAddress {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários endereços inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um endereço válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o endereço é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kendereco_invalido_1_ = " Rua 14 Sul, ap. 301";
    const string kendereco_invalido_2_ = "Rua 14 Sul, ap. 301 ";
    const string kendereco_invalido_3_ = " Rua 14 Sul, ap. 301 ";
    const string kendereco_invalido_4_ = "Rua 14  Sul, ap. 301";
    const string kendereco_invalido_5_ = "Rua 14 Sul, ap. 301iopjdsiojasoij";
    const string kendereco_valido_ = "Rua 20 Sul, ap. 503";

    Address *endereco_;
    bool estado_;

    inline void SetUp() {
        endereco_ = new Address();
        estado_ = true;
    }

    inline void Destroy() {
        delete endereco_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa várias definições inválidas e uma definição válida, para verificar o lançamento de exceções.
 *
 */
class TUTextoDefinicao {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados várias definições inválidas e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também uma definição válida e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e a definição é válida.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kdefinicao_invalida_1_ = "1.atração baseada no desejo sexual.";
    const string kdefinicao_invalida_2_ = "2.atração baseada no desejo por dinheiro.";
    const string kdefinicao_invalida_3_ = "3.atração baseada no desejo por comida.";
    const string kdefinicao_invalida_4_ = "4.atração baseada no desejo pela morte.";
    const string kdefinicao_valida_ = "5.forte afeição por alguém.";

    TextoDefinicao *texto_;
    bool estado_;

    inline void SetUp() {
        texto_ = new TextoDefinicao();
        estado_ = true;
    }

    inline void Destroy() {
        delete texto_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa vários idiomas inválidos e um idioma válido, para verificar o lançamento de exceções.
 *
 */
class TUIdioma {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados vários idiomas inválidos e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também um idioma válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e o idioma é válido.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kidioma_invalido_1_ = "XAN";
    const string kidioma_invalido_2_ = "LIL";
    const string kidioma_invalido_3_ = "EXQ";
    const string kidioma_invalido_4_ = "KBM";
    const string kidioma_valido_ = "POR";

    Idioma *idioma_;
    bool estado_;

    inline void SetUp() {
        idioma_ = new Idioma();
        estado_ = true;
    }

    inline void Destroy() {
        delete idioma_;
    }

    void FailTest();
    void SuccessTest();
};

/**
 * @brief Testa várias preferências inválidas e uma preferência válida, para verificar o lançamento de exceções.
 *
 */
class TUPreferencia {
    public:

    /**
     * @brief Roda vários casos de testes para verificar se está tudo funcionando como o esperado.
     *
     * São passados várias preferências inválidas e verificado se as exceções estão sendo lançadas como previsto.
     * É passado também uma preferência válido e feito o mesmo teste, verificando se o que foi Setado é igual ao argumento.
     *
     * @return true se as exceções foram capturadas corretamente e a preferência é válida.
     * @return false se alguma exceção não foi devidamente capturada.
     */
    bool Run();

  private:
    const string kpreferencia_invalida_1_ = "XD";
    const string kpreferencia_invalida_2_ = "BR";
    const string kpreferencia_invalida_3_ = "LP";
    const string kpreferencia_invalida_4_ = "MM";
    const string kpreferencia_valida_ = "NP";

    ClasseDoTermo *preferido_;
    bool estado_;

    inline void SetUp() {
        preferido_ = new ClasseDoTermo();
        estado_ = true;
    }

    inline void Destroy() {
        delete preferido_;
    }

    void FailTest();
    void SuccessTest();
};

#endif // VOC_CTRL_TUDOMINIOS_H_

