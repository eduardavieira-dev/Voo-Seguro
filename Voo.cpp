#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Voo.h"
#include <fstream>

using namespace std;

#define MAX_VOOS 100

vector<Voo>voos;

int contagemVoo = 0;

void Voo::salvarVoos() {
    ofstream arquivo("voos.dat", ios::binary);

    if (arquivo.is_open()) {
       
        for (int i = 0; i < contagemVoo; i++) {
            
            arquivo.write(reinterpret_cast<char*>(&voos[i].codigoVoo), sizeof(voos[i].codigoVoo));
            arquivo.write(reinterpret_cast<char*>(&voos[i].codigoAviao), sizeof(voos[i].codigoAviao));
            arquivo.write(voos[i].origem.c_str(), voos[i].origem.size() + 1);  
            arquivo.write(voos[i].destino.c_str(), voos[i].destino.size() + 1);
            arquivo.write(reinterpret_cast<char*>(&voos[i].dia), sizeof(voos[i].dia));
            arquivo.write(reinterpret_cast<char*>(&voos[i].mes), sizeof(voos[i].mes));
            arquivo.write(reinterpret_cast<char*>(&voos[i].ano), sizeof(voos[i].ano));
            arquivo.write(reinterpret_cast<char*>(&voos[i].hora), sizeof(voos[i].hora));
            arquivo.write(reinterpret_cast<char*>(&voos[i].minuto), sizeof(voos[i].minuto));
            arquivo.write(reinterpret_cast<char*>(&voos[i].codigoPiloto), sizeof(voos[i].codigoPiloto));
            arquivo.write(reinterpret_cast<char*>(&voos[i].codigoCopiloto), sizeof(voos[i].codigoCopiloto));
            arquivo.write(reinterpret_cast<char*>(&voos[i].codigoComissario), sizeof(voos[i].codigoComissario));
            arquivo.write(reinterpret_cast<char*>(&voos[i].tarifa), sizeof(voos[i].tarifa));
            arquivo.write(reinterpret_cast<char*>(&voos[i].status), sizeof(voos[i].status));
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para salvar os voos." << endl;
    }
}


void Voo::carregarVoos() {
    ifstream arquivo("voos.dat", ios::binary);

    if (arquivo.is_open()) {
        while (arquivo.read(reinterpret_cast<char*>(&codigoVoo), sizeof(codigoVoo))) {
            arquivo.read(reinterpret_cast<char*>(&codigoAviao), sizeof(codigoAviao));
            getline(arquivo, origem, '\0'); 
            getline(arquivo, destino, '\0');
            arquivo.read(reinterpret_cast<char*>(&dia), sizeof(dia));
            arquivo.read(reinterpret_cast<char*>(&mes), sizeof(mes));
            arquivo.read(reinterpret_cast<char*>(&ano), sizeof(ano));
            arquivo.read(reinterpret_cast<char*>(&hora), sizeof(hora));
            arquivo.read(reinterpret_cast<char*>(&minuto), sizeof(minuto));
            arquivo.read(reinterpret_cast<char*>(&codigoPiloto), sizeof(codigoPiloto));
            arquivo.read(reinterpret_cast<char*>(&codigoCopiloto), sizeof(codigoCopiloto));
            arquivo.read(reinterpret_cast<char*>(&codigoComissario), sizeof(codigoComissario));
            arquivo.read(reinterpret_cast<char*>(&tarifa), sizeof(tarifa));
            arquivo.read(reinterpret_cast<char*>(&status), sizeof(status));

            Voo novoVoo;
            novoVoo.setCodigoVoo(codigoVoo);
            novoVoo.setCodigoAviao(codigoAviao);
            novoVoo.setOrigem(origem);
            novoVoo.setDestino(destino);
            novoVoo.setDia(dia);
            novoVoo.setMes(mes);
            novoVoo.setAno(ano);
            novoVoo.setHora(hora);
            novoVoo.setMinuto(minuto);
            novoVoo.setCodigoPiloto(codigoPiloto);
            novoVoo.setCodigoCopiloto(codigoCopiloto);
            novoVoo.setCodigoComissario(codigoComissario);
            novoVoo.setTarifa(tarifa);
            novoVoo.setStatus(status);

            voos.push_back(novoVoo);
            contagemVoo++;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os voos." << endl;
    }
}

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

void Voo::cadastroVoo(){
    system("cls");
    Voo voo;
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

    voo.salvarVoos();

}

void Voo::listarVoo(){
    system("cls");
    if(contagemVoo == 0){
        cout << "Nenhum voo cadastrado" << endl;
    }else{
        for(int i = 0; i<contagemVoo; i++){
            cout << "\nInformações de Voo:" << endl;
            cout << "Código de voo: " << voos[i].getCodigoVoo() << endl;               
            cout << "Código do avião: " << voos[i].getCodigoAviao() << endl;           
            cout << "Local de origem: " << voos[i].getOrigem() << endl;                
            cout << "Local de destino: " << voos[i].getDestino() << endl;              
            cout << "Data: " << voos[i].getDia() << "/" << voos[i].getMes() << "/" << voos[i].getAno() << endl;
            cout << "Horário: " << voos[i].getHora() << ":" << voos[i].getMinuto() << endl; 
            cout << "Piloto: " << voos[i].getCodigoPiloto() << endl;                   
            cout << "Copiloto: " << voos[i].getCodigoCopiloto() << endl;               
            cout << "Comissário: " << voos[i].getCodigoComissario() << endl;           
            cout << "Tarifa: " << voos[i].getTarifa() << endl;                         
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();

}
