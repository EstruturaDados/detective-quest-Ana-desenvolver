
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
















