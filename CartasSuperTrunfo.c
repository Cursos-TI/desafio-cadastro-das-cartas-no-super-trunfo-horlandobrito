#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constantes para tamanhos máximos
#define MAX_CIDADE 50
#define TAM_CODIGO 4
#define NUM_CARTAS 2

// Função para cadastrar uma carta
void cadastrarCarta(char *estado, char *codigo, char *cidade, 
                   unsigned long int *populacao, float *area, float *pib, 
                   int *pontos_turisticos, int numero_carta) {
    printf("\n--- Carta %d ---\n", numero_carta);
    
    printf("Estado (A-H): ");
    scanf(" %c", estado);
    getchar();
    
    printf("Código da Carta (%c##): ", *estado);
    scanf("%3s", codigo);
    getchar();
    
    printf("Nome da Cidade: ");
    fgets(cidade, MAX_CIDADE, stdin);
    cidade[strcspn(cidade, "\n")] = '\0';
    
    printf("População: ");
    scanf("%lu", populacao);
    
    printf("Área (km²): ");
    scanf("%f", area);
    
    printf("PIB (bilhões de reais): ");
    scanf("%f", pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontos_turisticos);
    getchar();
}

// Função para exibir uma carta
void exibirCarta(char estado, char *codigo, char *cidade, 
                unsigned long int populacao, float area, float pib, 
                int pontos_turisticos, int numero_carta) {
    printf("\nCarta %d:\n", numero_carta);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos);
}

// Função para comparar e mostrar resultado
void compararAtributo(const char *nomeAtributo, float valor1, float valor2, int inverso) {
    int resultado;
    
    if (inverso) {
        resultado = valor1 < valor2;
    } else {
        resultado = valor1 > valor2;
    }
    
    printf("%s: Carta %d venceu (%d)\n", nomeAtributo, resultado ? 1 : 2, resultado);
}

int main() {
    // Variáveis para armazenar os dados das cartas
    char estados[NUM_CARTAS];
    char codigos[NUM_CARTAS][TAM_CODIGO];
    char cidades[NUM_CARTAS][MAX_CIDADE];
    unsigned long int populacoes[NUM_CARTAS];
    float areas[NUM_CARTAS];
    float pibs[NUM_CARTAS];
    int pontos_turisticos[NUM_CARTAS];
    
    // Variáveis calculadas
    float densidades[NUM_CARTAS];
    float pib_per_capita[NUM_CARTAS];
    float super_poder[NUM_CARTAS];

    printf("=== Cadastro de Cartas do Super Trunfo de Países ===\n\n");

    // Cadastrar as duas cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        cadastrarCarta(&estados[i], codigos[i], cidades[i], 
                      &populacoes[i], &areas[i], &pibs[i], 
                      &pontos_turisticos[i], i+1);
        
        // Calcular métricas derivadas
        densidades[i] = areas[i] > 0 ? populacoes[i] / areas[i] : 0;
        pib_per_capita[i] = populacoes[i] > 0 ? (pibs[i] * 1e9) / populacoes[i] : 0;
        
        // Calcular Super Poder (soma de todos os atributos numéricos)
        // Incluindo o inverso da densidade (quanto menor a densidade, maior o poder)
        float inverso_densidade = densidades[i] > 0 ? 1 / densidades[i] : 0;
        super_poder[i] = populacoes[i] + areas[i] + pibs[i] + pontos_turisticos[i] + pib_per_capita[i] + inverso_densidade;
    }

    // Exibir as cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(estados[i], codigos[i], cidades[i], 
                   populacoes[i], areas[i], pibs[i], 
                   pontos_turisticos[i], i+1);
        printf("Densidade Populacional: %.2f hab/km²\n", densidades[i]);
        printf("PIB per capita: R$ %.2f\n", pib_per_capita[i]);
        printf("Super Poder: %.2f\n\n", super_poder[i]);
    }

    // Comparar as cartas
    printf("\n=== RESULTADO DAS COMPARAÇÕES ===\n");
    printf("Carta 1: %s\n", cidades[0]);
    printf("Carta 2: %s\n\n", cidades[1]);
    
    // Comparar cada atributo
    compararAtributo("População", populacoes[0], populacoes[1], 0);
    compararAtributo("Área", areas[0], areas[1], 0);
    compararAtributo("PIB", pibs[0], pibs[1], 0);
    compararAtributo("Pontos Turísticos", pontos_turisticos[0], pontos_turisticos[1], 0);
    compararAtributo("Densidade Populacional", densidades[0], densidades[1], 1);
    compararAtributo("PIB per Capita", pib_per_capita[0], pib_per_capita[1], 0);
    compararAtributo("Super Poder", super_poder[0], super_poder[1], 0);

    return 0;
}