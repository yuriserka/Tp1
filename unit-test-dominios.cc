#include "unit-test-dominios.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void TUNome::FailTest() {
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

void TUNome::SuccessTest() {
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

bool TUNome::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUSobrenome::FailTest() {
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

void TUSobrenome::SuccessTest() {
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

bool TUSobrenome::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUSenha::FailTest() {
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

void TUSenha::SuccessTest() {
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

bool TUSenha::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUData::FailTest() {
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

void TUData::SuccessTest() {
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

bool TUData::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUEmail::FailTest() {
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

void TUEmail::SuccessTest() {
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

bool TUEmail::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUTelefone::FailTest() {
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

void TUTelefone::SuccessTest() {
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

bool TUTelefone::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUAddress::FailTest() {
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

void TUAddress::SuccessTest() {
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

bool TUAddress::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUTextoDefinicao::FailTest() {
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

void TUTextoDefinicao::SuccessTest() {
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
 
bool TUTextoDefinicao::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUIdioma::FailTest() {
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

void TUIdioma::SuccessTest() {
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

bool TUIdioma::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

void TUPreferencia::FailTest() {
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

void TUPreferencia::SuccessTest() {
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

bool TUPreferencia::Run() {
    SetUp();
    SuccessTest();
    FailTest();
    Destroy();
    return estado_;
}

