#include "entidades.h"
#include "dominios.h"
#include "unit-test-dominios.h"
#include "unit-test-entidades.h"
#include "testes.h"
#include "UI.h"

#include <iostream>

using namespace std;

int main() {

  ApresentacaoAutenticacao menu = ApresentacaoAutenticacao();

  menu.RunMenu();

  return 0;
}


