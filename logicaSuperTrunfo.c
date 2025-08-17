#include <stdio.h>
#include <string.h>

/*
Super Trunfo - Países (Cidades) - Nível Novato
- Cadastro de 2 cartas via terminal
- Exibição organizada das cartas
- Comparação por um atributo definido NO CÓDIGO:
    1 = População        (maior vence)
    2 = Área (km²)       (maior vence)
    3 = PIB (bilhões)    (maior vence)
    4 = Pontos turísticos(maior vence)
    5 = Densidade hab/km²(menor vence)  << regra especial
*/

#define COMPARE_ATTR 3
/* Altere o valor acima para 1..5 conforme a comparação desejada:
   1 População | 2 Área | 3 PIB | 4 Pontos Turísticos | 5 Densidade (menor vence)
*/

typedef struct {
    char estado[32];         // Ex.: "SP"
    char codigo[16];         // Ex.: "A01"
    char cidade[64];         // Ex.: "São_Paulo" (use _ no lugar de espaço se preferir)
    long long populacao;     // habitantes
    double area;             // km²
    double pib;              // bilhões (use ponto como separador decimal)
    int pontosTuristicos;    // quantidade
} Carta;

double densidade(const Carta *c) {
    if (c->area <= 0.0) return 0.0;
    return (double)c->populacao / c->area;
}

void lerCarta(Carta *c, int idx) {
    printf("\n=== Cadastro da Carta %d ===\n", idx);
    printf("Estado (ex: SP): ");
    scanf("%31s", c->estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%15s", c->codigo);

    printf("Cidade (sem espacos ou use _): ");
    scanf("%63s", c->cidade);

    printf("Populacao (habitantes): ");
    scanf("%lld", &c->populacao);

    printf("Area (km2): ");
    scanf("%lf", &c->area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &c->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);
}

void exibirCarta(const Carta *c, const char *titulo) {
    printf("\n--- %s ---\n", titulo);
    printf("Estado: %s\n", c->estado);
    printf("Codigo: %s\n", c->codigo);
    printf("Cidade: %s\n", c->cidade);
    printf("Populacao: %lld\n", c->populacao);
    printf("Area (km2): %.2f\n", c->area);
    printf("PIB (bilhoes): %.2f\n", c->pib);
    printf("Pontos turisticos: %d\n", c->pontosTuristicos);
    printf("Densidade (hab/km2): %.2f\n", densidade(c));
}

int comparar(const Carta *a, const Carta *b, int attr) {
    // Retorna: -1 se A perde para B, 0 se empata, 1 se A vence B
    switch (attr) {
        case 1: // População - maior vence
            if (a->populacao > b->populacao) return 1;
            if (a->populacao < b->populacao) return -1;
            return 0;
        case 2: // Área - maior vence
            if (a->area > b->area) return 1;
            if (a->area < b->area) return -1;
            return 0;
        case 3: // PIB - maior vence
            if (a->pib > b->pib) return 1;
            if (a->pib < b->pib) return -1;
            return 0;
        case 4: // Pontos turísticos - maior vence
            if (a->pontosTuristicos > b->pontosTuristicos) return 1;
            if (a->pontosTuristicos < b->pontosTuristicos) return -1;
            return 0;
        case 5: { // Densidade - MENOR vence (regra especial)
            double da = densidade(a);
            double db = densidade(b);
            if (da < db) return 1;
            if (da > db) return -1;
            return 0;
        }
        default:
            // atributo inválido => empate
            return 0;
    }
}

const char* nomeAtributo(int attr) {
    switch (attr) {
        case 1: return "Populacao (maior vence)";
        case 2: return "Area (maior vence)";
        case 3: return "PIB (maior vence)";
        case 4: return "Pontos turisticos (maior vence)";
        case 5: return "Densidade (MENOR vence)";
        default: return "Atributo desconhecido";
    }
}

int main(void) {
    Carta c1, c2;

    printf("=== Super Trunfo - Cidades (Nivel Novato) ===\n");
    printf("Comparacao definida no codigo: %s (COMPARE_ATTR=%d)\n", nomeAtributo(COMPARE_ATTR), COMPARE_ATTR);

    lerCarta(&c1, 1);
    lerCarta(&c2, 2);

    exibirCarta(&c1, "Carta 1");
    exibirCarta(&c2, "Carta 2");

    int r = comparar(&c1, &c2, COMPARE_ATTR);

    printf("\n=== Resultado ===\n");
    if (r > 0) {
        printf("Carta 1 (%s - %s) VENCE por %s.\n", c1.estado, c1.cidade, nomeAtributo(COMPARE_ATTR));
    } else if (r < 0) {
        printf("Carta 2 (%s - %s) VENCE por %s.\n", c2.estado, c2.cidade, nomeAtributo(COMPARE_ATTR));
    } else {
        printf("Empate em %s.\n", nomeAtributo(COMPARE_ATTR));
    }

    return 0;
}
