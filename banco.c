#include <stdio.h>
#define MAX 100

struct Conta {
    float saldo;
    float historico[MAX];
    int totalTransacoes;
};

void menu() {
    printf("\n--- BANCO ---\n");
    printf("1 - Ver saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Ver historico\n");
    printf("5 - Sair\n");
    printf("Escolha: ");
}

void verSaldo(struct Conta conta) {
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

void depositar(struct Conta *conta) {
    float valor;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);

    if (valor > 0) {
        conta->saldo += valor;

        if (conta->totalTransacoes < MAX) {
            conta->historico[conta->totalTransacoes++] = valor;
        }

        printf("Deposito de R$ %.2f realizado!\n", valor);
    } else {
        printf("Valor invalido!\n");
    }
}

void sacar(struct Conta *conta) {
    float valor;
    printf("Digite o valor do saque: ");
    scanf("%f", &valor);

    if (valor > conta->saldo) {
        printf("Saldo insuficiente!\n");

    } else if (valor <= 0) {
        printf("Valor invalido!\n");

    } else {
        conta->saldo -= valor;

        if (conta->totalTransacoes < MAX) {
            conta->historico[conta->totalTransacoes++] = -valor;
        }

        printf("Saque de R$ %.2f realizado!\n", valor);
    }
}

void mostrarHistorico(struct Conta conta) {
    printf("\n--- HISTORICO ---\n");

    if (conta.totalTransacoes == 0) {
        printf("Nenhuma transacao ainda.\n");
    } else {
        for (int i = 0; i < conta.totalTransacoes; i++) {
            if (conta.historico[i] > 0) {
                printf("Deposito: R$ %.2f\n", conta.historico[i]);
            } else {
                printf("Saque: R$ %.2f\n", conta.historico[i]);
            }
        }
    }
}

int main() {
    struct Conta conta;
    conta.saldo = 0;
    conta.totalTransacoes = 0;

    int opcao;

    while (1) {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            verSaldo(conta);

        } else if (opcao == 2) {
            depositar(&conta);

        } else if (opcao == 3) {
            sacar(&conta);

        } else if (opcao == 4) {
            mostrarHistorico(conta);

        } else if (opcao == 5) {
            printf("Encerrando sistema...\n");
            break;

        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
