/*
Задача 1. Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe
*/

#include <stdio.h>
#include <string.h>

void swapAdjacentChars(FILE *input, FILE *output) 
{
    char ch, prevCh = ' ';
    while((ch = fgetc(input)) != EOF) 
    {
        if(ch != ' ' && prevCh != ' ') 
        {
            fputc(ch, output);
            fputc(prevCh, output);
            prevCh = ' ';
        } else {
            prevCh = ch;
        }
    }
    if(prevCh != ' ') 
    {
        fputc(prevCh, output);
    }
}

int main() 
{
    FILE *inputFile = fopen("task1_in.txt", "r");
    FILE *outputFile = fopen("task1_out.txt", "w");

    swapAdjacentChars(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

}