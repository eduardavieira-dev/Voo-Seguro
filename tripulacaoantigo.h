#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <vector>
#include <string>
using namespace std;

class Tripulante {
public:
    string id_tripulante;  
    string nome;
    string telefone;
    string cargo;
    
    Tripulante(const string& id_tripulante, const string& nome, const string& telefone, const string& cargo);
};

class Tripulacao {
private:
    vector<Tripulante> tripulantes;
 
    int contadorPiloto;
    int contadorCopiloto;
    int contadorComissario;

    const string arquivoBinario = "tripulantes.dat";

    string gerarId(const string& cargo);

public:

    Tripulacao();

    void cadastrarTripulante();
    void listarTripulantes();

    void salvarDados();   
    void carregarDados(); 
};

#endif
