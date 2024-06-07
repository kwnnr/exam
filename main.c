#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <windows.h>

// Обработчик сигнала для завершения программы при нажатии Ctrl+C
void handle_sigint(int sig) {
    printf("\nПрограмма завершена.\n", sig);
    exit(0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char operation[10]; // Массив для хранения введенной операции
    int operand1, operand2, result; // Переменные для хранения операндов и результата
    char operator; // Переменная для хранения оператора

    // Установка обработчика сигнала для SIGINT (Ctrl+C)
    signal(SIGINT, handle_sigint); // При получении сигнала SIGINT вызовется функция handle_sigint

    printf("Введите арифметическую операцию с однозначными операндами (например, 3+2):\n");
    printf("Для завершения работы программы нажмите Ctrl+C.\n");

    while (1) { // Бесконечный цикл
        printf("Операция: ");
        if (fgets(operation, sizeof(operation), stdin) == NULL) { // Чтение строки из стандартного ввода
            break; // Если ввод завершен (EOF), выйти из цикла
        }

        // Считывание операндов и оператора из введенной строки
        if (sscanf(operation, " %1d %1c %1d", &operand1, &operator, &operand2) != 3) {
            printf("Некорректный ввод. Попробуйте снова.\n");
            continue; // Если ввод некорректен, запросить ввод снова
        }

        // Выполнение операции в зависимости от оператора
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
                if (operand2 == 0) { // Проверка деления на ноль
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

    return 0; // Возврат из функции main, завершение программы
}
