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
  inline void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
    this->ctrl_apresentacao_autenticacao_ = iaa;
  }

  /**
   * @brief Set the Ctrl Apresentacao Usuario object
   * 
   * @param iau 
   */
  inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override {
    this->ctrl_apresentacao_usuario_ = iau;
  }

  /**
   * @brief Set the Ctrl Apresentacao Vocabulario object
   * 
   * @param iav 
   */
  inline void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *iav) override {
    this->ctrl_apresentacao_vocabulario_ = iav;
  }

 private:
  InterfaceApresentacaoAutenticacao *ctrl_apresentacao_autenticacao_;
  InterfaceApresentacaoUsuario *ctrl_apresentacao_usuario_;
  InterfaceApresentacaoVocabulario *ctrl_apresentacao_vocabulario_;
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
  ResultadoUsuario Executar(const Email &_email) override;

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
  Resultado ShowDados(const Email &, InterfaceServicoUsuario *);
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

