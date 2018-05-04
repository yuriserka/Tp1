#ifndef VOC_CTRL_DOMINIOS_H_
#define VOC_CTRL_DOMINIOS_H_

#include "bits/stdc++.h"

using namespace std;

/**
 * @file Dominios.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de kAbril de 2018
 *
 * @brief Descrição de todas as classes de Dominio.
 *
 * Neste arquivo estão listadas as classes de Domínio, ou seja, as classes com menor nível de abstração.
 */

/**
 * @brief classe responsável por armazenar o Nome do usuário do sistema.
 *
 * Contém de uma a vinte letras (A – Z a – z), sendo a primeira maiúscula.
 *
 */
class Nome {
 public:

  /**
   * @brief Constrói um novo objeto da classe Nome.
   *
   * @param _nome é a string passada.
   */
  explicit Nome(const string &_nome) {
    SetNome(_nome);
  }

  /**
   * @brief Construtor padrão da classe Nome.
   *
   */
  Nome() = default;

  /**
    * @brief Seta o nome do objeto da classe Nome
    *
  * Seta o nome se estiver de acordo com os padrões estabelecidos.
  *
    * @param _nome é a string q o usuário vai passar.
    */
  void SetNome(string _nome);

  /**
  * @brief retorna o nome do objeto da classe Nome
  *
  * @return string nome.
  */
  string GetNome() const { return nome_; }

 private:
  string nome_;
  const static unsigned kmax_nome_size_ = 20;
  const static unsigned kmin_nome_size_ = 1;

  void ValidaNome(string _nome);
};

/**
 * @brief classe responsável por armazenar o Sobrenome do usuário do sistema.
 *
 * Contém de uma a vinte letras (A – Z a – z), sendo a primeira maiúscula.
 *
 */
class Sobrenome {
 public:

  /**
   * @brief Constrói um novo objeto da classe Sobrenome.
   *
   * @param _sobrenome é a string passada.
   */
  explicit Sobrenome(const string &_sobrenome);

  /**
   * @brief Construtor padrão da classe Sobrenome.
   *
   */
  Sobrenome() = default;

  /**
    * @brief Seta o sobrenome do objeto da classe Sobrenome.
    *
  * Seta o sobrenome se estiver de acordo com os padrões estabelecidos.
  *
    * @param _sobrenome é a string que o usuário vai passar.
    */
  void SetSobrenome(string _sobrenome);

  /**
    * @brief retorna o sobrenome do objeto da classe Sobrenome.
    *
    * @return string sobrenome.
    */
  string GetSobrenome() const { return sobrenome_; }

 private:
  string sobrenome_;
  const static unsigned kmax_sobrenome_size_ = 20;
  const static unsigned kmin_sobrenome_size_ = 1;

  void ValidaSobrenome(string _sobrenome);
};

/**
 * @brief classe responsável por verificar a Senha do usuário do sistema.
 *
 * Contém oito caracteres, que podem ser letras (A – Z a – z) ou
 * dígitos (0 a 9). Cada senha precisa conter, pelo menos, uma letra
 * maiúscula, uma letra minúscula e um dígito. Não pode conter o
 * nome do seu usuário.
 *
 */
class Senha {
 public:

  /**
   * @brief Constrói um novo objeto da classe Senha.
   *
   * @param _senha é a string passada.
   */
  explicit Senha(const string &_senha) {
    SetSenha(_senha);
  }

  /**
   * @brief Construtor padrão da classe Senha.
   *
   */
  Senha() = default;

  /**
    * @brief Seta a senha do objeto da classe Senha
    *
  * Seta a senha se estiver de acordo com os padrões estabelecidos.
  *
    * @param _senha é a string que o usuário vai passar.
    */
  void SetSenha(string _senha);

  /**
    * @brief retorna a senha do objeto da classe Senha
    *
    * @return string senha.
    */
  string GetSenha() const { return senha_; }

 private:
  string senha_;
  const static unsigned kmax_senha_size_ = 8;
  const static int kminimo_maiuscula_ = 1, kminimo_minuscula_ = 1, kminimo_numero_ = 1;

  void ValidaSenha(string _senha);
};

/**
 * @brief classe responsável por verificar o e-mail do usuário do sistema.
 *
 * Composto por parte local e domínio separados por @. A parte local
 * pode conter letras (A – Z a – z), dígitos (0 – 9) e caracteres (! # $ %
 * & ' * + - / = ? ^ _ ` { | } ~ ;). Pode conter ponto (.) desde que não
 * seja o primeiro ou o último caracter. O domínio pode conter letras
 * (A – Z a – z); dígitos (0 – 9), desde que o domínio não seja só
 * numérico; – (hífen), desde que não seja o primeiro ou o último
 * caracter.
 *
 */
class Email {
 public:

  /**
   * @brief Constrói um novo objeto da classe Email.
   *
   * @param _email é a string passada.
   */
  explicit Email(const string &_email) {
    SetEmail(_email);
  }

  /**
   * @brief Construtor padrão da classe Email.
   *
   */
  Email() = default;

  /**
    * @brief Seta o e-mail do objeto da classe Email
    *
  * Seta o e-mail se estiver de acordo com os padrões estabelecidos.
  *
    * @param _email é a string que o usuário vai passar.
    */
  void SetEmail(string _email);

  /**
    * @brief retorna o e-mail do objeto da classe Email.
    *
    * @return string email.
    */
  string GetEmail() const { return email_; }

 private:
  string email_;
  const static unsigned kmin_email_size_ = 1;

  void ValidaEmail(string _email);
};

/**
 * @brief classe responsável por verificar a data que é passada.
 *
 * Formato DD/MM/AAAA onde DD consiste de número de 01 e 31,
 * MM consiste de número de 01 e 12, AAAA consiste de número de
 * 1900 a 2099. As datas devem considerar os anos que sejam
 * bissextos.
 *
 */
class Data {
 public:

  /**
   * @brief Constrói um novo objeto da classe Data.
   *
   * @param _data é a string passada.
   */
  explicit Data(const string &_data) {
    SetData(_data);
  }

  /**
   * @brief Construtor padrão da classe Data.
   *
   */
  Data() = default;

  /**
    * @brief Seta a data do objeto da classe Data
    *
  * Seta a data se estiver de acordo com os padrões estabelecidos.
  *
    * @param _data é a string que o usuário vai passar.
    */
  void SetData(string _data);

  /**
    * @brief retorna a data do objeto da classe Data.
    *
    * @return string data.
    */
  string GetData() const { return data_; }

 private:

  string data_;
  const static int kmax_dia_ = 31, kmin_dia_ = 1, kmax_mes_ = 12, kmin_mes_ = 1, kmax_ano_ = 2099, kmin_ano_ = 1900;
  const static int kmax_dia_kFevereiro_ = 28, kpos_barra_dia_ = 2, kpos_barra_mes_ = 5;
  const static unsigned kmin_data_size_ = 1;

  void ValidaData(string _data);

  enum Meses {
    knull, // para os meses ficarem com o indice certo
    kJaneiro,
    kFevereiro,
    kMarco,
    kAbril,
    kMaio,
    kJunho,
    kJulho,
    kAgosto,
    kSetembro,
    kOutubro,
    kNovembro,
    kDezembro
  };
};

/**
 * @brief classe responsável por verificar o Telefone do usuário do sistema.
 *
 * Formato AA NNNNN–NNNN onde A e N são dígitos (0 – 9).
 *
 */
class Telefone {
 public:

  /**
   * @brief Constrói um novo objeto da classe telefone.
   *
   * @param _telefone é a string passada.
   */
  explicit Telefone(const string &_telefone) {
    SetTelefone(_telefone);
  }

  /**
   * @brief Construtor padrão da classe Telefone.
   *
   */
  Telefone() = default;

  /**
    * @brief Seta o telefone do objeto da classe Telefone
    *
  * Seta o telefone se estiver de acordo com os padrões estabelecidos.
  *
    * @param _telefone é a string que o usuário vai passar.
    */
  void SetTelefone(string _telefone);

  /**
    * @brief retorna o telefone do objeto da classe Telefone
    *
    * @return string telefone.
    */
  string GetTelefone() const { return telefone_; }

 private:
  string telefone_;
  const static unsigned kmin_telefone_size_ = 1;
  const static int kspace_pos_ = 2, khifen_pos_ = 8;

  void ValidaTelefone(string _telefone);
};

/**
 * @brief classe responsável por verificar o endereço que é passado.
 *
 * Contém de uma a vinte letras (A – Z a – z). Pode conter espaços em
 * branco. O primeiro e o último caracter não podem ser espaços em
 * branco. Não podem haver espaços em branco em sequência (dois
 * ou mais).
 *
 */
class Address {
 public:

  /**
   * @brief Constrói um novo objeto da classe Address.
   *
   * @param _address é a string passada.
   */
  explicit Address(const string &_address) {
    SetAddress(_address);
  }

  /**
   * @brief Construtor padrão da classe Address.
   *
   */
  Address() = default;

  /**
    * @brief Seta o endereço do objeto da classe Address
    *
  * Seta o endereço se estiver de acordo com os padrões estabelecidos.
  *
    * @param _address é a string que o usuário vai passar.
    */
  void SetAddress(string _address);

  /**
    * @brief retorna o endereço do objeto da classe Address.
    *
    * @return string endereço.
    */
  string GetAddress() const { return address_; }

 private:
  string address_;
  const static unsigned kmax_address_size_ = 20;
  const static unsigned kmin_address_size_ = 1;

  void ValidaAddress(string _address);
};

/**
 * @brief classe responsável por verificar a definição que é passada.
 *
 * Contém de um a trinta caracteres quaisquer.
 *
 */
class TextoDefinicao {
 public:

  /**
   * @brief Constrói um novo objeto da classe TextoDefinicao.
   *
   * @param _definicao é a string passada.
   */
  explicit TextoDefinicao(const string &_definicao) {
    SetDefinicao(_definicao);
  }

  /**
   * @brief Construtor padrão da classe TextoDefinicao.
   *
   */
  TextoDefinicao() = default;

  /**
  * @brief Seta a definição do objeto da classe TextoDeDefinicao
  *
  * Seta a definição se estiver de acordo com os padrões estabelecidos.
  *
  * @param _definicao é a string que o usuário vai passar.
  */
  void SetDefinicao(string _definicao);

  /**
    * @brief retorna a definição do objeto da classe TextoDeDefinicao.
    *
    * @return string definicao.
    */
  string GetDefinicao() const { return definicao_; }

 private:
  string definicao_;
  const static unsigned kmax_definicao_size_ = 30;

  void ValidaDefinicao(string _definicao);
};

/**
 * @brief classe responsável por verificar qual o idioma do termo que é passado.
 *
 * ENG (inglês), FRA (francês), GER (alemão), ITA (italiano), POR
 * (português) e SPA (espanhol).
 *
 */
class Idioma {
 public:

  /**
   * @brief Constrói um novo objeto da classe Idioma.
   *
   * @param _idioma é a string passada.
   */
  explicit Idioma(const string &_idioma) {
    SetIdioma(_idioma);
  }

  /**
   * @brief Construtor padrão da classe Idioma.
   *
   */
  Idioma() = default;

  /**
    * @brief Seta o idioma do objeto da classe Idioma
    *
  * Seta o idioma se estiver de acordo com os padrões estabelecidos.
  *
    * @param _idioma é a string que o usuário vai passar.
    */
  void SetIdioma(string _idioma);

  /**
    * @brief retorna o idioma do objeto da classe Idioma.
    *
    * @return string idioma.
    */
  string GetIdioma() const { return idioma_; }

 private:
  string idioma_;

  void ValidaIdioma(string _idioma);
};

/**
 * @brief classe responsável por verificar a preferência do termo que é passado.
 *
 * PT (preferred term) e NP (non preferred term).
 *
 */
class ClasseDoTermo {
 public:

  /**
   * @brief Constrói um novo objeto da classe ClasseDoTermo.
   *
   * @param _preferencia é a string passada.
   */
  explicit ClasseDoTermo(const string &_preferencia) {
    SetPreferencia(_preferencia);
  }

  /**
   * @brief Construtor padrão da classe ClasseDoTermo.
   *
   */
  ClasseDoTermo() = default;

  /**
    * @brief Seta a preferência do objeto da classe ClasseDoTermo
    *
  * Seta a preferência se estiver de acordo com os padrões estabelecidos.
  *
    * @param _preferencia é a string que o usuário vai passar.
    */
  void SetPreferencia(string _preferencia);

  /**
    * @brief retorna a preferência do objeto da classe ClasseDoTermo.
    *
    * @return string preferencia.
    */
  string GetPreferencia() const { return preferencia_; }

 private:
  string preferencia_;

  void ValidaPreferencia(string _preferencia);
};

#endif // VOC_CTRL_DOMINIOS_H_

