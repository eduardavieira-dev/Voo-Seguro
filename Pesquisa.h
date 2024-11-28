#ifndef PESQUISA_H
#define PESQUISA_H
#include <string>
#include <vector>
#include "Passageiro.h"
#include "Tripulacao.h"

using namespace std;

class Pesquisa{

    private:
    int IdPassageiro;
    string NomePassageiro;
    int IdTripulante;
    string NomeTripulante;


    public:

  // Métodos Setters
    void setCodPassageiro(int codPassageiro);
    void setNomePassageiro(string nomePassageiro);
    void setCodTripulacao(int codTripulante);
    void setNomeTripulacao(string nomeTripulante);

   // Métodos Getters
    int getCodPassageiro();
    int getCodTripulante();
    string getNomePassageiro();
    string getNomeTripulante();


 
  // Métodos de pesquisa

    void pesquisarNomePassageiro(string NomePassageiro); 
    void pesquisarIdPassageiro(int IdPassageiro);                
    void pesquisarNomeTripulante(string NomeTripulante);
    void pesquisarIdTripulante(int IdTripulante);  


    void pesquisarTripulacao();
    void pesquisarPassageiro();
};



#endif // PESQUISA_H3
