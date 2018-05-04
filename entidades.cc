#include "entidades.h"

void Leitor::ValidaSenhaEntidades(const Senha &senha) {
  string _nome = nome_.GetNome();
  string _senha = senha.GetSenha();

  _nome[0] += ' ';

  for (char &i : _senha) {
    if (i >= 'A' && i <= 'Z') {
      i += ' ';
    }
  }

  if (_senha.find(_nome) < _senha.size()) {
    throw invalid_argument("A senha nao pode conter o nome do usuario.\n");
  }
}

void Leitor::SetSenha(const Senha &_senha) {
  ValidaSenhaEntidades(_senha);
  this->senha_ = _senha;
}
