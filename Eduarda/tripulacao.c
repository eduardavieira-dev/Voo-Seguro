#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPULANTES 100
#define ARQUIVO_BINARIO "tripulacao.dat"

typedef struct {
    int id;
    char nome[50];
    char telefone[15];
    char cargo[20]; // "Piloto", "Copiloto", "Comissário"
} Tripulante;

Tripulante tripulacao[MAX_TRIPULANTES];
int total_tripulantes = 0;
int proximo_id = 1;

// Funções de manipulação de arquivo
void salvarDados();
void carregarDados();

void cadastrarTripulante();
void deletarTripulante();
void listarTripulantes();
void menuCadastro();

int main() {
    carregarDados(); // Carregar os dados ao iniciar o programa
    menuCadastro();
    return 0;
}

// Função para salvar os dados em um arquivo binário
void salvarDados() {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    // Salva o número de tripulantes e o próximo ID
    fwrite(&total_tripulantes, sizeof(int), 1, arquivo);
    fwrite(&proximo_id, sizeof(int), 1, arquivo);

    // Salva o vetor de tripulantes
    fwrite(tripulacao, sizeof(Tripulante), total_tripulantes, arquivo);

    fclose(arquivo);
    printf("Dados salvos com sucesso.\n");
}

// Função para carregar os dados de um arquivo binário
void carregarDados() {
    FILE *arquivo = fopen(ARQUIVO_BINARIO, "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de dados encontrado. Iniciando com dados vazios.\n");
        return;
    }

    // Carrega o número de tripulantes e o próximo ID
    fread(&total_tripulantes, sizeof(int), 1, arquivo);
    fread(&proximo_id, sizeof(int), 1, arquivo);

    // Carrega o vetor de tripulantes
    fread(tripulacao, sizeof(Tripulante), total_tripulantes, arquivo);

    fclose(arquivo);
    printf("Dados carregados com sucesso.\n");
}

// Função para cadastrar um novo tripulante
void cadastrarTripulante() {
    if (total_tripulantes >= MAX_TRIPULANTES) {
        printf("Limite de tripulantes atingido.\n");
        return;
    }

    Tripulante t;
    t.id = proximo_id++;
    printf("Nome: ");
    scanf(" %[^\n]", t.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", t.telefone);


    int opcao_cargo;
    printf("Escolha o cargo:\n");
    printf("1 - Piloto\n");
    printf("2 - Copiloto\n");
    printf("3 - Comissario\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao_cargo);

    // Atribuir o cargo com base na escolha
    switch (opcao_cargo) {
        case 1:
            strcpy(t.cargo, "Piloto");
            break;
        case 2:
            strcpy(t.cargo, "Copiloto");
            break;
        case 3:
            strcpy(t.cargo, "Comissario");
            break;
        default:
            printf("Opcao invalida! Cargo definido como 'Indefinido'.\n");
            strcpy(t.cargo, "Indefinido");
            break;
    }

    tripulacao[total_tripulantes++] = t;
    salvarDados();
    printf("Tripulante cadastrado com sucesso! ID: %d\n", t.id);
}

void deletarTripulante() {
    int id;
    printf("Digite o ID do integrante a ser deletado: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < total_tripulantes; i++) {
        if (tripulacao[i].id == id) {
            encontrado = 1;
            for (int j = i; j < total_tripulantes - 1; j++) {
                tripulacao[j] = tripulacao[j + 1];
            }
            total_tripulantes--;
            salvarDados(); // Salvar os dados após a exclusão
            printf("Tripulante excluido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Tripulante com ID %d nao encontrado.\n", id);
    }
}

void listarTripulantes() {
    if (total_tripulantes == 0) {
        printf("Nenhum tripulante cadastrado.\n");
        return;
    }

    printf("\nLista de Tripulantes:\n");
    for (int i = 0; i < total_tripulantes; i++) {
        Tripulante t = tripulacao[i];
        printf("ID: %d, Nome: %s, Telefone: %s, Cargo: %s\n", t.id, t.nome, t.telefone, t.cargo);
    }
}

void menuCadastro() {
    int opcao;
    do {
        printf("\nMenu de Cadastro de Tripulacao:\n");
        printf("1 - Cadastrar um integrante\n");
        printf("2 - Deletar um integrante\n");
        printf("3 - Listar tripulantes\n");
        printf("4 - Voltar ao menu principal\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTripulante();
                break;
            case 2:
                deletarTripulante();
                break;
            case 3:
                listarTripulantes();
                break;
            case 4:
                printf("Voltando ao menu principal...\n");
                break;
            case 5:
                printf("Saindo do sistema...\n");
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
}
