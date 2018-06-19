#include "../cabecalhos/includes.h"

void TUNome::CasoFalha() {
  try {
    nome_->SetNome(knome_invalido_1_);
    estado_ = false;
    nome_->SetNome(knome_invalido_2_);
    estado_ = false;
    nome_->SetNome(knome_invalido_3_);
    estado_ = false;
    nome_->SetNome(knome_invalido_4_);
    estado_ = false;
    nome_->SetNome(knome_invalido_5_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUNome::CasoSucesso() {
  try {
    nome_->SetNome(knome_valido_);
    if (nome_->GetNome() != knome_valido_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUSobrenome::CasoFalha() {
  try {
    sobrenome_->SetSobrenome(ksobrenome_invalido_1_);
    estado_ = false;
    sobrenome_->SetSobrenome(ksobrenome_invalido_2_);
    estado_ = false;
    sobrenome_->SetSobrenome(ksobrenome_invalido_3_);
    estado_ = false;
    sobrenome_->SetSobrenome(ksobrenome_invalido_4_);
    estado_ = false;
    sobrenome_->SetSobrenome(ksobrenome_invalido_5_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUSobrenome::CasoSucesso() {
  try {
    sobrenome_->SetSobrenome(ksobrenome_valido_);
    if (sobrenome_->GetSobrenome() != ksobrenome_valido_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUSenha::CasoFalha() {
  try {
    senha_->SetSenha(ksenha_invalida_1_);
    estado_ = false;
    senha_->SetSenha(ksenha_invalida_2_);
    estado_ = false;
    senha_->SetSenha(ksenha_invalida_3_);
    estado_ = false;
    senha_->SetSenha(ksenha_invalida_4_);
    estado_ = false;
    senha_->SetSenha(ksenha_invalida_5_);
    estado_ = false;
    senha_->SetSenha(ksenha_invalida_6_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUSenha::CasoSucesso() {
  try {
    senha_->SetSenha(ksenha_valida_);
    if (senha_->GetSenha() != ksenha_valida_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUData::CasoFalha() {
  try {
    data_->SetData(kdata_invalida_1_);
    estado_ = false;
    data_->SetData(kdata_invalida_2_);
    estado_ = false;
    data_->SetData(kdata_invalida_3_);
    estado_ = false;
    data_->SetData(kdata_invalida_4_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUData::CasoSucesso() {
  try {
    data_->SetData(kdata_valida_);
    if (data_->GetData() != kdata_valida_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUEmail::CasoFalha() {
  try {
    email_->SetEmail(kemail_invalido_1_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_2_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_3_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_4_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_5_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_6_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_7_);
    estado_ = false;
    email_->SetEmail(kemail_invalido_8_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUEmail::CasoSucesso() {
  try {
    email_->SetEmail(kemail_valido_);
    if (email_->GetEmail() != kemail_valido_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUTelefone::CasoFalha() {
  try {
    telefone_->SetTelefone(ktelefone_invalido_1_);
    estado_ = false;
    telefone_->SetTelefone(ktelefone_invalido_2_);
    estado_ = false;
    telefone_->SetTelefone(ktelefone_invalido_3_);
    estado_ = false;
    telefone_->SetTelefone(ktelefone_invalido_4_);
    estado_ = false;
    telefone_->SetTelefone(ktelefone_invalido_5_);
    estado_ = false;
    telefone_->SetTelefone(ktelefone_invalido_6_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUTelefone::CasoSucesso() {
  try {
    telefone_->SetTelefone(telefone_valido);
    if (telefone_->GetTelefone() != telefone_valido) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUAddress::CasoFalha() {
  try {
    endereco_->SetAddress(kendereco_invalido_1_);
    estado_ = false;
    endereco_->SetAddress(kendereco_invalido_2_);
    estado_ = false;
    endereco_->SetAddress(kendereco_invalido_3_);
    estado_ = false;
    endereco_->SetAddress(kendereco_invalido_4_);
    estado_ = false;
    endereco_->SetAddress(kendereco_invalido_5_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUAddress::CasoSucesso() {
  try {
    endereco_->SetAddress(kendereco_valido_);
    if (endereco_->GetAddress() != kendereco_valido_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUTextoDefinicao::CasoFalha() {
  try {
    texto_->SetDefinicao(kdefinicao_invalida_1_);
    estado_ = false;
    texto_->SetDefinicao(kdefinicao_invalida_2_);
    estado_ = false;
    texto_->SetDefinicao(kdefinicao_invalida_3_);
    estado_ = false;
    texto_->SetDefinicao(kdefinicao_invalida_4_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUTextoDefinicao::CasoSucesso() {
  try {
    texto_->SetDefinicao(kdefinicao_valida_);
    if (texto_->GetDefinicao() != kdefinicao_valida_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUIdioma::CasoFalha() {
  try {
    idioma_->SetIdioma(kidioma_invalido_1_);
    estado_ = false;
    idioma_->SetIdioma(kidioma_invalido_2_);
    estado_ = false;
    idioma_->SetIdioma(kidioma_invalido_3_);
    estado_ = false;
    idioma_->SetIdioma(kidioma_invalido_4_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUIdioma::CasoSucesso() {
  try {
    idioma_->SetIdioma(kidioma_valido_);
    if (idioma_->GetIdioma() != kidioma_valido_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUPreferencia::CasoFalha() {
  try {
    preferido_->SetPreferencia(kpreferencia_invalida_1_);
    estado_ = false;
    preferido_->SetPreferencia(kpreferencia_invalida_2_);
    estado_ = false;
    preferido_->SetPreferencia(kpreferencia_invalida_3_);
    estado_ = false;
    preferido_->SetPreferencia(kpreferencia_invalida_4_);
    estado_ = false;
  }
  catch (exception &e) {
    return;
  }
}

void TUPreferencia::CasoSucesso() {
  try {
    preferido_->SetPreferencia(kpreferencia_valida_);
    if (preferido_->GetPreferencia() != kpreferencia_valida_) {
      estado_ = false;
    }
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    estado_ = false;
  }
}

void TUDominios::RunDominios() {
  SetUpDominios();
  cout << "\tRodando testes de unidade dos Dominios\n\n";

  switch (teste_unidade_nome_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Nome\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Nome\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_sobrenome_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Sobrenome\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Sobrenome\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_senha_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade da Senha\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade da Senha\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_endereco_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Endereco\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Endereco\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_email_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Email\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Email\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_data_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade da Data\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade da Data\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_telefone_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade do Telefone\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade do Telefone\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_texto_definicao_->Run()) {
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

  switch (teste_unidade_idioma_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade de Idioma\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade de Idioma\n";
      break;
    }
    default:break;
  }

  switch (teste_unidade_preferencia_->Run()) {
    case true: {
      cout << "Sucesso no teste de unidade de Preferencia\n";
      break;
    }
    case false: {
      cout << "Falha no teste de unidade de Preferencia\n";
      break;
    }
    default:break;
  }
  DestroyDominios();
}

