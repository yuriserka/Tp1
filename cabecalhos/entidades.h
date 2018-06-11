#ifndef TRABALHO__ENTIDADES__H__
#define TRABALHO__ENTIDADES__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file entidades.h
 * @author Yuri Serka do Carmo Rodrigues
 * @date 7 de Abril de 2018
 *
 * @brief Descrição de todas as classes de Entidades.
 *
 * Neste arquivo estão listadas as classes de Entidade, ou seja, as classes que armazenarão os dados dos usuários.
 * */

/**
 * @brief classe responsável por armazenar as informações de um Leitor.
 *
 * Um leitor poderá apenas acessar os termos para ler.
 *
 */
class Leitor {
 public:

  /**
  * @brief Constrói um novo objeto da classe Leitor.
  *
  * @param _nome é o nome passado pelo usuário.
  * @param _sobrenome é o sobrenome pelo usuário.
  * @param _senha é a senha passada pelo usuário.
  * @param _email é o e-mail passado pelo usuário.
  */
  Leitor(const Nome &_nome, const Sobrenome &_sobrenome, const Senha &_senha, const Email &_email) {
    SetNome(_nome);
    SetSobrenome(_sobrenome);
    SetSenha(_senha);
    SetEmail(_email);
  }
  /**
  * @brief Construtor padrão da classe Leitor.
  *
  */
  Leitor() = default;

  /**
   * @brief Seta o objeto Nome do Leitor.
   *
   * @param _nome é o nome passado pelo usuário.
   */

  inline void SetNome(const Nome &_nome) {
    this->nome_ = _nome;
  }

  /**
   * @brief Seta o objeto Sobrenome do Leitor.
   *
   * @param _sobrenome é o sobrenome passado pelo usuário.
   */
  inline void SetSobrenome(const Sobrenome &_sobrenome) {
    this->sobrenome_ = _sobrenome;
  }

  /**
   * @brief Seta o objeto Senha do Leitor.
   *
   * Seta a senha se estiver de acordo com os padrões estabelecidos.
   *
   * @param _senha é a senha passada pelo usuário.
   */
  void SetSenha(const Senha &_senha);

  /**
   * @brief Seta o objeto Email do Leitor.
   *
   * @param _email é o e-mail passado pelo usuário.
   */
  inline void SetEmail(const Email &_email) {
    this->email_ = _email;
  }

  /**
   * @brief retorna o Nome do objeto da classe Leitor.
   *
   * @return Nome retorna um objeto da classe.
   */
  inline Nome GetNome() const { return nome_; }

  /**
   * @brief retorna o Sobrenome do objeto da classe Leitor.
   *
   * @return Nome retorna um objeto da classe.
   */
  inline Sobrenome GetSobrenome() const { return sobrenome_; }

  /**
   * @brief retorna a Senha do objeto da classe Leitor.
   *
   * @return Senha retorna um objeto da classe.
   */
  inline Senha GetSenha() const { return senha_; }

  /**
   * @brief retorna o Email do objeto da classe Leitor.
   *
   * @return Email retorna um objeto da classe.
   */
  inline Email GetEmail() const { return email_; }

  /**
   * @brief overload do operador == para fazer comparações de Emails
   * 
   * Compara o Email do atual elemento da classe com o que está sendo procurado.
   * 
   * @param procurado é o email que é passado para a comparação
   * @return true se forem iguais.
   * @return false se forem diferentes.
   */
  bool operator==(const Email &procurado) {
    return (this->email_.GetEmail().compare(procurado.GetEmail()) == 0);
  }

 protected:
  /**
   * @brief função que valida a senha do usuario.
   * 
   * A senha nao pode conter o nome de usuario.
   * 
   */
  void ValidaSenhaEntidades(const Senha &);

  /**
   * @brief Nome do usuario
   * 
   */
  Nome nome_;

  /**
   * @brief Sobrenome do usuario
   * 
   */
  Sobrenome sobrenome_;

  /**
   * @brief Senha do usuario.
   * 
   */
  Senha senha_;

  /**
   * @brief Email do usuario.
   * 
   */
  Email email_;
};

/**
 * @brief classe responsável por armazenar as informações de um Desenvolvedor.
 *
 * Um Desenvolvedor poderá, além dos serviços disponíveis aos leitores, criar, excluir, editar termo e definição de termo.
 *
 */
class Desenvolvedor : public Leitor {
 public:

  /**
  * @brief Constrói um novo objeto da classe Desenvolvedor.
  *
  * @param _nome é o nome passado pelo usuário.
  * @param _sobrenome é o sobrenome pelo usuário.
  * @param _senha é a senha passada pelo usuário.
  * @param _email é o e-mail passado pelo usuário.
  * @param _data é a data passada pelo usuário.
  */
  Desenvolvedor(const Nome &_nome, const Sobrenome &_sobrenome, const Senha &_senha,
                const Email &_email, const Data &_data) {
    SetNome(_nome);
    SetSobrenome(_sobrenome);
    SetSenha(_senha);
    SetEmail(_email);
    SetDataDeNascimento(_data);
  }

  /**
   * @brief Construtor padrão da classe Desenvolvedor.
   *
   */
  Desenvolvedor() = default;

  /**
   * @brief Seta o objeto Data do Desenvolvedor.
   *
   * @param _data é a data passada pelo usuário.
   */
  inline void SetDataDeNascimento(const Data &_data) {
    this->data_de_nascimento_ = _data;
  }

  /**
   * @brief retorna a Data do objeto da classe Leitor.
   *
   * @return Data retorna um objeto da classe.
   */
  inline Data GetDataDeNascimento() const { return data_de_nascimento_; }

 protected:
  /**
   * @brief Data de Nascimento do usuario.
   * 
   */
  Data data_de_nascimento_;
};

/**
 * @brief classe responsável por armazenar as informações de um Administrador.
 *
 * Um administrador poderá criar quantos vocabulários controlados queira,
 * mas deve informar: nome do vocabulário controlado, texto de definição, idioma e data.
 *
 */
class Administrador : public Desenvolvedor {
 public:

  /**
  * @brief Constrói um novo objeto da classe Administrador.
  *
  * @param _nome é o nome passado pelo usuário.
  * @param _sobrenome é o sobrenome pelo usuário.
  * @param _senha é a senha passada pelo usuário.
  * @param _email é o e-mail passado pelo usuário.
  * @param _data é a data passada pelo usuário.
  * @param _telefone é o telefone passado pelo usuário.
  * @param _address é o endereço passado pelo usuário.
  */
  Administrador(const Nome &_nome, const Sobrenome &_sobrenome, const Senha &_senha, const Email &_email,
                const Data &_data, const Telefone &_telefone, const Address &_address) {
    SetNome(_nome);
    SetSobrenome(_sobrenome);
    SetSenha(_senha);
    SetEmail(_email);
    SetDataDeNascimento(_data);
    SetTelefone(_telefone);
    SetEndereco(_address);
  }

  /**
   * @brief Construtor padrão da classe Administrador.
   *
   */
  Administrador() = default;

  /**
   * @brief Seta o objeto Telefone do Administrador.
   *
   * @param _telefone é o telefone passado pelo usuário.
   */

  inline void SetTelefone(const Telefone &_telefone) {
    this->telefone_ = _telefone;
  }

  /**
   * @brief Seta o objeto Address do Administrador.
   *
   * @param _address é o endereço passado pelo usuário.
   */
  inline void SetEndereco(const Address &_address) {
    this->endereco_ = _address;
  }

  /**
   * @brief retorna o Telefone do objeto da classe Leitor.
   *
   * @return Telefone retorna um objeto da classe.
   */
  inline Telefone GetTelefone() const { return telefone_; }

  /**
   * @brief retorna o endereço do objeto da classe Leitor.
   *
   * @return Address retorna um objeto da classe.
   */
  inline Address GetEndereco() const { return endereco_; }

 protected:
  /**
   * @brief Telefone do usuario.
   * 
   */
  Telefone telefone_;

  /**
   * @brief Endereço do usuario
   * 
   */
  Address endereco_;
};

/**
 * @brief é uma estrutura que é composta por termos.
 *
 */
class VocabularioControlado {
 public:

  /**
   * @brief Constrói um novo objeto da classe Administrador.
   *
   * @param _nome é o nome passado pelo usuário.
   * @param _idioma é o idioma passado pelo usuário.
   * @param _data é a data passada pelo usuário.
   */
  VocabularioControlado(const Nome &_nome, const Idioma &_idioma, const Data &_data) {
    SetNome(_nome);
    SetIdioma(_idioma);
    SetData(_data);
  }

  /**
   * @brief Construtor padrão da classe VocabularioControlado.
   *
   */
  VocabularioControlado() = default;

  /**
   * @brief Seta o objeto Data do VocabularioControlado.
   *
   * @param _data é a data passada pelo usuário.
   */
  inline void SetData(const Data &_data) {
    this->data_ = _data;
  }

  /**
   * @brief Seta o objeto Nome do VocabularioControlado.
   *
   * @param _nome é o nome passado pelo usuário.
   */
  inline void SetNome(const Nome &_nome) {
    this->nome_ = _nome;
  }

  /**
   * @brief Seta o objeto Idioma do VocabularioControlado.
   *
   * @param _idioma é o idioma passado pelo usuário.
   */
  inline void SetIdioma(const Idioma &_idioma) {
    this->idioma_ = _idioma;
  }

  /**
   * @brief retorna a Data do objeto da classe VocabularioControlado.
   *
   * @return Data retorna um objeto da classe.
   */
  inline Data GetData() const { return data_; }

  /**
   * @brief retorna o Nome do objeto da classe VocabularioControlado.
   *
   * @return Nome retorna um objeto da classe.
   */
  inline Nome GetNome() const { return nome_; }

  /**
   * @brief retorna o Idioma do objeto da classe VocabularioControlado.
   *
   * @return Idioma retorna um objeto da classe.
   */
  inline Idioma GetIdioma() const { return idioma_; }

 protected:
  /**
   * @brief Data em que o Vocabulario foi criado.
   * 
   */
  Data data_;

  /**
   * @brief Nome do Vocabulario Controlado.
   * 
   */
  Nome nome_;

 private:
  Idioma idioma_;
};

/**
 * @brief é a palavra que vai ser definida.
 *
 */
class Termo : public VocabularioControlado {
 public:

  /**
   * @brief Constrói um novo objeto da classe Termo.
   *
   * @param _nome é o nome passado pelo usuário.
   * @param _preferencia é a preferência passada pelo usuário.
   * @param _data é a data passada pelo usuário.
   */
  Termo(const Nome &_nome, const ClasseDoTermo &_preferencia, const Data &_data) {
    SetNome(_nome);
    SetPreferencia(_preferencia);
    SetData(_data);
  }

  /**
   * @brief Construtor padrão da classe Termo.
   *
   */
  Termo() = default;

  /**
   * @brief Seta o objeto ClasseDoTermo do Termo.
   *
   * @param _preferencia é a preferência passada pelo usuário.
   */
  inline void SetPreferencia(const ClasseDoTermo &_preferencia) {
    this->preferencia_ = _preferencia;
  }

  /**
   * @brief retorna a preferência do objeto da classe Termo.
   *
   * @return ClasseDoTermo retorna um objeto da classe.
   */
  inline ClasseDoTermo GetPreferencia() const { return preferencia_; }

 private:
  ClasseDoTermo preferencia_;
};

/**
 * @brief estabelece a definição e a data em que foi feita.
 *
 */
class Definicao {
 public:

  /**
   * @brief Constrói um novo objeto da classe Definicao.
   *
   * @param _definicao é a definição passada pelo usuário.
   * @param _data é a data passada pelo usuário.
   */
  Definicao(const TextoDefinicao &_definicao, const Data &_data) {
    SetDefinicao(_definicao);
    SetData(_data);
  }

  Definicao() = default;

  /**
   * @brief Seta o objeto Data da Definicao.
   *
   * @param _data é a data passada pelo usuário.
   */
  inline void SetData(const Data &_data) {
    this->data_ = _data;
  }

  /**
   * @brief Seta o objeto TextoDeDefinicao da Definicao.
   *
   * @param _definicao é a definição passada pelo usuário.
   */
  inline void SetDefinicao(const TextoDefinicao &_definicao) {
    this->definicao_ = _definicao;
  }

  /**
   * @brief retorna a data do objeto da classe Definicao.
   *
   * @return Data retorna um objeto da classe.
   */
  inline Data GetData() const { return data_; }

  /**
   * @brief retorna a definição do objeto da classe Definicao.
   *
   * @return TextoDeDefinicao retorna um objeto da classe.
   */
  inline TextoDefinicao GetDefinicao() const { return definicao_; }

 private:
  TextoDefinicao definicao_;
  Data data_;
};

#endif // TRABALHO__ENTIDADES__H__

