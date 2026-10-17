#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Точка входа в программу.
 *
 * Разбирает аргументы командной строки и ожидает параметр `-p`,
 * задающий количество процессов. Проверяет корректность переданного
 * значения и выводит его на стандартный поток вывода.
 *
 * @param argc Количество аргументов командной строки.
 * @param argv Массив строк аргументов командной строки.
 *
 * @return 0 при успешном завершении, 1 в случае ошибки
 *         (неверные аргументы или количество процессов <= 1).
 */
int main(int argc, char *argv[]) {
    int x = -1;

    int opt;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                x = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -p X\n", argv[0]);
                return 1;
        }
    }

    if (x <= 1) {
        fprintf(stderr, "Usage: %s -p X\n", argv[0]);
        return 1;
    }

    printf("Количество процессов: %d\n", x);
    return 0;
}
