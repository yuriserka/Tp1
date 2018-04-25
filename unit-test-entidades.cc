#include "unit-test-entidades.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void TULeitor::FailTest() {
  try {
    leitor_invalido_ = new Leitor(knome_valido_, ksobrenome_valido_, ksenha_invalida_, kemail_valido_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TULeitor::SuccessTest() {
  try {
    if (leitor_valido_->GetNome().GetNome() != knome_valido_.GetNome()) {
      estado_ = false;
    }
    if (leitor_valido_->GetSobrenome().GetSobrenome() != ksobrenome_valido_.GetSobrenome()) {
      estado_ = false;
    }
    if (leitor_valido_->GetSenha().GetSenha() != ksenha_valida_.GetSenha()) {
      estado_ = false;
    }
    if (leitor_valido_->GetEmail().GetEmail() != kemail_valido_.GetEmail()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TULeitor::Run() {
  SetUp();
  SuccessTest();
  FailTest();
  Destroy();
  return estado_;
}

void TUDesenvolvedor::FailTest() {
  try {
    desenvolvedor_invalido = new Desenvolvedor(knome_valido_, ksobrenome_valido_,
                                               ksenha_invalida_, kemail_valido_, kdata_valida_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUDesenvolvedor::SuccessTest() {
  try {
    if (desenvolvedor_valido->GetNome().GetNome() != knome_valido_.GetNome()) {
      estado_ = false;
    }
    if (desenvolvedor_valido->GetSobrenome().GetSobrenome() != ksobrenome_valido_.GetSobrenome()) {
      estado_ = false;
    }
    if (desenvolvedor_valido->GetSenha().GetSenha() != ksenha_valida_.GetSenha()) {
      estado_ = false;
    }
    if (desenvolvedor_valido->GetEmail().GetEmail() != kemail_valido_.GetEmail()) {
      estado_ = false;
    }
    if (desenvolvedor_valido->GetDataDeNascimento().GetData() != kdata_valida_.GetData()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TUDesenvolvedor::Run() {
  SetUp();
  SuccessTest();
  FailTest();
  Destroy();
  return estado_;
}

void TUAdministrador::FailTest() {
  try {
    admin_invalido = new Administrador(knome_valido_, ksobrenome_valido_, ksenha_invalida_, kemail_valido_,
                                       kdata_valida_, telefone_valido, kendereco_valido_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUAdministrador::SuccessTest() {
  try {
    if (admin_valido->GetNome().GetNome() != knome_valido_.GetNome()) {
      estado_ = false;
    }
    if (admin_valido->GetSobrenome().GetSobrenome() != ksobrenome_valido_.GetSobrenome()) {
      estado_ = false;
    }
    if (admin_valido->GetSenha().GetSenha() != ksenha_valida_.GetSenha()) {
      estado_ = false;
    }
    if (admin_valido->GetEmail().GetEmail() != kemail_valido_.GetEmail()) {
      estado_ = false;
    }
    if (admin_valido->GetDataDeNascimento().GetData() != kdata_valida_.GetData()) {
      estado_ = false;
    }
    if (admin_valido->GetTelefone().GetTelefone() != telefone_valido.GetTelefone()) {
      estado_ = false;
    }
    if (admin_valido->GetEndereco().GetAddress() != kendereco_valido_.GetAddress()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TUAdministrador::Run() {
  SetUp();
  SuccessTest();
  FailTest();
  Destroy();
  return estado_;
}

void TUVocabulario::SuccessTest() {
  try {
    if (valido_->GetNome().GetNome() != knome_valido_.GetNome()) {
      estado_ = false;
    }
    if (valido_->GetIdioma().GetIdioma() != kidioma_valido_.GetIdioma()) {
      estado_ = false;
    }
    if (valido_->GetData().GetData() != kdata_valida_.GetData()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TUVocabulario::Run() {
  SetUp();
  SuccessTest();
  Destroy();
  return estado_;
}

void TUTermo::SuccessTest() {
  try {
    if (valido_->GetNome().GetNome() != knome_valido_.GetNome()) {
      estado_ = false;
    }
    if (valido_->GetPreferencia().GetPreferencia() != kclasse_valida_.GetPreferencia()) {
      estado_ = false;
    }
    if (valido_->GetData().GetData() != kdata_valida_.GetData()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TUTermo::Run() {
  SetUp();
  SuccessTest();
  Destroy();
  return estado_;
}

void TUDefinicao::SuccessTest() {
  try {
    if (valido_->GetDefinicao().GetDefinicao() != kdefinicao_valida_.GetDefinicao()) {
      estado_ = false;
    }
    if (valido_->GetData().GetData() != kdata_valida_.GetData()) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

int TUDefinicao::Run() {
  SetUp();
  SuccessTest();
  Destroy();
  return estado_;
}


