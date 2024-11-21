#ifndef ATRIBUTOSVOO_H
#define ATRIBUTOSVOO_H

#include <string>
using namespace std;

class atributosVoo {
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
    int getCodigoAviao() {
        return codigoAviao;
    }

    int getCodigoPiloto() {
        return codigoPiloto;
    }

    int getCodigoCopiloto() {
        return codigoCopiloto;
    }

    int getCodigoComissario() {
        return codigoComissario;
    }

    int getCodigoVoo() {
        return codigoVoo;
    }

    int getStatus() {
        return status;
    }

    int getTarifa() {
        return tarifa;
    }

     int getDia() {        return dia;
    }

     int getMes() {
        return mes;
    }

     int getAno() {
        return ano;
    }

     int getHora() {
        return hora;
    }

     int getMinuto() {
        return minuto;
    }

    string getOrigem() {
        return origem;
    }

    string getDestino() {
        return destino;
    }

    void setCodigoAviao(int codigoAviao) {
        this->codigoAviao = codigoAviao;
    }

    void setCodigoPiloto(int codigoPiloto) {
        this->codigoPiloto = codigoPiloto;
    }

    void setCodigoCopiloto(int codigoCopiloto) {
        this->codigoCopiloto = codigoCopiloto;
    }

    void setCodigoComissario(int codigoComissario) {
        this->codigoComissario = codigoComissario;
    }

    void setCodigoVoo(int codigoVoo) {
        this->codigoVoo = codigoVoo;
    }

    void setStatus(int status) {
        this->status = status;
    }

    void setTarifa(int tarifa) {
        this->tarifa = tarifa;
    }

    void setDia (int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }

    void setHora(int hora) {
        this->hora = hora;
    }

    void setMinuto(int minuto) {
        this->minuto = minuto;
    }

    void setOrigem(string origem) {
        this->origem = origem;
    }

    void setDestino(string destino) {
        this->destino = destino;
    }
};

#endif // ATRIBUTOSVOO_H
