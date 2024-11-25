#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <vector>
#include <string>
using namespace std;

class Tripulante {
public:
    int id_tripulante;  
    string nome;
    string telefone;
    string cargo;

    // Construtor
    Tripulante(int id_tripulante, const string& nome, const string& telefone, const string& cargo);
};

class Tripulacao {
private:
    vector<Tripulante> tripulantes;
    int proximo_id;

    const string arquivoBinario = "tripulantes.dat";
public:
    Tripulacao();

    void cadastrarTripulante();
    void listarTripulantes();

    void salvarDados();   
    void carregarDados(); 
};

#endif
