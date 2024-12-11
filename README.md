# Voo Seguro  
**Trabalho Interdisciplinar de AEDS e Fundamentos de Engenharia de Software**  

## Descrição do Projeto  
O projeto **Voo Seguro** foi desenvolvido em C++ e aborda conceitos fundamentais de algoritmos e desenvolvimento de sistemas. A aplicação simula um sistema de gerenciamento aéreo, permitindo realizar operações como cadastro e listagem de tripulantes, passageiros, voos e reservas.  

### Funcionalidades Implementadas  
- **Cadastro de Tripulantes**: Inclui nome, telefone, cargo e ID autoincrementado.   
- **Listagem de Tripulantes**: Exibe todos os registros.  
- **Armazenamento em Arquivo**: Dados salvos em formato binário para persistência.  


Aqui está a seção formatada no padrão que você prefere:  

---

### Funcionalidades Implementadas  

- **Cadastro de Passageiro**: Garante que não haja passageiros com id's duplicados e permite a geração automática do id.  
- **Cadastro de Tripulação**: Permite definir cargos específicos para cada membro da tripulação, e cria de forma automática os IDs para cada tripulante.  
- **Cadastro de Voo**: Inclui informações como data, hora, origem, destino, tarifa, tripulação e avião. Verifica a presença de pelo menos um piloto e um copiloto para ativar o voo.  
- **Cadastro de Assento**: Gera e organiza os assentos disponíveis para cada voo.  
- **Reserva de Assento**: Verifica a disponibilidade do assento antes da reserva e impede duplicidade para o mesmo assento em um voo.  
- **Baixa em Reserva**: Libera o assento reservado, atualizando seu status para "livre", e calcula o valor total a ser pago de acordo com a tarifa do voo, se necessário.  
- **Pesquisa**: Permite buscar passageiros e tripulantes pelo nome ou código e listar os voos associados a um passageiro.  
- **Programa de Fidelidade**: Cada voo concede 10 pontos de fidelidade ao passageiro, que podem ser acumulados ao longo de múltiplos voos.  





## Tecnologias Utilizadas  
- Linguagem: C++  
- Estruturas de Dados: Arrays  
- Conceitos: Classes, Repetições (for, while, do-while)  
- Arquivos: Binários para persistência de dados  

## Metodologias e Organização  
Adotamos práticas de metodologias ágeis, com destaque para o **Scrum**, onde dividimos o trabalho em sprints. Utilizamos o **Kanban** para gerenciar o backlog e acompanhar o progresso.  

### Ferramentas de Organização  
- **Kanban**: Organização das tarefas por meio de um quadro visual no github projects.  
- **GitHub**: Controle de versão e colaboração.  

## Integrantes  

<table>
  <tr>
      <td align="center">
      <a href="https://github.com/eduardavieira-dev" title="Foto">
        <img src="https://avatars.githubusercontent.com/u/159597766?v=4" width="100px;" alt="Foto da Eduarda V."/><br>
        <sub>
          <b>Eduarda Vieira</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Eric-Leal" title="Foto">
        <img src="https://avatars.githubusercontent.com/u/181984841?v=4" width="100px;" alt="Foto do Eric Leal"/><br>
        <sub>
          <b>Eric Leal</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/LauraPontara" title="Foto">
        <img src="https://avatars.githubusercontent.com/u/179180583?v=4" width="100px;" alt="Foto da Laura"/><br>
        <sub>
          <b>Laura Pontara</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

### Apresentação do Voo-Seguro:

https://github.com/user-attachments/assets/7152008a-d4b2-4f4c-8fcf-3f12b1d5df71


## Como Executar o Projeto no VSCode 
1. Clone o repositório:  
   ```bash
   git clone https://github.com/eduardavieira-dev/Voo-Seguro.git
2. Compile o código:

    ```bash
    g++ -o voo_seguro main.cpp Assento.cpp Passageiro.cpp Pesquisa.cpp Reserva.cpp tripulacao.cpp Voo.cpp
    ```
3. Execute a aplicação:

    ```bash
       ./voo_seguro
    ```


#### Outra alternativa para executar o projeto no CodeBlocks

Após clonar o projeto no seu computador entre no codeBlocks. 
Cligue em: File > New > Project > Console Aplication > C++

Nomeie o projeto como Voo-seguro, procure a pasta do Voo-seguro que voce clonou no computador e por fim clique em finish.

Após ter feito este processo na parte de workspace -Voo-seguro +Sources clique com o botão direito em cima do Voo-seguro depois clique em Add Files, após isso encontre a pasta com os arquivos do projeto e adicione todos os arquivos.

Clique em Sources e abra o main.cpp Na primeira ver que rodar voce será direcionado ao main que mostra a mensagem    cout << "Hello world!" << endl; Exclua todo o escrito desse arquivo e volte ao main.cpp do Voo-seguro correto e rode o programa novamente. E pronto!! Use o sistema e teste as funcionalidades como desejar.
