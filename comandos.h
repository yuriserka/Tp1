#ifndef TRABALHO__COMANDOS__H__
#define TRABALHO__COMANDOS__H__

/**
 * @file 
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief
 * 
 */

#include "interfaces.h"

class ComandoAVocabulario {
    public:
        virtual void Executar(InterfaceServicoVocabulario *) = 0;
        virtual ~ComandoAVocabulario() = default;
};

class ComandoAVocabularioLeitor : public ComandoAVocabulario {
    public:
        void Executar(InterfaceServicoVocabulario *) override;
    private:
        enum {         
            knull,
            klistarvocabularios,
            kapresentarvocabulario,
            kconsultartermo,
            kconsultardefinicao,
            kvoltar
        };
};

class ComandoAVocabularioDesenvolvedor : public ComandoAVocabulario {
    public:
        void Executar(InterfaceServicoVocabulario *) override;
    private:
        enum {         
            knull,
            klistarvocabularios,
            kapresentarvocabulario,
            kconsultartermo,
            kconsultardefinicao,
            kcadastrardesenvolvedor,
            kcriartermo,
            keditartermo,
            kexcluirtermo,
            kcriardefinicao,
            keditardefinicao,
            kexcluirdefinicao,
            kvoltar
        };
};

class ComandoAVocabularioAdministrador : public ComandoAVocabulario {
    public:
        void Executar(InterfaceServicoVocabulario *) override;
    private:
        enum {         
            knull,
            klistarvocabularios,
            kapresentarvocabulario,
            kconsultartermo,
            kconsultardefinicao,
            kcadastrardesenvolvedor,
            kcriartermo,
            keditartermo,
            kexcluirtermo,
            kcriardefinicao,
            keditardefinicao,
            kexcluirdefinicao,
            kcriarvocabulario,
            keditarvocabulario,
            kexcluirvocabulario,
            kvoltar
        };
};

#endif  // TRABALHO__COMANDOS__H__