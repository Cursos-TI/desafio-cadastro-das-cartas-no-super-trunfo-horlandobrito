#include <stdio.h>
#include <string.h>

// Constantes para tamanhos máximos
#define MAX_CIDADE 50
#define TAM_CODIGO 4
#define NUM_CARTAS 2

int main() {
    // Variáveis para armazenar os dados das cartas
    char estados[NUM_CARTAS];               // Estados (A-H)
    char codigos[NUM_CARTAS][TAM_CODIGO];    // Códigos (A01, B02, etc)
    char cidades[NUM_CARTAS][MAX_CIDADE];    // Nomes das cidades
    int populacoes[NUM_CARTAS];              // Populações
    float areas[NUM_CARTAS];                 // Áreas em km²
    float pibs[NUM_CARTAS];                  // PIBs em bilhões
    int pontos_turisticos[NUM_CARTAS];       // Pontos turísticos

    void cadastrarCarta(int index) {
        printf("\n--- Carta %d ---\n", index + 1);
        
        // Estado (A-H)
        printf("Estado (A-H): ");
        scanf(" %c", &estados[index]);
        getchar(); // Limpa o buffer
        
        // Código da carta (ex: A01)
        printf("Código da Carta (%c##): ", estados[index]);
        scanf("%3s", codigos[index]);
        getchar();
        
        // Nome da cidade
        printf("Nome da Cidade: ");
        fgets(cidades[index], MAX_CIDADE, stdin);
        cidades[index][strcspn(cidades[index], "\n")] = '\0';
        
        // População
        printf("População: ");
        scanf("%d", &populacoes[index]);
        
        // Área
        printf("Área (km²): ");
        scanf("%f", &areas[index]);
        
        // PIB
        printf("PIB (bilhões de reais): ");
        scanf("%f", &pibs[index]);
        
        // Pontos turísticos
        printf("Número de Pontos Turísticos: ");
        scanf("%d", &pontos_turisticos[index]);
        getchar();
    }

    void exibirCarta(int index) {
        printf("\nCarta %d:\n", index + 1);
        printf("Estado: %c\n", estados[index]);
        printf("Código: %s\n", codigos[index]);
        printf("Nome da Cidade: %s\n", cidades[index]);
        printf("População: %d\n", populacoes[index]);
        printf("Área: %.2f km²\n", areas[index]);
        printf("PIB: %.2f bilhões de reais\n", pibs[index]);
        printf("Número de Pontos Turísticos: %d\n", pontos_turisticos[index]);
    }

    int main() {
        printf("=== Cadastro de Cartas do Super Trunfo de Países ===\n\n");
    
        // Cadastrar as duas cartas
        for (int i = 0; i < NUM_CARTAS; i++) {
            cadastrarCarta(i);
        }
    
        // Exibir as cartas cadastradas
        printf("\n=== Cartas Cadastradas ===\n");
        for (int i = 0; i < NUM_CARTAS; i++) {
            exibirCarta(i);
        printf("Novo commit\n");

        }
    
        return 0;
    }