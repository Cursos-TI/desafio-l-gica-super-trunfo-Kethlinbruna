#include <stdio.h>
#include <string.h> // Necessário para manipulação de strings

// Define a estrutura de dados para uma carta
struct Carta {
    char estado[3];
    int codigo;
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // Produto Interno Bruto
    int pontosTuristicos;
};

int main() {
    // Declara duas variáveis do tipo Carta
    struct Carta carta1, carta2;

    // --- Cadastro da Carta 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o estado (sigla com 2 letras): ");
    scanf("%2s", carta1.estado);

    printf("Digite o codigo da carta: ");
    scanf("%d", &carta1.codigo);

    printf("Digite o nome da cidade: ");
    // Limpa o buffer de entrada antes de ler a string para evitar pular a leitura
    getchar(); 
    fgets(carta1.nomeCidade, 50, stdin);
    // Remove o caractere de nova linha que o fgets adiciona
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Digite a area (em km2): ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("\n");

    // --- Cadastro da Carta 2 ---
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Digite o estado (sigla com 2 letras): ");
    scanf("%2s", carta2.estado);

    printf("Digite o codigo da carta: ");
    scanf("%d", &carta2.codigo);

    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta2.nomeCidade, 50, stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Digite a area (em km2): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("\n");

    // --- Exibição das Cartas Cadastradas ---
    printf("----------------------------------------\n");
    printf("           CARTAS CADASTRADAS\n");
    printf("----------------------------------------\n");
    printf("CARTA 1 (%s - %d): %s\n", carta1.estado, carta1.codigo, carta1.nomeCidade);
    printf("  - Populacao: %d habitantes\n", carta1.populacao);
    printf("  - Area: %.2f km2\n", carta1.area);
    printf("  - PIB: R$ %.2f bilhoes\n", carta1.pib);
    printf("  - Pontos Turisticos: %d\n\n", carta1.pontosTuristicos);

    printf("CARTA 2 (%s - %d): %s\n", carta2.estado, carta2.codigo, carta2.nomeCidade);
    printf("  - Populacao: %d habitantes\n", carta2.populacao);
    printf("  - Area: %.2f km2\n", carta2.area);
    printf("  - PIB: R$ %.2f bilhoes\n", carta2.pib);
    printf("  - Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("----------------------------------------\n\n");

    // --- Comparação e Resultado ---
    // A regra de comparação foi definida no código: maior PIB vence.
    printf("--- RESULTADO DA COMPARACAO (MAIOR PIB) ---\n");

    if (carta1.pib > carta2.pib) {
        printf("A carta vencedora e a CARTA 1: %s!\n", carta1.nomeCidade);
    } else if (carta2.pib > carta1.pib) {
        printf("A carta vencedora e a CARTA 2: %s!\n", carta2.nomeCidade);
    } else {
        printf("Houve um empate no atributo PIB!\n");
    }

    return 0;
}
