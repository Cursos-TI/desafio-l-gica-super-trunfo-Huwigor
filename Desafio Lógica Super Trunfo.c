#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para as cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2, pontos_turisticos1, pontos_turisticos2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pib_per_capita1, pib_per_capita2;

    // Propriedade escolhida para comparação (1=População, 2=Área, 3=PIB, 4=Densidade, 5=PIB per capita)
    const int PROPRIEDADE_COMPARACAO = 1; // Alterar conforme necessário

    printf("=== SUPER TRUNFO DE PAÍSES ===\n");
    printf("Cadastre duas cartas para compará-las\n\n");

    // Cadastro da Carta 1
    printf("CADASTRO CARTA 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    
    printf("População: ");
    scanf("%d", &populacao1);
    
    printf("Área (em km²): ");
    scanf("%f", &area1);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cálculos para Carta 1
    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1; // Convertendo bilhões para unidades

    // Exibição Carta 1
    printf("\nCARTA 1 CADASTRADA:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);
    printf("Pontos Turísticos: %d\n\n", pontos_turisticos1);

    // Cadastro da Carta 2
    printf("CADASTRO CARTA 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    
    printf("População: ");
    scanf("%d", &populacao2);
    
    printf("Área (em km²): ");
    scanf("%f", &area2);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos para Carta 2
    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // Exibição Carta 2
    printf("\nCARTA 2 CADASTRADA:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);
    printf("Pontos Turísticos: %d\n\n", pontos_turisticos2);

    // Comparação das cartas
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    
    // Exibe as cartas resumidas
    printf("Carta 1: %s (%s) - Pop: %d, Área: %.2f, PIB: %.2f\n", 
           cidade1, codigo1, populacao1, area1, pib1);
    printf("Carta 2: %s (%s) - Pop: %d, Área: %.2f, PIB: %.2f\n", 
           cidade2, codigo2, populacao2, area2, pib2);
    
    // Determina o vencedor com base na propriedade escolhida
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2
    float valor1, valor2;
    char *propriedade = "";
    
    switch(PROPRIEDADE_COMPARACAO) {
        case 1: // População
            valor1 = populacao1;
            valor2 = populacao2;
            propriedade = "POPULAÇÃO";
            vencedor = (valor1 > valor2) ? 1 : ((valor2 > valor1) ? 2 : 0);
            break;
            
        case 2: // Área
            valor1 = area1;
            valor2 = area2;
            propriedade = "ÁREA";
            vencedor = (valor1 > valor2) ? 1 : ((valor2 > valor1) ? 2 : 0);
            break;
            
        case 3: // PIB
            valor1 = pib1;
            valor2 = pib2;
            propriedade = "PIB";
            vencedor = (valor1 > valor2) ? 1 : ((valor2 > valor1) ? 2 : 0);
            break;
            
        case 4: // Densidade Populacional
            valor1 = densidade1;
            valor2 = densidade2;
            propriedade = "DENSIDADE POPULACIONAL";
            // Para densidade, ganha quem tiver MENOR valor
            vencedor = (valor1 < valor2) ? 1 : ((valor2 < valor1) ? 2 : 0);
            break;
            
        case 5: // PIB per capita
            valor1 = pib_per_capita1;
            valor2 = pib_per_capita2;
            propriedade = "PIB PER CAPITA";
            vencedor = (valor1 > valor2) ? 1 : ((valor2 > valor1) ? 2 : 0);
            break;
            
        default:
            printf("Propriedade de comparação inválida!\n");
            return 1;
    }
    
    printf("\nComparando por: %s\n", propriedade);
    
    if (vencedor == 0) {
        printf("EMPATE! Ambas as cartas têm o mesmo valor para %s.\n", propriedade);
    } else if (vencedor == 1) {
        printf("VENCEDOR: CARTA 1 - %s (%s) com %.2f vs %.2f\n", 
               cidade1, codigo1, valor1, valor2);
    } else {
        printf("VENCEDOR: CARTA 2 - %s (%s) com %.2f vs %.2f\n", 
               cidade2, codigo2, valor2, valor1);
    }

    return 0;
}