#include "../include/interfaces.h"
#include "../include/servicos.h"

int main() {
  InterfaceServicoControle *isc;
  isc = new CtrlServicoControle();
  isc->Construir();

  delete isc;

  return 0;
}
