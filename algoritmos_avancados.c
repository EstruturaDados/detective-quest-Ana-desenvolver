
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

//  EXPLORAÇÃO INTERATIVA
// O jogador navega pela árvore pode escolher:
//   'e' → ir para a esquerda
//   'd' → ir para a direita
//   's' → sair do jogo 

void explorarSalas(Sala* atual) {
// Loop principal da exploração
    while (atual != NULL) {
        printf("\nVocê está na sala: %s\n", atual->nome);

        // Verifica se chegou a um nó-folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho! Você chegou ao final da exploração.\n");
            return;
        }

char opcao;
        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL) printf("  (e) Ir para a ESQUERDA\n");
        if (atual->direita != NULL)  printf("  (d) Ir para a DIREITA\n");
        printf("  (s) Sair\n");
        printf("Sua escolha: ");
        scanf(" %c", &opcao);

  if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;  // move para o nó à esquerda
        }
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;   // move para o nó à direita
        }
        else if (opcao == 's') {
            printf("Exploração encerrada.\n");
            return;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

//  MONTAGEM DO MAPA DA MANSÃO
// A árvore é criada manualmente 
int main() {
    // Criação das salas
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



