#ifndef ASSENTO_H
#define ASSENTO_H

#include "Voo.h"
#include <vector>

using namespace std;
extern vector<Voo> voos;

class Assento
{
private:
    static int contadorNumAssento;
    int codVoo;
    int numAssento;
    bool status;

public:
    Assento();

    Assento(int codVoo);

    void setCodVoo(int codVoo);

    void setNumAssento(int numAssento);

    void setStatusAssento();

    int getCodVoo();

    int getNumAssento();

    bool getStatusAssento();

    void salvarAssento();

    void carregarAssentos();

    void cadastroAssento();

    void ExibirAssentos();
};

#endif //ASSENTO.H