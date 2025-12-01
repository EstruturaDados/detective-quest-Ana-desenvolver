
// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Nível Novato: Mapa da Mansão com Árvore Binária
 

   #include <stdio.h>
   #include <stdlib.h>

// Cada sala é um nó de uma árvore binária
typedef struct Sala {
    char nome[50];           // Nome do cômodo
    struct Sala *esquerda;   // Caminho à esquerda
    struct Sala *direita;    // Caminho à direita
} Sala;

//  CRIA UMA NOVA SALA
// Recebe o nome do cômodo
// Aloca memória dinamicamente e devolve o ponteiro para o nó criado

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));  // aloca memória para a sala
    if (!nova) {                                // verifica erro de alocação
        printf("Erro ao alocar memoria!\n");
        exit(1);
}
// Copia o nome recebido para dentro da estrutura
    strcpy(nova->nome, nome);

    // Inicialmente, não há caminhos (nó folha)
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;  // retorna a sala criada
}













