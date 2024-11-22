#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Voo.h"

using namespace std;

#define MAX_VOOS 100

    int Voo::getCodigoAviao() {
        return codigoAviao;
    }

    int Voo::getCodigoPiloto() {
        return codigoPiloto;
    }

    int Voo::getCodigoCopiloto() {
        return codigoCopiloto;
    }

    int Voo::getCodigoComissario() {
        return codigoComissario;
    }

    int Voo::getCodigoVoo() {
        return codigoVoo;
    }

    int Voo::getStatus() {
        return status;
    }

    int Voo::getTarifa() {
        return tarifa;
    }

     int Voo::getDia() {
        return dia;
    }

     int Voo::getMes() {
        return mes;
    }

     int Voo::getAno() {
        return ano;
    }

     int Voo::getHora() {
        return hora;
    }

     int Voo::getMinuto() {
        return minuto;
    }

    string Voo::getOrigem() {
        return origem;
    }

    string Voo::getDestino() {
        return destino;
    }


void Voo::setCodigoAviao(int codigoAviao) {
        this->codigoAviao = codigoAviao;
    }

    void Voo::setCodigoPiloto(int codigoPiloto) {
        this->codigoPiloto = codigoPiloto;
    }

    void Voo::setCodigoCopiloto(int codigoCopiloto) {
        this->codigoCopiloto = codigoCopiloto;
    }

    void Voo::setCodigoComissario(int codigoComissario) {
        this->codigoComissario = codigoComissario;
    }

    void Voo::setCodigoVoo(int codigoVoo) {
        this->codigoVoo = codigoVoo;
    }

    void Voo::setStatus(int status) {
        this->status = status;
    }

    void Voo::setTarifa(int tarifa) {
        this->tarifa = tarifa;
    }

    void Voo::setDia (int dia) {
        this->dia = dia;
    }

    void Voo::setMes(int mes) {
        this->mes = mes;
    }

    void Voo::setAno(int ano) {
        this->ano = ano;
    }

    void Voo::setHora(int hora) {
        this->hora = hora;
    }

    void Voo::setMinuto(int minuto) {
        this->minuto = minuto;
    }

    void Voo::setOrigem(string origem) {
        this->origem = origem;
    }

    void Voo::setDestino(string destino) {
        this->destino = destino;
}

vector<Voo>voos;

int contagemVoo = 0;

Voo voo;

void Voo::cadastroVoo(){
    system("cls");

    if(contagemVoo >= MAX_VOOS){
        cout << "Limite de voos cadastrados atingido!" << endl;
        return;
    };

    string origem, destino;
    int codigoAviao, codigoComissario, codigoCopiloto, codigoPiloto, tarifa, status, dia, mes, ano, hora, minuto;

    cout << "Informe a origem do voo:" << endl;
    getline(cin, origem);
    voo.setOrigem(origem);

    cout << "Informe o destino do voo:" << endl;
    getline(cin, destino);
    voo.setDestino(destino);

    cout << "Informe a data do voo:" << endl;
    cout << "Dia:";
    cin >> dia;
    cin.ignore();
    voo.setDia(dia);

    cout << "Mes:";
    cin >> mes;
    cin.ignore();
    voo.setMes(mes);

    cout << "Ano:";
    cin >> ano;
    cin.ignore();
    voo.setAno(ano);

    cout << "Informe a hora do voo:" << endl;
    cout << "Hora:";
    cin >> hora;
    cin.ignore();
    voo.setHora(hora);

    cout << "Minutos:";
    cin >> minuto;
    cin.ignore();
    voo.setMinuto(minuto);

    cout << "Informe o código do avião:" << endl;
    cin >> codigoAviao;
    cin.ignore();
    voo.setCodigoAviao(codigoAviao);

    cout << "Informe o código do Piloto:" << endl;
    cin >> codigoPiloto;
    cin.ignore();
    voo.setCodigoPiloto(codigoPiloto);

    cout << "Informe o código do Copiloto:" << endl;
    cin >> codigoCopiloto;
    cin.ignore();
    voo.setCodigoCopiloto(codigoCopiloto);

    cout << "Informe o código do Comissário:" << endl;
    cin >> codigoComissario;
    cin.ignore();
    voo.setCodigoComissario(codigoComissario);

    cout << "Informe a tarifa:" << endl;
    cin >> tarifa;
    cin.ignore();
    voo.setTarifa(tarifa);

    if(codigoPiloto !=0 && codigoCopiloto !=0){
        cout << "Voo ativo" << endl;
        status = 1;
        voo.setStatus(status);
    }else{
        cout << "Voo inativo, falta piloto ou copiloto" << endl;
        status = 0;
        voo.setStatus(status);
    }

    contagemVoo++;
    voo.setCodigoVoo(contagemVoo);

    voos.push_back(voo);
}

void Voo::listarVoo(){
    system("cls");
    if(contagemVoo == 0){
        cout << "Nenhum voo cadastrado" << endl;
    }else{
        for(int i = 0; i<contagemVoo; i++){
            cout << "\nInformações de Voo:" << endl;
            cout << "Código de voo: " << codigoVoo << endl;
            cout << "Código do avião: " << codigoAviao << endl;
            cout << "Local de origem: " << origem << endl;
            cout << "Local de destino: " << destino << endl;
            cout << "Data: " << dia << "/" << mes << "/" << ano  << endl;
            cout << "Horário: " << hora << ":" << minuto << endl;
            cout << "Piloto: " << codigoPiloto << endl;
            cout << "Copiloto: " << codigoCopiloto << endl;
            cout << "Comissário: " << codigoComissario << endl;
            cout << "Tarifa:" << tarifa << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();

}
