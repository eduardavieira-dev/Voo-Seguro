#include "Tripulacao.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//rode no terminal: g++ -o Eduarda main.cpp tripulacao.cpp voo.cpp

// Construtor de Tripulante
Tripulante::Tripulante(int id_tripulante, const string& nome, const string& telefone, const string& cargo)
    : id_tripulante(id_tripulante), nome(nome), telefone(telefone), cargo(cargo) {}

// Construtor de Tripulacao
Tripulacao::Tripulacao() : proximo_id(1) {
    carregarDados();
}

// Método para salvar os dados no arquivo binário
void Tripulacao::salvarDados() {
    ofstream arquivo(arquivoBinario, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para salvar os dados.\n";
        return;
    }

    arquivo.write((char*)&proximo_id, sizeof(proximo_id));
    int tamanho = tripulantes.size();
    arquivo.write((char*)&tamanho, sizeof(tamanho));

    for (const auto& t : tripulantes) {
        arquivo.write((char*)&t.id_tripulante, sizeof(t.id_tripulante));  // Alterado para id_tripulante

        size_t tamanhoNome = t.nome.size();
        arquivo.write((char*)&tamanhoNome, sizeof(tamanhoNome));
        arquivo.write(t.nome.c_str(), tamanhoNome);

        size_t tamanhoTelefone = t.telefone.size();
        arquivo.write((char*)&tamanhoTelefone, sizeof(tamanhoTelefone));
        arquivo.write(t.telefone.c_str(), tamanhoTelefone);

        size_t tamanhoCargo = t.cargo.size();
        arquivo.write((char*)&tamanhoCargo, sizeof(tamanhoCargo));
        arquivo.write(t.cargo.c_str(), tamanhoCargo);
    }

    cout << "Dados salvos com sucesso!\n";
}

// Método para carregar os dados do arquivo binário
void Tripulacao::carregarDados() {
    ifstream arquivo(arquivoBinario, ios::binary);
    if (!arquivo) {
        cout << "Nenhum arquivo encontrado. Começando com dados vazios.\n";
        return;
    }

    arquivo.read((char*)&proximo_id, sizeof(proximo_id));
    int tamanho = 0;
    arquivo.read((char*)&tamanho, sizeof(tamanho));

    tripulantes.clear();
    for (int i = 0; i < tamanho; i++) {
        Tripulante t(0, "", "", "");
        arquivo.read((char*)&t.id_tripulante, sizeof(t.id_tripulante));  // Alterado para id_tripulante

        size_t tamanhoNome;
        arquivo.read((char*)&tamanhoNome, sizeof(tamanhoNome));
        t.nome.resize(tamanhoNome);
        arquivo.read(&t.nome[0], tamanhoNome);

        size_t tamanhoTelefone;
        arquivo.read((char*)&tamanhoTelefone, sizeof(tamanhoTelefone));
        t.telefone.resize(tamanhoTelefone);
        arquivo.read(&t.telefone[0], tamanhoTelefone);

        size_t tamanhoCargo;
        arquivo.read((char*)&tamanhoCargo, sizeof(tamanhoCargo));
        t.cargo.resize(tamanhoCargo);
        arquivo.read(&t.cargo[0], tamanhoCargo);

        tripulantes.push_back(t);
    }

    cout << "Dados carregados com sucesso!\n";
}

// Método para cadastrar um novo tripulante
void Tripulacao::cadastrarTripulante() {
    string nome, telefone, cargo;
    int opcao_cargo;

    cin.ignore();
    cout << "Digite o nome do tripulante: ";
    getline(cin, nome);

    cout << "Digite o telefone do tripulante: ";
    getline(cin, telefone);

    cout << "Escolha o cargo:\n1 - Piloto\n2 - Copiloto\n3 - Comissario\nOpcao: ";
    cin >> opcao_cargo;

    switch (opcao_cargo) {
        case 1: cargo = "Piloto"; break;
        case 2: cargo = "Copiloto"; break;
        case 3: cargo = "Comissario"; break;
        default: cargo = "Indefinido"; break;
    }

    Tripulante novo(proximo_id++, nome, telefone, cargo);
    tripulantes.push_back(novo);

    salvarDados();
    cout << "Tripulante cadastrado com sucesso! ID: " << novo.id_tripulante << endl;
}

// Método para listar todos os tripulantes
void Tripulacao::listarTripulantes() {
    if (tripulantes.empty()) {
        cout << "Nenhum tripulante cadastrado.\n";
        return;
    }

    cout << left << setw(5) << "ID"
        << setw(20) << "Nome"
        << setw(15) << "Telefone"
        << setw(15) << "Cargo" << endl;

    cout << string(5 + 20 + 15 + 15, '-') << endl;

    for (const auto& t : tripulantes) {
        cout << left << setw(5) << t.id_tripulante  // Alterado para id_tripulante
             << setw(20) << t.nome
             << setw(15) << t.telefone
             << setw(15) << t.cargo << endl;
    }
}
