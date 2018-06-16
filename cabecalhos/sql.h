#ifndef TRABALHO__CMDSQL__H__
#define TRABALHO__CMDSQL__H__

#include "../cabecalhos/../cabecalhos/includes.h"

class ElementoResultado {
  public:
    inline void SetNomeColuna(const string &colname) {
      this->nome_coluna_ = colname;
    }

    inline void SetValorColuna(const string &colval) {
      this->valor_coluna_ = colval;
    }

    inline string GetNomeColuna() const {
      return nome_coluna_;
    }

    inline string GetValorColuna() const {
      return valor_coluna_;
    }

  private:
    string nome_coluna_;
    string valor_coluna_;
};

class ComandoSql {
  public:
    ComandoSql() {
      nome_banco_de_dados_ = "databank.db";
    }
    void Executar();
    
  protected:
    string cmdSql_;
    static list<ElementoResultado> lista_resultado_;

  private:
    const char* nome_banco_de_dados_;
    sqlite3* bd_;
    char* mensagem_;
    int rc_;
    void Conectar();
    void Desconectar();
    static int Callback(void *, int, char **, char **);
};

class ComandoSqlCadastrar : public ComandoSql { 
  public:
    ComandoSqlCadastrar() = default;
    explicit ComandoSqlCadastrar(const Leitor &leitor, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, conta)"\
      " VALUES (";
      cmdSql_ += "'" + leitor.GetNome().GetNome() +           "', ";
      cmdSql_ += "'" + leitor.GetSobrenome().GetSobrenome() + "', ";
      cmdSql_ += "'" + leitor.GetSenha().GetSenha() +         "', ";
      cmdSql_ += "'" + leitor.GetEmail().GetEmail() +         "', ";
      cmdSql_ += "'" + conta + "');";
    }

    explicit ComandoSqlCadastrar(const Desenvolvedor &dev, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, "\
      "nascimento, conta) VALUES (";
      cmdSql_ += "'" + dev.GetNome().GetNome() +              "', ";
      cmdSql_ += "'" + dev.GetSobrenome().GetSobrenome() +    "', ";
      cmdSql_ += "'" + dev.GetSenha().GetSenha() +            "', ";
      cmdSql_ += "'" + dev.GetEmail().GetEmail() +            "', ";
      cmdSql_ += "'" + dev.GetDataDeNascimento().GetData() +  "', ";
      cmdSql_ += "'" + conta + "');";
    }

    explicit ComandoSqlCadastrar(const Administrador &adm, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, "\
      "nascimento, telefone, endereco, conta) VALUES (";
      cmdSql_ += "'" + adm.GetNome().GetNome() +              "', ";
      cmdSql_ += "'" + adm.GetSobrenome().GetSobrenome() +    "', ";
      cmdSql_ += "'" + adm.GetSenha().GetSenha() +            "', ";
      cmdSql_ += "'" + adm.GetEmail().GetEmail() +            "', ";
      cmdSql_ += "'" + adm.GetDataDeNascimento().GetData() +  "', ";
      cmdSql_ += "'" + adm.GetTelefone().GetTelefone() +      "', ";
      cmdSql_ += "'" + adm.GetEndereco().GetAddress() +       "', ";
      cmdSql_ += "'" + conta + "');";
    }
    
    explicit ComandoSqlCadastrar(const VocabularioControlado &voc, const Definicao &def, const Email &email) {
      cmdSql_ = "INSERT or IGNORE INTO vocabularios (nome, idioma, data, definicao, administrador)"\
      "VALUES (";
      cmdSql_ += "'" + voc.GetNome().GetNome() +           "', ";
      cmdSql_ += "'" + voc.GetIdioma().GetIdioma() +       "', ";
      cmdSql_ += "'" + voc.GetData().GetData() +           "', ";
      cmdSql_ += "'" + def.GetDefinicao().GetDefinicao() + "', ";
      cmdSql_ += "'" + email.GetEmail() +                  "');";
    }
    
    explicit ComandoSqlCadastrar(const Termo &termo, const VocabularioControlado &voc) {
      cmdSql_ = "INSERT or IGNORE INTO termos (nome, classe, data, vocabulario)"\
      "VALUES (";
      cmdSql_ += "'" + termo.GetNome().GetNome() +               "', ";
      cmdSql_ += "'" + termo.GetPreferencia().GetPreferencia() + "', ";
      cmdSql_ += "'" + termo.GetData().GetData() +               "', ";
      cmdSql_ += "'" + voc.GetNome().GetNome() +                 "');";
    }
    
    explicit ComandoSqlCadastrar(const Definicao &def) {
      cmdSql_ = "INSERT or IGNORE INTO definicoes (texto, data)"\
      "VALUES (";
      cmdSql_ += "'" + def.GetDefinicao().GetDefinicao() + "', ";
      cmdSql_ += "'" + def.GetData().GetData() +           "');";
    }

    // cadastra desenvolvedor
    explicit ComandoSqlCadastrar(const VocabularioControlado &voc, const Desenvolvedor &dev) {
      cmdSql_ = "INSERT or IGNORE INTO vocabularios (nome, idioma, data, desenvolvedor)"\
      "VALUES (";
      cmdSql_ += "'" + voc.GetNome().GetNome() +      "', ";
      cmdSql_ += "'" + voc.GetIdioma().GetIdioma() +  "', ";
      cmdSql_ += "'" + voc.GetData().GetData() +      "', ";
      cmdSql_ += "'" + dev.GetEmail().GetEmail() +    "');";
    }
};

class ComandoSqlAtualizar : public ComandoSql {
  public:
    ComandoSqlAtualizar() = default;
    explicit ComandoSqlAtualizar(const Leitor &leitor) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome = '"      + leitor.GetNome().GetNome();
      cmdSql_ += "', sobrenome = '"  + leitor.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha = '"      + leitor.GetSenha().GetSenha();
      cmdSql_ += "' WHERE email = '" + leitor.GetEmail().GetEmail() + "';";
    }

    explicit ComandoSqlAtualizar(const Desenvolvedor &dev) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome = '"      + dev.GetNome().GetNome();
      cmdSql_ += "', sobrenome = '"  + dev.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha = '"      + dev.GetSenha().GetSenha();
      cmdSql_ += "', nascimento = '"  + dev.GetDataDeNascimento().GetData();
      cmdSql_ += "' WHERE email = '" + dev.GetEmail().GetEmail() + "';";
    }

    explicit ComandoSqlAtualizar(const Administrador &adm) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome =      '"  + adm.GetNome().GetNome();
      cmdSql_ += "', sobrenome =  '"  + adm.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha =      '"  + adm.GetSenha().GetSenha();
      cmdSql_ += "', nascimento = '"  + adm.GetDataDeNascimento().GetData();
      cmdSql_ += "', telefone =   '"  + adm.GetTelefone().GetTelefone();
      cmdSql_ += "', endereco =   '"  + adm.GetEndereco().GetAddress();
      cmdSql_ += "' WHERE email = '"  + adm.GetEmail().GetEmail() + "';";
    }

    explicit ComandoSqlAtualizar(const Termo &termo) {
      cmdSql_ = "UPDATE termos ";
      cmdSql_ += "SET classe =    '" + termo.GetPreferencia().GetPreferencia();
      cmdSql_ += "', data =       '" + termo.GetData().GetData();
      cmdSql_ += "' WHERE nome =  '" + termo.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlAtualizar(const VocabularioControlado &voc) {
      cmdSql_ = "UPDATE vocabularios ";
      cmdSql_ += "SET idioma =    '" + voc.GetIdioma().GetIdioma();
      cmdSql_ += "', data =       '" + voc.GetData().GetData();
      cmdSql_ += "' WHERE nome =  '" + voc.GetNome().GetNome() + "';";
    }

    // vai atualizar o desenvolvedor do vocabulario
    explicit ComandoSqlAtualizar(const Desenvolvedor &dev, const VocabularioControlado &voc) {
      cmdSql_ = "UPDATE vocabularios ";
      cmdSql_ += "SET desenvolvedor = '" + dev.GetEmail().GetEmail();
      cmdSql_ += "' WHERE nome =      '" + voc.GetNome().GetNome() + "';";
    }

    // vai atualizar o administrador do vocabulario
    explicit ComandoSqlAtualizar(const Administrador &dev, const VocabularioControlado &voc) {
      cmdSql_ = "UPDATE vocabularios ";
      cmdSql_ += "SET administrador = '" + dev.GetEmail().GetEmail();
      cmdSql_ += "' WHERE nome =      '" + voc.GetNome().GetNome() + "';";
    }

    // vai atualizar a definicao do termo passado
    explicit ComandoSqlAtualizar(const Definicao &def, const Termo &termo) {
      cmdSql_ = "UPDATE definicao ";
      cmdSql_ += "SET texto  = '" + def.GetDefinicao().GetDefinicao();
      cmdSql_ += "', data    = '" + def.GetData().GetData();
      cmdSql_ += "' WHERE termo = '" + termo.GetNome().GetNome() + "';";
    }

    // vai atualizar a definicao do vocabulario passado
    explicit ComandoSqlAtualizar(const Definicao &def, const VocabularioControlado &voc) {
      cmdSql_ = "UPDATE definicao ";
      cmdSql_ += "SET texto           = '" + def.GetDefinicao().GetDefinicao();
      cmdSql_ += "', data             = '" + def.GetData().GetData();
      cmdSql_ += "' WHERE vocabulario = '" + voc.GetNome().GetNome() + "';";
    }

    // vai atualizar o termo do vocabulario passado
    explicit ComandoSqlAtualizar(const Termo &termo, const VocabularioControlado &voc) {
      cmdSql_ = "UPDATE termos ";
      cmdSql_ += "SET classe =    '" + termo.GetPreferencia().GetPreferencia();
      cmdSql_ += "', data =       '" + termo.GetData().GetData();
      cmdSql_ += "' WHERE vocabulario = '" + voc.GetNome().GetNome() + "';";
    }
};

class ComandoSqlAssociar : public ComandoSql {
  public:
    ComandoSqlAssociar() = default;
    explicit ComandoSqlAssociar(const Email &email, const VocabularioControlado &voc) {
      cmdSql_ = "INSERT or IGNORE INTO desenvolvedor_vocabulario (desenvolvedor, vocabulario)"\
      " VALUES (";
      cmdSql_ += "'" + email.GetEmail() +                          "', ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "');";
    }

    explicit ComandoSqlAssociar(const Termo &termo, const Definicao & def) {
      cmdSql_ = "INSERT or IGNORE INTO termo_definicao (termo, definicao)"\
      " VALUES (";
      cmdSql_ += "'" + termo.GetNome().GetNome() +         "', ";
      cmdSql_ += "'" + def.GetDefinicao().GetDefinicao() + "');";
    }
};

class ComandoSqlCriarTabelas : public ComandoSql {
  public:
    explicit ComandoSqlCriarTabelas(); 
};

class ComandoSqlLerSenha : public ComandoSql {
  public:
    ComandoSqlLerSenha() = default;
    explicit ComandoSqlLerSenha(const Email &email) {
      cmdSql_  = "SELECT senha FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }

    string RecuperaSenha() const;
};

class ComandoSqlLerEmail : public ComandoSql {
  public:
    ComandoSqlLerEmail() = default;
    explicit ComandoSqlLerEmail(const Email &email) {
      cmdSql_  = "SELECT email FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }
    string RecuperaEmail() const;
};

class ComandoSqlTipoConta : public ComandoSql {
  public:
    ComandoSqlTipoConta() = default;
    explicit ComandoSqlTipoConta(const Email &email) {
      cmdSql_ = "SELECT conta FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }
    string RecuperaConta() const;
};

class ComandoSqlPesquisarUsuario : public ComandoSql {
  public:
    ComandoSqlPesquisarUsuario() = default;
    explicit ComandoSqlPesquisarUsuario(const Email &email) {
      cmdSql_  = "SELECT * FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }

    Leitor GetLeitor() const;
    Desenvolvedor GetDev() const;
    Administrador GetAdm() const;
};

class ComandoSqlConsultarVocabs : public ComandoSql {
  public:
    // seleciona todos os vocabularios que existem, basicamente essa é a função para o leitor
    explicit ComandoSqlConsultarVocabs() {
      cmdSql_  = "SELECT nome, idioma, data FROM vocabularios;";
    }

    // seleciona todos os vocabularios que estão associados com o email do administrador
    explicit ComandoSqlConsultarVocabs(const Administrador &adm) {
      cmdSql_  = "SELECT nome, idioma, data FROM vocabularios WHERE administrador = ";
      cmdSql_ += "'" + adm.GetEmail().GetEmail() + "';";
    }

    // seleciona todos os vocabularios que estão associados com o email do desenvolvedor
    explicit ComandoSqlConsultarVocabs(const Desenvolvedor &dev) {
      cmdSql_  = "SELECT nome, idioma, data FROM vocabularios WHERE desenvolvedor = ";
      cmdSql_ += "'" + dev.GetEmail().GetEmail() + "';";
    }

    vector<VocabularioControlado> GetVocabs();
};

class ComandoSqlConsultarTermos : public ComandoSql {
  public:
    ComandoSqlConsultarTermos() = default;
    explicit ComandoSqlConsultarTermos(const VocabularioControlado &voc) {
      cmdSql_  = "SELECT nome, classe, data FROM termos WHERE vocabulario = ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "';";
    }

    vector<Termo> GetTermos();
};

class ComandoSqlConsultarDefinicao : public ComandoSql {
  public:
    explicit ComandoSqlConsultarDefinicao() {
      cmdSql_  = "SELECT texto, data FROM definicoes;";
    }

    explicit ComandoSqlConsultarDefinicao(const Termo &termo) {
      cmdSql_  = "SELECT texto, data FROM definicoes WHERE termo = ";
      cmdSql_ += "'" + termo.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlConsultarDefinicao(const VocabularioControlado &voc) {
      cmdSql_  = "SELECT texto, data FROM definicoes WHERE vocabulario = ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "';";
    }

    vector<Definicao> GetDefinicoes();
};

class ComandoSqlRemover : public ComandoSql {
  public:
    ComandoSqlRemover() = default;
    explicit ComandoSqlRemover(const Email &email) {
      cmdSql_  = "DELETE FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }

    explicit ComandoSqlRemover(const VocabularioControlado &voc) {
      cmdSql_  = "DELETE FROM vocabularios WHERE nome = ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlRemover(const Termo &termo) {
      cmdSql_  = "DELETE FROM termos WHERE nome = ";
      cmdSql_ += "'" + termo.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlRemover(const Termo &termo, const VocabularioControlado &voc) {
      cmdSql_  = "DELETE FROM termos WHERE vocabulario = ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlRemover(const Definicao &def, const Termo &termo) {
      cmdSql_  = "DELETE FROM vocabularios WHERE termo = ";
      cmdSql_ += "'" + termo.GetNome().GetNome() + "';";
    }

    explicit ComandoSqlRemover(const Definicao &def, const VocabularioControlado &voc) {
      cmdSql_  = "DELETE FROM definicao WHERE vocabulario = ";
      cmdSql_ += "'" + voc.GetNome().GetNome() + "';";
    }
};

#endif  //TRABALHO__CMDSQL__H__
