#ifndef VOOS_H
#define VOOS_H
#include <string>
#include <vector>
#include "tripulacao.h"

using namespace std;

extern vector<Tripulacao> tripulacaoVet;

class Voo {
    private:
    int codigoAviao;
    int codigoVoo;
    int tarifa;
    int dia;
    int mes;
    string status;
    int ano;
    int hora;
    int minuto;
    string origem;
    string destino;
    int codigoTripulacao;
   /*  bool tripulacaoEmUso; */

    public:
    
    int getCodigoAviao();
    int getCodigoVoo(); 
    string getStatus(); 
    int getTarifa(); 
    int getDia(); 
    int getMes(); 
    int getAno(); 
    int getHora(); 
    int getMinuto(); 
    string getOrigem(); 
    string getDestino(); 
    /* bool getTripulacaoEmUso(); */

    void setCodigoAviao(int codigoAviao);       
    void setCodigoVoo(int codigoVoo);
    void setStatus(int status);
    void setTarifa(int tarifa); 
    void setDia (int dia); 
    void setMes(int mes); 
    void setAno(int ano); 
    void setHora(int hora); 
    void setMinuto(int minuto);
    void setOrigem(string origem);
    void setDestino(string destino);
    /* void setTripulacaoEmUso(bool tripulacaoEmUso); */
    
    void cadastroVoo();
    void listarVoo();

    void salvarVoos();
    void carregarVoos(); 
    
};
#endif // VOOS_H