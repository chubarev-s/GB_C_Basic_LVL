/*
Задача 5. Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
несколько, не обрабатывать.
Данные на входе: Строка из английских букв и пробелов. Не более
1000 символов.
Данные на выходе: Одно слово из английских букв.
Пример
Данные на входе: Hello beautiful world
Данные на выходе: beautiful
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *inputFilename = "task5_in.txt";
    const char *outputFilename = "task5_out.txt";
    
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    
    char word[256]; // предполагаем, что слово не превышает 255 символов
    char longestWord[256] = ""; // здесь будет храниться самое длинное слово
    
    while (fscanf(inputFile, "%255s", word) == 1) 
    { 
        if (strlen(word) > strlen(longestWord)) 
        { 
            strcpy(longestWord, word); 
        }
    }

    fprintf(outputFile, "%s", longestWord); 
    
    fclose(inputFile);
    fclose(outputFile);
    
}