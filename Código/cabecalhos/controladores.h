#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file controladores.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief Classes de controle de fluxo do programa.
 * 
 * Neste arquivo estão as classes que irão controlar o fluxo do programa.
 * 
 */

/**
 * @brief Classe que será responsavel pelo controle principal do programa.
 * 
 */
class CtrlApresentacaoControle : public InterfaceApresentacaoControle {
 public:
  /**
   * @brief implementa a classe base e inicializa o programa.
   * 
   */
  void Inicializar() override;

  /**
   * @brief implementa a classe base e vai para um menu apos ser logado
   * com sucesso.
   * 
   */
  void ControleLogado(const Email &) override;

  /**
   * @brief Seta o controle para a parte de apresentação autenticação.
   * 
   * @param iaa objeto de alguma classe derivada da interface de apresentação autentcação.
   */
  inline void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
    this->ctrl_aa = iaa;
  }

  /**
   * @brief Seta o controle para a parte de apresentação cadastro.
   * 
   * @param iac objeto de alguma classe derivada da interface de apresentação cadastro.
   */
  inline void SetCtrlApresentacaoCadastro(InterfaceApresentacaoCadastro *iac) override {
    this->ctrl_ak = iac;
  }

  /**
   * @brief Seta o controle para a parte de apresentação usuario.
   * 
   * @param iau objeto de alguma classe derivada da interface de apresentação usuario.
   */
  inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override {
    this->ctrl_au = iau;
  }

  /**
   * @brief Seta o controle para a parte de apresentação vocabulário.
   * 
   * @param iav objeto de alguma classe derivada da interface de apresentação vocabulario.
   */
  inline void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *iav) override {
    this->ctrl_av = iav;
  }

 private:
  InterfaceApresentacaoAutenticacao *ctrl_aa;
  InterfaceApresentacaoCadastro *ctrl_ak;
  InterfaceApresentacaoUsuario *ctrl_au;
  InterfaceApresentacaoVocabulario *ctrl_av;

  enum Controle {
    knullc,
    kentrar,
    kcadastrar,
    ksair
  };

  enum ControleLogado {
    knullcl,
    kgestao_usuario,
    kgestao_vocabulo,
    kvoltar
  };
};

/**
 * @brief Classe que será responsável pela parte de autenticação de usuarios.
 * 
 */
class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
 public:
  /**
   * @brief implementa a classe base e autentica os dados do usuario.
   * 
   * @return ResultadoAutenticar retorna um objeto que conterá email e 
   * um resultado que representará sucesso ou falha.
   */
  ResultadoAutenticar Autenticar() override;

  /**
   * @brief Seta o controle para a parte de serviço de autenticação.
   * 
   * @param isa objeto de alguma classe derivada da interface de serviço
   * de autenticação.
   */
  inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
    this->ctrl_servico_autenticacao_ = isa;
  }

 private:
  InterfaceServicoAutenticacao *ctrl_servico_autenticacao_;
};

/**
 * @brief Classe que será responsável pela parte de cadastramento de usuarios.
 * 
 */
class CtrlApresentacaoCadastro : public InterfaceApresentacaoCadastro {
 public:
  /**
  * @brief implementa a classe base e cadastra um usuario.
  *
  */
  void Cadastrar() override;

  /**
   * @brief Seta o controle para a parte de serviço de cadastro.
   *
   * @param isc objeto de alguma classe derivada da interface de serviço de cadastro.
   */
  inline void SetCtrlServicoCadastro(InterfaceServicoCadastro *isc) override {
    this->ctrl_servico_cadastro_ = isc;
  }

 private:
  InterfaceServicoCadastro *ctrl_servico_cadastro_;
  enum Cadastro {
    knull,
    kadm,
    kdev,
    kleitor,
    kvoltar
  };
};

/**
 * @brief Classe que será responsável pela parte de gestão de usuarios.
 * 
 */
class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario {
 public:
  /**
   * @brief implementa a classe base e vai para a tela de gestão de usuarios.
   * 
   * @return Resultado retorna um objeto que poderá dizer se foi sucesso 
   * ou falha. 
   */
  Resultado Executar(const Email &) override;

  /**
   * @brief Seta o controle para a parte de serviço de usuario.
   * 
   * @param isu objeto de alguma classe derivada da interface de serviço de usuario.
   */
  void inline SetCtrlServicoUsuario(InterfaceServicoUsuario *isu) override {
    this->ctrl_servico_usuario_ = isu;
  }

 private:
  InterfaceServicoUsuario *ctrl_servico_usuario_;
  enum {
    knull,
    keditar,
    kexcluir,
    kvoltar
  };
};

/**
 * @brief Classe que implementa a InterfaceServicoVocabulario responsável pela parte de gestão dos vocabulários.
 * 
 */
class CtrlApresentacaoVocabulario : public InterfaceApresentacaoVocabulario {
 public:
  /**
   * @brief função herdada que direciona para a tela de gestão de vocabularios.
   * 
   */
  void Executar(const Email &) override;

  /**
   * @brief função herdada que seta o controle para a interface de serviço de vocabulário.
   * 
   * @param isv objeto da classe InterfaceServicoVocabulario.
   */
  void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *isv) override {
    this->ctrl_servico_vocabulario_ = isv;
  }

 private:
  InterfaceServicoVocabulario *ctrl_servico_vocabulario_;
};

#endif // TRABALHO__CONTROLADORAS__H__

