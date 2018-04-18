#include "testes.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void Teste::RunTestes() {
    cout << "\tRodando testes de unidade dos Dominios\n\n";

    switch(teste_unidade_nome_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Nome\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Nome\n";
            break;
        }
    }

    switch(teste_unidade_sobrenome_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Sobrenome\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Sobrenome\n";
            break;
        }
    }

    switch(teste_unidade_senha_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade da Senha\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade da Senha\n";
            break;
        }
    }

    switch(teste_unidade_endereco_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Endereco\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Endereco\n";
            break;
        }
    }

    switch(teste_unidade_email_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Email\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Email\n";
            break;
        }
    }

    switch(teste_unidade_data_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade da Data\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade da Data\n";
            break;
        }
    }

    switch(teste_unidade_telefone_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Telefone\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Telefone\n";
            break;
        }
    }

    switch(teste_unidade_texto_definicao_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade de Definicao\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade de Definicao\n";
            break;
        }
    }

    switch(teste_unidade_idioma_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade de Idioma\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade de Idioma\n";
            break;
        }
    }

    switch(teste_unidade_preferencia_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade de Preferencia\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade de Preferencia\n";
            break;
        }
    }

    cout << "\n\tRodando testes de unidade das Entidades\n\n";

    switch(teste_unidade_leitor_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Leitor\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Leitor\n";
            break;
        }
    }

    switch(teste_unidade_desenvolvedor_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Desenvolvedor\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Desenvolvedor\n";
            break;
        }
    }

    switch(teste_unidade_administrador_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Administrador\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Administrador\n";
            break;
        }
    }

    switch(teste_unidade_termo_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Termo\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Termo\n";
            break;
        }
    }

    switch(teste_unidade_vocabulario_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade do Vocabulario\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade do Vocabulario\n";
            break;
        }
    }

    switch(teste_unidade_definicao_->Run()) {
        case true: {
            cout << "Sucesso no teste de unidade de Definicao\n";
            break;
        }
        case false: {
            cout << "Falha no teste de unidade de Definicao\n";
            break;
        }
    }
}

void Teste::SetUpTestes() {
    teste_unidade_administrador_   = new TUAdministrador();
    teste_unidade_data_            = new TUData();
    teste_unidade_definicao_       = new TUDefinicao();
    teste_unidade_desenvolvedor_   = new TUDesenvolvedor();
    teste_unidade_email_           = new TUEmail();
    teste_unidade_endereco_        = new TUAddress();
    teste_unidade_idioma_          = new TUIdioma();
    teste_unidade_leitor_          = new TULeitor();
    teste_unidade_nome_            = new TUNome();
    teste_unidade_preferencia_     = new TUPreferencia();
    teste_unidade_senha_           = new TUSenha();
    teste_unidade_sobrenome_       = new TUSobrenome();
    teste_unidade_telefone_        = new TUTelefone();
    teste_unidade_termo_           = new TUTermo();
    teste_unidade_vocabulario_     = new TUVocabulario();
    teste_unidade_definicao_       = new TUDefinicao();
    teste_unidade_texto_definicao_ = new TUTextoDefinicao();
}

void Teste::Execute() {
    SetUpTestes();
    RunTestes();
    Destroy();
}

