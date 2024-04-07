/*
Задача 6. Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000
символов.
Данные на выходе: Одно целое число
Пример
Данные на входе: Mama mila ramu
Данные на выходе: 2
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    const char *inputFileName = "task6_in.txt";
    const char *outputFileName = "task6_out.txt";
    char line[MAX_LEN];
    int count = 0;

    FILE *inputFile = fopen(inputFileName, "r");

    fscanf(inputFile, "%[^\n]", line);
    
    fclose(inputFile);

    // Разбиваем предложение на слова
    char *token = strtok(line, " ");
    
    while (token != NULL) {
        // Проверяем последнюю букву слова на 'a'
        if (token[strlen(token) - 1] == 'a') {
            count++;
        }
        token = strtok(NULL, " ");
    }

    FILE *outputFile = fopen(outputFileName, "w");

    // Записываем количество слов на букву 'a' в файл
    fprintf(outputFile, "%d", count);

    fclose(outputFile);


}