#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <windows.h>

void handle_sigint(int sig) {
    printf("\nПрограмма завершена.\n", sig);
    exit(0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char operation[10];
    int operand1, operand2, result;
    char operator;

    signal(SIGINT, handle_sigint);

    printf("Введите арифметическую операцию с однозначными операндами (например, 3+2):\n");
    printf("Для завершения работы программы нажмите Ctrl+C.\n");

    while (1) {
        printf("Операция: ");
        if (fgets(operation, sizeof(operation), stdin) == NULL) {
            break;
        }

        if (sscanf(operation, " %1d %1c %1d", &operand1, &operator, &operand2) != 3) {
            printf("Некорректный ввод. Попробуйте снова.\n");
            continue;
        }

        switch (operator) {
            case '+':
                result = operand1 + operand2;
                printf("Результат: %d\n", result);
                break;
            case '-':
                result = operand1 - operand2;
                printf("Результат: %d\n", result);
                break;
            case '*':
                result = operand1 * operand2;
                printf("Результат: %d\n", result);
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Ошибка: деление на ноль\n");
                } else {
                    result = operand1 / operand2;
                    printf("Результат: %d\n", result);
                }
                break;
            default:
                printf("Некорректный оператор. Попробуйте снова.\n");
                break;
        }
    }

    return 0;
}
