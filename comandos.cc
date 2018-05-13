#include "comandos.h"

void ComandoAVocabularioLeitor::Executar(InterfaceServicoVocabulario *stub_isv) {
    int opt;
    do {
        system(CLEAR);
        cout << "\tGestao de Vocabulos\n";
        cout << "\nEscolha uma das opcoes abaixo.\n\n";
        cout << klistarvocabularios << ". Listar Vocabularios\n";
        cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
        cout << kconsultartermo << ". Consultar Termo\n";
        cout << kconsultardefinicao << ". Consultar Definicao\n";
        cout << kvoltar << ". Voltar\n\topcao: ";
        cin >> opt;

        switch (opt) {
        case klistarvocabularios:system(CLEAR);
            if (stub_isv->ListarVocabularios().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            }
            break;
        case kapresentarvocabulario:system(CLEAR);
            if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultartermo:system(CLEAR);
            if (stub_isv->ConsultarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultardefinicao:system(CLEAR);
            if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}

void ComandoAVocabularioDesenvolvedor::Executar(InterfaceServicoVocabulario *stub_isv) {
    int opt;
    do {
        system(CLEAR);
        cout << "\tGestao de Vocabulos\n";
        cout << "\nEscolha uma das opcoes abaixo.\n\n";
        cout << klistarvocabularios << ". Listar Vocabularios\n";
        cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
        cout << kconsultartermo << ". Consultar Termo\n";
        cout << kconsultardefinicao << ". Consultar Definicao\n";
        cout << kcriartermo << ". Criar Termo\n";
        cout << keditartermo << ". Editar Termo\n";
        cout << kexcluirtermo << ". Excluir Termo\n";
        cout << kcriardefinicao << ". Criar Definicao\n";
        cout << keditardefinicao << ". Editar Definicao\n";
        cout << kexcluirdefinicao << ". Excluir Definicao\n";
        cout << kvoltar << ". Voltar\n\topcao: ";
        cin >> opt;

        switch (opt) {
        case klistarvocabularios:system(CLEAR);
            if (stub_isv->ListarVocabularios().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            }
            break;
        case kapresentarvocabulario:system(CLEAR);
            if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultartermo:system(CLEAR);
            if (stub_isv->ConsultarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultardefinicao:system(CLEAR);
            if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kcadastrardesenvolvedor:system(CLEAR);
            if (stub_isv->CadastrarDesenvolvedor().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Cadastrar Desenvolvedor\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Cadastrar Desenvolvedor\n" << endl;
                system(PAUSE);
            }
            break;
        case kcriartermo:system(CLEAR);
            if (stub_isv->CriarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Criar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Criar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case keditartermo:system(CLEAR);
            if (stub_isv->EditarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Editar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Editar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kexcluirtermo:system(CLEAR);
            if (stub_isv->ExcluirTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Excluir Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Excluir Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kcriardefinicao:system(CLEAR);
            if (stub_isv->CriarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Criar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Criar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case keditardefinicao:system(CLEAR);
            if (stub_isv->EditarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Editar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Editar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kexcluirdefinicao:system(CLEAR);
            if (stub_isv->ExcluirDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Excluir Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Excluir Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Executar(InterfaceServicoVocabulario *stub_isv) {
    int opt;
    do {
        system(CLEAR);
        cout << "\tGestao de Vocabulos\n";
        cout << "\nEscolha uma das opcoes abaixo.\n\n";
        cout << klistarvocabularios << ". Listar Vocabularios\n";
        cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
        cout << kconsultartermo << ". Consultar Termo\n";
        cout << kconsultardefinicao << ". Consultar Definicao\n";
        cout << kcadastrardesenvolvedor << ". Cadastrar Desenvolvedor\n";
        cout << kcriartermo << ". Criar Termo\n";
        cout << keditartermo << ". Editar Termo\n";
        cout << kexcluirtermo << ". Excluir Termo\n";
        cout << kcriardefinicao << ". Criar Definicao\n";
        cout << keditardefinicao << ". Editar Definicao\n";
        cout << kexcluirdefinicao << ". Excluir Definicao\n";
        cout << kcriarvocabulario << ". Criar Vocabulario\n";
        cout << keditarvocabulario << ". Editar Vocabulario\n";
        cout << kexcluirvocabulario << ". Excluir Vocabulario\n";
        cout << kvoltar << ". Voltar\n\topcao: ";
        cin >> opt;

        switch (opt) {
        case klistarvocabularios:system(CLEAR);
            if (stub_isv->ListarVocabularios().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Listar Vocabularios\n" << endl;
                system(PAUSE);
            }
            break;
        case kapresentarvocabulario:system(CLEAR);
            if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Apresentar Vocabulario\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultartermo:system(CLEAR);
            if (stub_isv->ConsultarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kconsultardefinicao:system(CLEAR);
            if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Consultar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Consultar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kcadastrardesenvolvedor:system(CLEAR);
            if (stub_isv->CadastrarDesenvolvedor().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Cadastrar Desenvolvedor\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Cadastrar Desenvolvedor\n" << endl;
                system(PAUSE);
            }
            break;
        case kcriartermo:system(CLEAR);
            if (stub_isv->CriarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Criar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Criar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case keditartermo:system(CLEAR);
            if (stub_isv->EditarTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Editar Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Editar Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kexcluirtermo:system(CLEAR);
            if (stub_isv->ExcluirTermo().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Excluir Termo\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Excluir Termo\n" << endl;
                system(PAUSE);
            }
            break;
        case kcriardefinicao:system(CLEAR);
            if (stub_isv->CriarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Criar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Criar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case keditardefinicao:system(CLEAR);
            if (stub_isv->EditarDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Editar Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Editar Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kexcluirdefinicao:system(CLEAR);
            if (stub_isv->ExcluirDefinicao().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Excluir Definicao\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Excluir Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kcriarvocabulario:system(CLEAR);
            if (stub_isv->CriarVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Criar Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Criar Vocabulario\n" << endl;
                system(PAUSE);
            }
            break;
        case keditarvocabulario:system(CLEAR);
            if (stub_isv->EditarVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Editar Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Editar Vocabulario\n" << endl;
                system(PAUSE);
            }
            break;
        case kexcluirvocabulario:system(CLEAR);
            if (stub_isv->ExcluirVocabulario().GetResultado() == Resultado::SUCESSO) {
                cout << "Sucesso ao Excluir Vocabulario\n" << endl;
                system(PAUSE);
            } else {
                cout << "Falha ao Excluir Definicao\n" << endl;
                system(PAUSE);
            }
            break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}