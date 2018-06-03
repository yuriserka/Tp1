#ifndef TRABALHO__SERVICOS__H__
#define TRABALHO__SERVICOS__H__

#include "includes.h"

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
  ResultadoUsuario CadastrarLeitor(Leitor &, const Nome &,
                            const Sobrenome &, const Senha &, const Email &) override;
                            
  ResultadoUsuario CadastrarDev(Desenvolvedor &, const Nome &,
                         const Sobrenome &, const Senha &, const Email &, const Data &) override;

  ResultadoUsuario CadastrarAdm(Administrador &, const Nome &,
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

#endif //TRABALHO__SERVICOS__H__