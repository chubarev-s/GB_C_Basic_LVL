/*
Задача 4. Удалить повторяющиеся символы
В файле .txt строка из маленьких и больших английских букв, знаков
препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
все пробелы. Результат записать в файл .txt.
Данные на входе: Строка из маленьких и больших английских букв,
знаков препинания и пробелов. Размер строки не более 1000 символов.
Данные на выходе: Строка из маленьких и больших английских
букв.
Пример
Данные на входе: abc cde def
Данные на выходе: abcdef
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define CHARSET_SIZE 256 // количество различных символов в расширенной ASCII таблице

int main() {
    const char *inputFileName = "task4_in.txt";
    const char *outputFileName = "task4_out.txt";
    bool seen[CHARSET_SIZE] = {false}; // массив для отслеживания встреченных символов
    int ch;

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    while ((ch = fgetc(inputFile)) != EOF) 
    {
        // Если символ - это пробел, пропускаем его
        if (ch == ' ') 
        {
            continue;
        }

        // Проверяем, встречался ли символ ранее
        if (!seen[ch]) 
        {
            fputc(ch, outputFile);  // Запись символа в выходной файл
            seen[ch] = true;    // Отметить символ как встреченный
        }
    }

    fclose(inputFile);
    fclose(outputFile);

}