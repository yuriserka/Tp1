#include "dominios.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void Nome::ValidaNome(string _nome) {
  if (_nome.size() <= kmin_nome_size_) {
    throw invalid_argument("Nome muito pequeno.\n");
  }

  if (_nome.size() > kmax_nome_size_) {
    throw invalid_argument("Nome muito extenso.\n");
  }

  if (_nome[0] < 'A' || _nome[0] > 'Z') {
    throw invalid_argument("A primeira letra do nome deve ser maiuscula.\n");
  }

  for (char i : _nome) {
    if (i >= '0' && i <= '9') {
      throw invalid_argument("Nao sao permitidos numeros no nome.\n");
    }
  }
}

void Nome::SetNome(string _nome) {
  ValidaNome(_nome);
  this->nome_ = _nome;
}

void Sobrenome::ValidaSobrenome(string _sobrenome) {
  if (_sobrenome.size() <= kmin_sobrenome_size_) {
    throw invalid_argument("Sobrenome muito pequeno.\n");
  }

  if (_sobrenome.size() > kmax_sobrenome_size_) {
    throw invalid_argument("Sobrenome muito extenso.\n");
  }

  if (_sobrenome[0] < 'A' || _sobrenome[0] > 'Z') {
    throw invalid_argument("A primeira letra do sobrenome deve ser maiuscula.\n");
  }

  for (char i : _sobrenome) {
    if (i >= '0' && i <= '9') {
      throw invalid_argument("Nao sao permitidos numeros no sobrenome.\n");
    }
  }
}

void Sobrenome::SetSobrenome(string _sobrenome) {
  ValidaSobrenome(_sobrenome);
  this->sobrenome_ = _sobrenome;
}

Sobrenome::Sobrenome(const string &_sobrenome) {
  SetSobrenome(_sobrenome);
}

void Senha::ValidaSenha(string _senha) {
  if (_senha.size() > kmax_senha_size_) {
    throw invalid_argument("Senha extensa. A senha deve conter 8 caracteres.\n");
  }

  if (_senha.size() < kmax_senha_size_) {
    throw invalid_argument("Senha pequena. A senha deve conter 8 caracteres.\n");
  }

  int maiusc = 0, minusc = 0, nums = 0;

  for (char i : _senha) {
    if (i >= '0' && i <= '9') {
      nums++;
    }
    if (i >= 'A' && i <= 'Z') {
      maiusc++;
    }
    if (i >= 'a' && i <= 'z') {
      minusc++;
    }
  }

  if (maiusc < kminimo_maiuscula_ || minusc < kminimo_minuscula_ || nums < kminimo_numero_) {
    throw invalid_argument("Sua senha deve conter ao menos um numero, uma letra maiuscula e uma letra minuscula.\n");
  }
}

void Senha::SetSenha(string _senha) {
  ValidaSenha(_senha);
  this->senha_ = _senha;
}

void Email::ValidaEmail(string _email) {
  unsigned j = 0;
  bool FullNumerical, temletra = false;

  if (_email.size() <= kmin_email_size_) {
    throw invalid_argument("email muito pequeno.\n");
  }

  for (unsigned i = 0; i < _email.size(); i++) {
    if (_email[i] == '!' || _email[i] == '#' || _email[i] == '$' || _email[i] == '%' ||
        _email[i] == '&' || _email[i] == '*' || _email[i] == '+' || _email[i] == '-' ||
        _email[i] == '/' || _email[i] == '=' || _email[i] == '?' || _email[i] == '^' ||
        _email[i] == '_' || _email[i] == '{' || _email[i] == '}' || _email[i] == '|' ||
        _email[i] == '.' || _email[i] == ';' || (_email[i] >= 'A' && _email[i] <= 'Z') ||
        (_email[i] >= 'a' && _email[i] <= 'z') || (_email[i] >= '0' && _email[i] <= '9')) {
      continue;
    } else if (_email[i] == '@') {
      j = i;
      break;
    } else {
      throw invalid_argument("E-mail contem caracteres nao permitidos.\n");
    }
  }
  if (_email.front() == '.' || _email.back() == '.') {
    throw invalid_argument("O e-mail nao pode começar e nem terminar com ponto.\n");
  }

  if (_email[j - 1] == '.') {
    throw invalid_argument("A parte local do e-mail nao pode terminar com '.'\n");
  }

  if (_email[j + 1] == '-' || _email.back() == '-') {
    throw invalid_argument("Dominios nao podem comecar e nem terminar com hifen.\n");
  }

  for (unsigned i = j + 1; i < _email.size(); i++) {
    if ((_email[i] >= 'a' && _email[i] <= 'z') || (_email[i] >= 'A' && _email[i] <= 'Z')) {
      temletra = true;
    } else if (_email[i] == '@') {
      throw invalid_argument("nao sao permitidos dois @'s no e-mail.\n");
    }

    if (_email[i] == '.') {
      break;
    }
  }

  FullNumerical = !temletra;

  if (FullNumerical) {
    throw invalid_argument("Dominios nao podem conter apenas números.\n");
  }
}

void Email::SetEmail(string _email) {
  ValidaEmail(_email);
  this->email_ = _email;
}

void Data::ValidaData(string _data) {
  string::size_type sz;
  bool bissexto = false;
  int dia_int_, mes_int_, ano_int_;

  if (_data.size() <= kmin_data_size_) {
    throw invalid_argument("Data muito curta.\n");
  }

  if (_data[kpos_barra_dia_] != '/') {
    throw invalid_argument("Data com formato invalido.\n");
  }

  if (_data[kpos_barra_mes_] != '/') {
    throw invalid_argument("Data com formato invalido.\n");
  }

  dia_int_ = stoi(_data, &sz);
  mes_int_ = stoi(_data.substr(sz + 1), &sz);
  ano_int_ = stoi(_data.substr(sz + sz + 2));

  if (ano_int_ % 400 == 0 || (ano_int_ % 4 == 0 && ano_int_ % 100 != 0)) {
    bissexto = true;
  }

  if ((dia_int_ > kmax_dia_kFevereiro_ && mes_int_ == kFevereiro && !bissexto) || dia_int_ > kmax_dia_ ||
      dia_int_ < kmin_dia_ || mes_int_ > kmax_mes_ || mes_int_ < kmin_mes_ || ano_int_ < kmin_ano_
      || ano_int_ > kmax_ano_) {
    throw invalid_argument("Dia invalido.\n");
  }

  if (dia_int_ > 30 && (mes_int_ == kAbril || mes_int_ == kJunho || mes_int_ == kSetembro || mes_int_ == kNovembro)) {
    throw invalid_argument("Dia invalido.\n");
  }
}

void Data::SetData(string _data) {
  ValidaData(_data);
  this->data_ = _data;
}

void Telefone::ValidaTelefone(string _telefone) {
  if (_telefone.size() <= kmin_telefone_size_) {
    throw invalid_argument("numero de Telefone muito pequeno");
  }

  if (_telefone[kspace_pos_] != ' ') {
    throw invalid_argument("Telefone esta com espaco na posicao incorreta.\n");
  }

  if (_telefone[khifen_pos_] != '-') {
    throw invalid_argument("Telefone esta com o hifen na posicao incorreta.\n");
  }

  for (unsigned i = 0; i < _telefone.size(); i++) {
    if (i == kspace_pos_ || i == khifen_pos_) {
      continue;
    }

    if (_telefone[i] < '0' || _telefone[i] > '9') {
      throw invalid_argument("nao sao permitidas letras no telefone.\n");
    }
  }
}

void Telefone::SetTelefone(string _telefone) {
  ValidaTelefone(_telefone);
  this->telefone_ = _telefone;
}

void Address::ValidaAddress(string _address) {
  if (_address.size() > kmax_address_size_) {
    throw invalid_argument("O endereco eh muito extenso.\n");
  }

  if (_address.size() <= kmin_address_size_) {
    throw invalid_argument("endereço muito pequeno.\n");
  }

  if (_address.front() == ' ' || _address.back() == ' ') {
    throw invalid_argument("O endereço nao pode começar nem terminar com espaços.\n");
  }

  for (unsigned i = 1; i < _address.size() && i < kmax_address_size_; i++) {
    if (_address[i] == ' ' && _address[i - 1] == ' ') {
      throw invalid_argument("nao pode haver dois espaços em branco seguidos.\n");
    }
  }
}

void Address::SetAddress(string _address) {
  ValidaAddress(_address);
  this->address_ = _address;
}

void TextoDefinicao::ValidaDefinicao(string _definicao) {
  if (_definicao.size() > kmax_definicao_size_) {
    throw invalid_argument("Definicao muito extensa.\n");
  }
}

void TextoDefinicao::SetDefinicao(string _definicao) {
  ValidaDefinicao(_definicao);
  this->definicao_ = _definicao;
}

void Idioma::ValidaIdioma(string _idioma) {
  if (_idioma != "ENG" && _idioma != "FRA" && _idioma != "GER" &&
      _idioma != "ITA" && _idioma != "POR" && _idioma != "SPA") {
    throw invalid_argument("Idioma nao suportado.\n");
  }
}

void Idioma::SetIdioma(string _idioma) {
  ValidaIdioma(_idioma);
  this->idioma_ = _idioma;
}

void ClasseDoTermo::ValidaPreferencia(string _preferencia) {
  if (_preferencia != "PT" && _preferencia != "NP") {
    throw invalid_argument("Preferencia Invalida.\n");
  }
}

void ClasseDoTermo::SetPreferencia(string _preferencia) {
  ValidaPreferencia(_preferencia);
  this->preferencia_ = _preferencia;
}

