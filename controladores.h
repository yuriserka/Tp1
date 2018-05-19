#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "interfaces.h"
#include "stubs.h"

/**
 * @file 
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief
 * 
 */

/**
 * @brief 
 * 
 */
class CtrlApresentacaoControle : public InterfaceApresentacaoControle {
 public:
  /**
   * @brief 
   * 
   */
  void Inicializar() override;

  /**
   * @brief 
   * 
   */
  void ControleLogado(const Email &) override;

  /**
   * @brief Set the Ctrl Autenticacao object
   * 
   * @param iaa 
   */
  inline void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
    this->ctrl_aa = iaa;
  }

  /**
   * @brief Set the Ctrl Apresentacao Cadastro object
   * 
   * @param iac 
   */
  inline void SetCtrlApresentacaoCadastro(InterfaceApresentacaoCadastro *iac) override {
    this->ctrl_ac = iac;
  }

  /**
   * @brief Set the Ctrl Apresentacao Usuario object
   * 
   * @param iau 
   */
  inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override {
    this->ctrl_au = iau;
  }

  /**
   * @brief Set the Ctrl Apresentacao Vocabulario object
   * 
   * @param iav 
   */
  inline void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *iav) override {
    this->ctrl_av = iav;
  }

 private:
  InterfaceApresentacaoAutenticacao *ctrl_aa;
  InterfaceApresentacaoUsuario *ctrl_au;
  InterfaceApresentacaoVocabulario *ctrl_av;
  InterfaceApresentacaoCadastro *ctrl_ac;

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
 * @brief 
 * 
 */
class CtrlApresentacaoCadastro : public InterfaceApresentacaoCadastro {
  public:
    /**
    * @brief 
    * 
    * @return Resultado 
    */
    void Cadastrar() override;

    /**
     * @brief Set the Ctrl Servico Cadastro object
     * 
     * @param isc 
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
 * @brief 
 * 
 */
class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
 public:
  /**
   * @brief 
   * 
   * @return ResultadoAutenticar 
   */
  ResultadoAutenticar Autenticar() override;

  /**
   * @brief Set the Ctrl Servico Autenticacao object
   * 
   * @param isa 
   */
  inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
    this->ctrl_servico_autenticacao_ = isa;
  }

 private:
  InterfaceServicoAutenticacao *ctrl_servico_autenticacao_;
};

/**
 * @brief 
 * 
 */
class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario {
 public:
  /**
   * @brief 
   * 
   * @param _email 
   * @return ResultadoUsuario 
   */
  Resultado Executar(const Email &_email) override;

  /**
   * @brief Set the Ctrl Servico Usuario object
   * 
   * @param isu 
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
 * @brief 
 * 
 */
class CtrlApresentacaoVocabulario : public InterfaceApresentacaoVocabulario {
 public:
  /**
   * @brief 
   * 
   * @param email 
   */
  void Executar(const Email &email) override;

  /**
   * @brief Set the Ctrl Servico Vocabulario object
   * 
   * @param isv 
   */
  void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *isv) override {
    this->ctrl_servico_vocabulario_ = isv;
  }

 private:
  InterfaceServicoVocabulario *ctrl_servico_vocabulario_;
};

#endif // TRABALHO__CONTROLADORAS__H__

