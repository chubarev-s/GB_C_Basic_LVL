/*
Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: Hello world!
Данные на выходе: Hello world!
*/
#include <stdio.h>
#include <string.h>

void removeExtraSpaces(FILE *input, FILE *output) 
{
    char ch, prevCh = ' ';
    while((ch = fgetc(input)) != EOF) 
    {
        if(ch != ' ' || (ch == ' ' && prevCh != ' ')) 
        {
            fputc(ch, output);
        }
        prevCh = ch;
    }
}

int main() 
{
    FILE *inputFile = fopen("task2_in.txt", "r");
    FILE *outputFile = fopen("task2_out.txt", "w");

    removeExtraSpaces(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}