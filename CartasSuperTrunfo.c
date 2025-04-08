#include <stdio.h>
#include <string.h>

// Constantes para tamanhos máximos
#define MAX_CIDADE 50
#define TAM_CODIGO 4
#define NUM_CARTAS 2

// Função para cadastrar uma carta
void cadastrarCarta(char *estado, char *codigo, char *cidade, 
                   int *populacao, float *area, float *pib, 
                   int *pontos_turisticos, int numero_carta) {
    printf("\n--- Carta %d ---\n", numero_carta);
    
    // Estado (A-H)
    printf("Estado (A-H): ");
    scanf(" %c", estado);
    getchar(); // Limpa o buffer
    
    // Código da carta (ex: A01)
    printf("Código da Carta (%c##): ", *estado);
    scanf("%3s", codigo);
    getchar();
    
    // Nome da cidade
    printf("Nome da Cidade: ");
    fgets(cidade, MAX_CIDADE, stdin);
    cidade[strcspn(cidade, "\n")] = '\0';
    
    // População
    printf("População: ");
    scanf("%d", populacao);
    
    // Área
    printf("Área (km²): ");
    scanf("%f", area);
    
    // PIB
    printf("PIB (bilhões de reais): ");
    scanf("%f", pib);
    
    // Pontos turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontos_turisticos);
    getchar();
}

// Função para exibir uma carta
void exibirCarta(char estado, char *codigo, char *cidade, 
                int populacao, float area, float pib, 
                int pontos_turisticos, int numero_carta) {
    printf("\nCarta %d:\n", numero_carta);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos);
}

int main() {
    // Variáveis para armazenar os dados das cartas
    char estados[NUM_CARTAS];               // Estados (A-H)
    char codigos[NUM_CARTAS][TAM_CODIGO];    // Códigos (A01, B02, etc)
    char cidades[NUM_CARTAS][MAX_CIDADE];    // Nomes das cidades
    int populacoes[NUM_CARTAS];              // Populações
    float areas[NUM_CARTAS];                 // Áreas em km²
    float pibs[NUM_CARTAS];                  // PIBs em bilhões
    int pontos_turisticos[NUM_CARTAS];       // Pontos turísticos

    printf("=== Cadastro de Cartas do Super Trunfo de Países ===\n\n");

    // Cadastrar as duas cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        cadastrarCarta(&estados[i], codigos[i], cidades[i], 
                      &populacoes[i], &areas[i], &pibs[i], 
                      &pontos_turisticos[i], i+1);
    }

    // Exibir as cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(estados[i], codigos[i], cidades[i], 
                   populacoes[i], areas[i], pibs[i], 
                   pontos_turisticos[i], i+1);
    }

    return 0;
}