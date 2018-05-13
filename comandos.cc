#include "comandos.h"

void ComandoAVocabularioLeitor::Exibir() {
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
        case klistarvocabularios:break;
        case kapresentarvocabulario:break;
        case kconsultartermo:break;
        case kconsultardefinicao:break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}

void ComandoAVocabularioDesenvolvedor::Exibir() {
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
        case klistarvocabularios:break;
        case kapresentarvocabulario:break;
        case kconsultartermo:break;
        case kconsultardefinicao:break;
        case kcadastrardesenvolvedor:break;
        case kcriartermo:break;
        case keditartermo:break;
        case kexcluirtermo:break;
        case kcriardefinicao:break;
        case keditardefinicao:break;
        case kexcluirdefinicao:break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Exibir() {
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
        case klistarvocabularios:break;
        case kapresentarvocabulario:break;
        case kconsultartermo:break;
        case kconsultardefinicao:break;
        case kcadastrardesenvolvedor:break;
        case kcriartermo:break;
        case keditartermo:break;
        case kexcluirtermo:break;
        case kcriardefinicao:break;
        case keditardefinicao:break;
        case kexcluirdefinicao:break;
        case kcriarvocabulario:break;
        case keditarvocabulario:break;
        case kexcluirvocabulario:break;
        case kvoltar:break;
        default:break;
        }
    } while (opt != kvoltar);
}