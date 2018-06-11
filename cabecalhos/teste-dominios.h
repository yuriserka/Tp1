#ifndef TRABALHO__TUDOMINIOS__H__
#define TRABALHO__TUDOMINIOS__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file teste-dominios.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de Abril de 2018
 *
 * @brief Descrição de todas as classes de Teste de Unidade das classes de Domínio.
 *
 * Neste arquivo estão listadas as classes de Teste de Unidade do Domínio, ou seja,
 * as classes que irão verificar se o lançamento de exceções nas classes de Dominio está ok.
 * */

/**
 * @brief Classe de Teste Base para as classes de Dominio.
 */
class TUBaseDominios {
 public:
  /**
   * @brief construtor padrão da classe TUBaseDominios.
   */
  TUBaseDominios() = default;

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
   * @brief Destrutor do objeto TUBaseDominios 
   * 
   */
  virtual ~TUBaseDominios() = default;

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
 * @brief Testa vários nomes inválidos e um nome válido, para verificar o lançamento de exceções.
 *
 */
class TUNome : public TUBaseDominios {
 private:
  const string knome_invalido_1_ = "";
  const string knome_invalido_2_ = "axt";
  const string knome_invalido_3_ = "abcdefghijklmnopqrstuvwxyz";
  const string knome_invalido_4_ = "30anos";
  const string knome_invalido_5_ = "xeSq33";
  const string knome_valido_ = "Matheus";

  Nome *nome_;

  void SetUp() override {
    nome_ = new Nome();
    estado_ = true;
  }

  void Destroy() override {
    delete nome_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa vários Sobrenomes inválidos e um sobrenome válido, para verificar o lançamento de exceções.
 *
 */
class TUSobrenome : public TUBaseDominios {
 private:
  const string ksobrenome_invalido_1_ = "oliveira";
  const string ksobrenome_invalido_2_ = "Gadf256";
  const string ksobrenome_invalido_3_ = "açlmalksljgjopadgsgjoppogj";
  const string ksobrenome_invalido_4_ = "";
  const string ksobrenome_invalido_5_ = "21Mdebraco";
  const string ksobrenome_valido_ = "Vieira";

  Sobrenome *sobrenome_;

  inline void SetUp() override {
    sobrenome_ = new Sobrenome();
    estado_ = true;
  }

  inline void Destroy() override {
    delete sobrenome_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa várias senhas inválidas e uma senha válida, para verificar o lançamento de exceções.
 *
 */
class TUSenha : public TUBaseDominios {
 private:
  const string ksenha_invalida_1_ = "1l2zx35h";
  const string ksenha_invalida_2_ = "AAAAAAA";
  const string ksenha_invalida_3_ = "1b";
  const string ksenha_invalida_4_ = "abc57";
  const string ksenha_invalida_5_ = "1l2zx35hasdasgagahh42";
  const string ksenha_invalida_6_ = "B1r1.com";
  const string ksenha_valida_ = "Yh4uw0ed";

  Senha *senha_;

  inline void SetUp() override {
    senha_ = new Senha();
    estado_ = true;
  }

  inline void Destroy() override {
    delete senha_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa vários e-mails inválidos e um e-mail válido, para verificar o lançamento de exceções.
 *
 */
class TUEmail : public TUBaseDominios {
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

  inline void SetUp() override {
    email_ = new Email();
    estado_ = true;
  }

  inline void Destroy() override {
    delete email_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa várias datas inválidas e uma data válida, para verificar o lançamento de exceções.
 *
 */
class TUData : public TUBaseDominios {
 private:
  const string kdata_invalida_1_ = "31/02/2018";
  const string kdata_invalida_2_ = "31/04/1980";
  const string kdata_invalida_3_ = "01/01/2110";
  const string kdata_invalida_4_ = "258/325/2001";
  const string kdata_valida_ = "12/10/1950";

  Data *data_;

  inline void SetUp() override {
    data_ = new Data();
    estado_ = true;
  }

  inline void Destroy() override {
    delete data_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa vários telefones inválidos e um telefone válido, para verificar o lançamento de exceções.
 *
 */
class TUTelefone : public TUBaseDominios {
 private:
  const string ktelefone_invalido_1_ = "61 984s2-2584";
  const string ktelefone_invalido_2_ = "h9 98482-2584";
  const string ktelefone_invalido_3_ = "619 984s2-2584";
  const string ktelefone_invalido_4_ = "61 984s288-2584";
  const string ktelefone_invalido_5_ = "61999984s2-2584";
  const string ktelefone_invalido_6_ = "61 99812-258l";
  const string telefone_valido = "61 98354-3214";

  Telefone *telefone_;

  inline void SetUp() override {
    telefone_ = new Telefone();
    estado_ = true;
  }

  inline void Destroy() override {
    delete telefone_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa vários endereços inválidos e um endereço válido, para verificar o lançamento de exceções.
 *
 */
class TUAddress : public TUBaseDominios {
 private:
  const string kendereco_invalido_1_ = " Rua 14 Sul, ap. 301";
  const string kendereco_invalido_2_ = "Rua 14 Sul, ap. 301 ";
  const string kendereco_invalido_3_ = " Rua 14 Sul, ap. 301 ";
  const string kendereco_invalido_4_ = "Rua 14  Sul, ap. 301";
  const string kendereco_invalido_5_ = "Rua 14 Sul, ap. 301iopjdsiojasoij";
  const string kendereco_valido_ = "Rua 20 Sul, ap. 503";

  Address *endereco_;

  inline void SetUp() override {
    endereco_ = new Address();
    estado_ = true;
  }

  inline void Destroy() override {
    delete endereco_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa várias definições inválidas e uma definição válida, para verificar o lançamento de exceções.
 *
 */
class TUTextoDefinicao : public TUBaseDominios {
 private:
  const string kdefinicao_invalida_1_ = "1.atração baseada no desejo sexual.";
  const string kdefinicao_invalida_2_ = "2.atração baseada no desejo por dinheiro.";
  const string kdefinicao_invalida_3_ = "3.atração baseada no desejo por comida.";
  const string kdefinicao_invalida_4_ = "4.atração baseada no desejo pela morte.";
  const string kdefinicao_valida_ = "5.forte afeição por alguém.";

  TextoDefinicao *texto_;

  inline void SetUp() override {
    texto_ = new TextoDefinicao();
    estado_ = true;
  }

  inline void Destroy() override {
    delete texto_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa vários idiomas inválidos e um idioma válido, para verificar o lançamento de exceções.
 *
 */
class TUIdioma : public TUBaseDominios {
 private:
  const string kidioma_invalido_1_ = "XAN";
  const string kidioma_invalido_2_ = "LIL";
  const string kidioma_invalido_3_ = "EXQ";
  const string kidioma_invalido_4_ = "KBM";
  const string kidioma_valido_ = "POR";

  Idioma *idioma_;

  inline void SetUp() override {
    idioma_ = new Idioma();
    estado_ = true;
  }

  inline void Destroy() override {
    delete idioma_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Testa várias preferências inválidas e uma preferência válida, para verificar o lançamento de exceções.
 *
 */
class TUPreferencia : public TUBaseDominios {
 private:
  const string kpreferencia_invalida_1_ = "XD";
  const string kpreferencia_invalida_2_ = "BR";
  const string kpreferencia_invalida_3_ = "LP";
  const string kpreferencia_invalida_4_ = "MM";
  const string kpreferencia_valida_ = "NP";

  ClasseDoTermo *preferido_;

  inline void SetUp() override {
    preferido_ = new ClasseDoTermo();
    estado_ = true;
  }

  inline void Destroy() override {
    delete preferido_;
  }

  void CasoFalha() override;
  void CasoSucesso() override;
};

/**
 * @brief Executa todos os testes referentes as classes de Dominio.
 * 
 */
class TUDominios {
 public:
  /**
   * @brief Roda os casos de teste das classes de dominio.
   * 
   */
  void RunDominios();
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

  void SetUpDominios() {
    teste_unidade_data_ = new TUData();
    teste_unidade_email_ = new TUEmail();
    teste_unidade_endereco_ = new TUAddress();
    teste_unidade_idioma_ = new TUIdioma();
    teste_unidade_nome_ = new TUNome();
    teste_unidade_preferencia_ = new TUPreferencia();
    teste_unidade_senha_ = new TUSenha();
    teste_unidade_sobrenome_ = new TUSobrenome();
    teste_unidade_telefone_ = new TUTelefone();
    teste_unidade_texto_definicao_ = new TUTextoDefinicao;
  }

  void DestroyDominios() {
    delete teste_unidade_texto_definicao_;
    delete teste_unidade_telefone_;
    delete teste_unidade_sobrenome_;
    delete teste_unidade_senha_;
    delete teste_unidade_preferencia_;
    delete teste_unidade_nome_;
    delete teste_unidade_idioma_;
    delete teste_unidade_endereco_;
    delete teste_unidade_email_;
    delete teste_unidade_data_;
  }
};

#endif // TRABALHO__TUDOMINIOS__H__

