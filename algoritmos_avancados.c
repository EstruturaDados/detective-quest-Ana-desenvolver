
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

// CRIA UMA NOVA SALA
// Recebe o nome do cômodo
// Aloca memória dinamicamente um nó (sala)

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));  // aloca memória para a sala
    if (!nova) {                                // verifica erro de alocação
        printf("Erro ao alocar memoria!\n");
        exit(1);
}

 // Copia o nome recebido para dentro da estrutura
    strcpy(nova->nome, nome); // copia o texto para a string da struct

// Inicialmente, não há caminhos (nó folha)
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;  // retorna a sala criada
}

//  EXPLORAR SALAS
// O jogador começa pelo hall e escolhe caminhos:
//   'e' → ir para a esquerda
//   'd' → ir para a direita
//   's' → sair do jogo 

void explorarSalas(Sala* atual) {
// Loop principal da exploração

char opcao;

while (1) {

        // Exibe o cômodo atual
        printf("\nVocê está em: **%s**\n", atual->nome);

        // Se chegou a um nó-folha, o caminho termina
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf(" Você chegou ao fim do caminho!\n");
            return;
        }

        printf("\nEscolha uma direção:\n");
        if (atual->esquerda != NULL) printf("  e → ir para a esquerda (%s)\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf("  d → ir para a direita (%s)\n", atual->direita->nome);
        printf("  s → sair\n");

        printf("\nOpção: ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\nVocê decidiu sair da exploração.\n");
            return;
        }
        else if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;   // avança para a esquerda
        }
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;    // avança para a direita
        }
        else {
            printf("\n Caminho inválido. Tente novamente.\n");
        }
    }
}

//  MONTAGEM DO MAPA DA MANSÃO
// A árvore é criada manualmente 
int main() {
    // Criando  os cômodos
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* laboratorio = criarSala("Laboratório");

 // Montando os caminhos da mansão
    hall->esquerda = salaEstar;
    hall->direita  = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita  = laboratorio;

    // Início do jogo
    printf("=== EXPLORAÇÃO DA MANSÃO (Nível Novato) ===\n");
    explorarSalas(hall);

    return 0;
}



