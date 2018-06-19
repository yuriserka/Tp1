#include "../cabecalhos/includes.h"

void TULeitor::CasoFalha() {
  try {
    leitor_invalido_ = new Leitor(knome_valido_, ksobrenome_valido_, ksenha_invalida_, kemail_valido_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TULeitor::CasoSucesso() {
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

void TUDesenvolvedor::CasoFalha() {
  try {
    desenvolvedor_invalido = new Desenvolvedor(knome_valido_, ksobrenome_valido_,
                                               ksenha_invalida_, kemail_valido_, kdata_valida_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUDesenvolvedor::CasoSucesso() {
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

void TUAdministrador::CasoFalha() {
  try {
    admin_invalido = new Administrador(knome_valido_, ksobrenome_valido_, ksenha_invalida_, kemail_valido_,
                                       kdata_valida_, telefone_valido, kendereco_valido_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUAdministrador::CasoSucesso() {
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

void TUVocabulario::CasoSucesso() {
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

void TUTermo::CasoSucesso() {
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

void TUDefinicao::CasoSucesso() {
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

void TUEntidades::RunEntidades() {
  SetUpEntidades();
  cout << "\n\tRodando testes de unidade das Entidades\n\n";

  switch (teste_unidade_leitor_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Leitor\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Leitor\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_desenvolvedor_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Desenvolvedor\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Desenvolvedor\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_administrador_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Administrador\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Administrador\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_termo_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Termo\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Termo\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_vocabulario_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Vocabulario\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Vocabulario\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_definicao_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade de Definicao\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade de Definicao\n";
      break;
    }
    default:break;
  }
  DestroyEntidades();
}

