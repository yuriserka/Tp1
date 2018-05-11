#include "controladores.h"
#include "comandos.h"
#include "stubs.h"

ResultadoAutenticar CtrlApresentacaoAutenticacao::Autenticar() {
  ResultadoAutenticar resultado;
  Resultado verificado;
  string iemail, isenha;
  Email email;
  Senha senha;

  while(true) {
    system(CLEAR);
    try {
      cout << "Email: ";
      cin >> iemail;
      email = Email(iemail);

      cout << "Senha: ";
      cin >> isenha;
      senha = Senha(isenha);
      break;
    }
    catch (exception &e) {
      cout << "Formato incorreto!\n\t" << e.what() << "\n";
      system(PAUSE);
    }
  }

  verificado = CtrlServicoAutenticacao_->Autenticar(email, senha);

  if (verificado.GetResultado() == ResultadoAutenticar::FALHA) {
    cout << "Falha na autenticacao\n";
  }

  resultado.SetResultado(verificado.GetResultado());
  resultado.SetEmailResultado(email);

  return resultado;
}

void CtrlApresentacaoControle::Inicializar() {
  InterfaceApresentacaoAutenticacao *ctrl_iaa = new CtrlApresentacaoAutenticacao();
  StubAutenticacao *stub_a = new StubAutenticacao();
  ctrl_iaa->SetCtrlServicoAutenticacao(stub_a);
  int opt;
  system(CLEAR);
  cout << "Sistema Vocabularios Controlados\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << kentrar << ". Entrar\n";
  cout << kcadastrar << ". Cadastrar\n";
  cout << ksair << ". Sair\n\tOpcao: ";

  cin >> opt;
  ResultadoAutenticar resultado;

  switch(opt) {
    case kentrar:
      SetCtrlAutenticacao(ctrl_iaa);
      resultado = ctrl_apresentacao_autenticacao_->Autenticar();
      if (resultado.GetResultado() == ResultadoAutenticar::SUCESSO) {
        Logado();
      }
      break;
    case kcadastrar:
      break;
    case ksair:
      break;
  }
}

void CtrlApresentacaoControle::Logado() {
  system(CLEAR);
  cout << "\tBem-vindo!\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << "1. Acessar Dados da Conta\n2. Acessar Vocabulos\n3. Voltar ao Menu Principal\n\topcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
  }
}