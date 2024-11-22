#ifndef ATRIBUTOSVOO_H
#define ATRIBUTOSVOO_H

#include <string>
using namespace std;

class Voo {
    private:
    int codigoAviao;
    int codigoPiloto;
    int codigoCopiloto;
    int codigoComissario;
    int codigoVoo;
    int status;
    int tarifa;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    string origem;
    string destino;

    public:
    int getCodigoAviao()

    int getCodigoPiloto() 

    int getCodigoCopiloto() 

    int getCodigoComissario() 

    int getCodigoVoo() 

    int getStatus() 

    int getTarifa() 

     int getDia() 

     int getMes() 

     int getAno() 

     int getHora() 

     int getMinuto() 

    string getOrigem() 

    string getDestino() 

    void setCodigoAviao(int codigoAviao)       

    void setCodigoPiloto(int codigoPiloto) 

    void setCodigoCopiloto(int codigoCopiloto) 

    void setCodigoComissario(int codigoComissario) 

    void setCodigoVoo(int codigoVoo) 

    void setStatus(int status) 

    void setTarifa(int tarifa) 

    void setDia (int dia) 

    void setMes(int mes) 

    void setAno(int ano) 

    void setHora(int hora) 

    void setMinuto(int minuto)

    void setOrigem(string origem)

    void setDestino(string destino)

};

#endif // ATRIBUTOSVOO_H
