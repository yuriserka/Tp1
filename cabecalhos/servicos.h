#ifndef TRABALHO__SERVICOS__H__
#define TRABALHO__SERVICOS__H__

#include "../cabecalhos/../cabecalhos/includes.h"

class CtrlServicoControle : public InterfaceServicoControle {
  public:
    void Construir() override;
};

class CtrlServicoAutenticacao : public InterfaceServicoAutenticacao {
  public:
    Resultado Autenticar(const Email &, const Senha &) override;
};

class CtrlServicoCadastro : public InterfaceServicoCadastro {
  public: 
  Resultado CadastrarLeitor(Leitor &, const Nome &,
                            const Sobrenome &, const Senha &, const Email &) override;
                            
  Resultado CadastrarDev(Desenvolvedor &, const Nome &,
                         const Sobrenome &, const Senha &, const Email &, const Data &) override;

  Resultado CadastrarAdm(Administrador &, const Nome &,
                         const Sobrenome &, const Senha &, const Email &, const Data &,
                         const Telefone &, const Address &) override;
};

class CtrlServicoUsuario : public InterfaceServicoUsuario {
  public:

  void Exibir(const Leitor &) override;
  void Exibir(const Desenvolvedor &) override;
  void Exibir(const Administrador &) override;

  ResultadoUsuario Editar(const Leitor &) override;
  ResultadoUsuario Editar(const Desenvolvedor &) override;
  ResultadoUsuario Editar(const Administrador &) override;

  Resultado Excluir(const Email &) override;
 private:
  ResultadoUsuario AtualizaLeitor(const Email &email);
  ResultadoUsuario AtualizaDesenvolvedor(const Email &email);
  ResultadoUsuario AtualizaAdministrador(const Email &email);
};

class CtrlServicoVocabulario : public InterfaceServicoVocabulario {
  vector<VocabularioControlado> ConsultarVocabularios() override;

  vector<Termo> ConsultarTermos(const VocabularioControlado &voc) override;

  vector<Termo> ConsultarTermos() override;

  vector<Definicao> ConsultarDefinicao(const Termo &) override;

  Definicao ConsultarDefinicao(const VocabularioControlado &) override;

  vector<Definicao> ConsultarDefinicoes() override;

  Resultado CadastrarDesenvolvedor(const VocabularioControlado &, const Email &) override;

  Resultado CadastrarAdministrador(const VocabularioControlado &, const Email &) override;


  Resultado CriarTermo(Termo &, 
                      const Nome &, 
                      const ClasseDoTermo &,
                      const Data &, 
                      const VocabularioControlado &) override;

  Resultado EditarTermo(Termo &, const Data &) override;

  Resultado ExcluirTermo(const Termo &) override;

  Resultado CriarDefinicao(Definicao &, 
                          const TextoDefinicao &, 
                          const Data &) override;

  Resultado EditarDefinicao(Definicao &, const Data &) override;

  Resultado ExcluirDefinicao(const Definicao &) override;

  Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
                        const Idioma &, const Data &, const Definicao &, const Email &) override;

  Resultado EditarVocabulario(VocabularioControlado &, const Idioma &, 
                              const Data &) override;

  Resultado ExcluirVocabulario(const VocabularioControlado &) override;

  Resultado AssociarTermoDefinicao(const Termo &, const Definicao &) override;
};

#endif //TRABALHO__SERVICOS__H__