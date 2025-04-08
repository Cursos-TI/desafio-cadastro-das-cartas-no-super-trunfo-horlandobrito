#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constantes para tamanhos máximos
#define MAX_CIDADE 50
#define TAM_CODIGO 4
#define NUM_CARTAS 2

// Função para cadastrar uma carta (mantida do código anterior)
void cadastrarCarta(char *estado, char *codigo, char *cidade, 
                   int *populacao, float *area, float *pib, 
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
    scanf("%d", populacao);
    
    printf("Área (km²): ");
    scanf("%f", area);
    
    printf("PIB (bilhões de reais): ");
    scanf("%f", pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontos_turisticos);
    getchar();
}

// Função para exibir uma carta (mantida do código anterior)
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

// Função para mostrar o menu e obter a escolha do usuário
int mostrarMenu() {
    int escolha;
    
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1. Comparar por População\n");
    printf("2. Comparar por Área\n");
    printf("3. Comparar por PIB\n");
    printf("4. Comparar por Pontos Turísticos\n");
    printf("5. Comparar por Densidade Demográfica\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    
    return escolha;
}

// Função principal com a lógica de comparação
int main() {
    // Variáveis para armazenar os dados das cartas
    char estados[NUM_CARTAS];
    char codigos[NUM_CARTAS][TAM_CODIGO];
    char cidades[NUM_CARTAS][MAX_CIDADE];
    int populacoes[NUM_CARTAS];
    float areas[NUM_CARTAS];
    float pibs[NUM_CARTAS];
    int pontos_turisticos[NUM_CARTAS];
    float densidades[NUM_CARTAS];

    printf("=== Cadastro de Cartas do Super Trunfo de Países ===\n\n");

    // Cadastrar as duas cartas
    for (int i = 0; i < NUM_CARTAS; i++) {
        cadastrarCarta(&estados[i], codigos[i], cidades[i], 
                      &populacoes[i], &areas[i], &pibs[i], 
                      &pontos_turisticos[i], i+1);
        
        // Calcular densidade demográfica (população/área)
        densidades[i] = populacoes[i] / areas[i];
    }

    // Exibir as cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(estados[i], codigos[i], cidades[i], 
                   populacoes[i], areas[i], pibs[i], 
                   pontos_turisticos[i], i+1);
        printf("Densidade Demográfica: %.2f hab/km²\n", densidades[i]);
    }

    // Menu interativo
    int opcao;
    do {
        opcao = mostrarMenu();
        
        if (opcao == 0) {
            printf("Saindo do jogo...\n");
            break;
        }
        
        if (opcao < 1 || opcao > 5) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }
        
        // Comparar as cartas
        printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
        printf("Carta 1: %s\n", cidades[0]);
        printf("Carta 2: %s\n", cidades[1]);
        
        switch(opcao) {
            case 1: // População
                printf("Atributo: População\n");
                printf("%s: %d habitantes\n", cidades[0], populacoes[0]);
                printf("%s: %d habitantes\n", cidades[1], populacoes[1]);
                
                if (populacoes[0] > populacoes[1]) {
                    printf("Vencedor: %s\n", cidades[0]);
                } else if (populacoes[1] > populacoes[0]) {
                    printf("Vencedor: %s\n", cidades[1]);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", cidades[0], areas[0]);
                printf("%s: %.2f km²\n", cidades[1], areas[1]);
                
                if (areas[0] > areas[1]) {
                    printf("Vencedor: %s\n", cidades[0]);
                } else if (areas[1] > areas[0]) {
                    printf("Vencedor: %s\n", cidades[1]);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhões\n", cidades[0], pibs[0]);
                printf("%s: %.2f bilhões\n", cidades[1], pibs[1]);
                
                if (pibs[0] > pibs[1]) {
                    printf("Vencedor: %s\n", cidades[0]);
                } else if (pibs[1] > pibs[0]) {
                    printf("Vencedor: %s\n", cidades[1]);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d pontos\n", cidades[0], pontos_turisticos[0]);
                printf("%s: %d pontos\n", cidades[1], pontos_turisticos[1]);
                
                if (pontos_turisticos[0] > pontos_turisticos[1]) {
                    printf("Vencedor: %s\n", cidades[0]);
                } else if (pontos_turisticos[1] > pontos_turisticos[0]) {
                    printf("Vencedor: %s\n", cidades[1]);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("Atributo: Densidade Demográfica (menor vence)\n");
                printf("%s: %.2f hab/km²\n", cidades[0], densidades[0]);
                printf("%s: %.2f hab/km²\n", cidades[1], densidades[1]);
                
                if (densidades[0] < densidades[1]) {
                    printf("Vencedor: %s\n", cidades[0]);
                } else if (densidades[1] < densidades[0]) {
                    printf("Vencedor: %s\n", cidades[1]);
                } else {
                    printf("Empate!\n");
                }
                break;
        }
        
    } while (opcao != 0);

    return 0;
}