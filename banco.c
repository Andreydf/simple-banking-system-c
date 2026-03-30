#include <stdio.h>
#define MAX 100

int main() {
    
    int opcao, i = 0;
    float saldo = 0, valor;
    float historico[MAX];

    while (1) {
        printf("\n--- BANCO ---\n");
        printf("1 - Ver saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Ver historico\n");
        printf("5 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Saldo atual: R$ %.2f\n", saldo);

        } else if (opcao == 2) {
            printf("Digite o valor do deposito: ");
            scanf("%f", &valor);

            if (valor > 0) {
                saldo += valor;

                if (i < MAX) {
                    historico[i++] = valor;
                }

                printf("Deposito de R$ %.2f realizado!\n", valor);
            } else {
                printf("Valor invalido!\n");
            }

        } else if (opcao == 3) {
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);

            if (valor > saldo) {
                printf("Saldo insuficiente!\n");

            } else if (valor <= 0) {
                printf("Valor invalido!\n");

            } else {
                saldo -= valor;

                if (i < MAX) {
                    historico[i++] = -valor;
                }

                printf("Saque de R$ %.2f realizado!\n", valor);
            }

        } else if (opcao == 4) {
            printf("\n--- HISTORICO ---\n");

            if (i == 0) {
                printf("Nenhuma transacao ainda.\n");
            } else {
                for (int j = 0; j < i; j++) {
                    if (historico[j] > 0) {
                        printf("Deposito: R$ %.2f\n", historico[j]);
                    } else {
                        printf("Saque: R$ %.2f\n", historico[j]);
                    }
                }
            }

        } else if (opcao == 5) {
            printf("Encerrando sistema...\n");
            break;

        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}