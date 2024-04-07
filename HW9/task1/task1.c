/*
Задача 1. По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные
одним пробелом. Найдите только те символы слов, которые встречаются в
обоих словах только один раз. Напечатайте их через пробел в файл .txt в
лексикографическом порядке.
Данные на входе: Два слова из маленьких английских букв через
пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе: Маленькие английские буквы через пробел.
Пример №1
Данные на входе: hello world
Данные на выходе: o
Данные на входе: aabcd bcef
Данные на выходе: b c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    const char *inputFileName = "task1_in.txt";
    const char *outputFileName = "task1_out.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

   
    char word1[101];
    char word2[101];

    fscanf(inputFile, "%100s %100s", word1, word2);
  

    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; word1[i] != '\0'; i++) 
    {
        count1[(unsigned char)word1[i]]++;
    }
    for (int i = 0; word2[i] != '\0'; i++) 
    {
        count2[(unsigned char)word2[i]]++;
    }

    for (int i = 0; i < 256; i++) 
    {
        if (count1[i] == 1 && count2[i] == 1) 
        {
            fprintf(outputFile, "%c ", i);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}