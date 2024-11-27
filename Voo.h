#include <string>
#include <vector>
using namespace std;

class Voo {
    private:
    int codigoAviao;
    int codigoVoo;
    int tarifa;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    string origem;
    string destino;
    int codigoTripulacao;

    public:
    
    int getCodigoAviao();
    int getCodigoVoo(); 
    int getStatus(); 
    int getTarifa(); 
    int getDia(); 
    int getMes(); 
    int getAno(); 
    int getHora(); 
    int getMinuto(); 
    string getOrigem(); 
    string getDestino(); 
    int getTotalVoo();
    /* int getCodigoTripulacao(); */

    void setCodigoAviao(int codigoAviao);       
    void setCodigoVoo(int codigoVoo);
    void setTarifa(int tarifa); 
    void setDia (int dia); 
    void setMes(int mes); 
    void setAno(int ano); 
    void setHora(int hora); 
    void setMinuto(int minuto);
    void setOrigem(string origem);
    void setDestino(string destino);
    /* void setCodigoTripulacao(int tripulacao); */
    
    void cadastroVoo();
    void listarVoo();

    void salvarVoos();
    void carregarVoos(); 
    Voo* getVooPorCodigo(int codigoVoo);
    
};