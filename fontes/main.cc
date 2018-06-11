#include "../cabecalhos/includes.h"

int main() {
  InterfaceServicoControle *isc;
  isc = new CtrlServicoControle();
  isc->Construir();

  delete isc;

  return 0;
}
