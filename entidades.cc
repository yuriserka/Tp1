#include "entidades.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void Leitor::ValidaSenhaEntidades(const Senha &senha) {
    string _nome = nome_.GetNome();
    string _senha = senha.GetSenha();

    _nome[0] += ' ';

    for (unsigned i = 0; i < _senha.size(); i++) {
        if(_senha[i] >= 'A' && _senha[i] <= 'Z') {
            _senha[i] += ' ';
        }
    }

    if(_senha.find(_nome) < _senha.size()) {
        throw invalid_argument("A senha nao pode conter o nome do usuario.\n");
    }
}

void Leitor::SetSenha(const Senha &_senha) {
    ValidaSenhaEntidades(_senha);
    this->senha_ = _senha;
}
