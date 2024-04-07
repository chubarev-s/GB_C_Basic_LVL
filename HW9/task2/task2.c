// Задача 2. Заменить a на b
// В файле .txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в .txt.
// Данные на входе: Строка из маленьких и больших английских букв,
// знаков препинания и пробелов.
// Данные на выходе: Строка из маленьких и больших английских
// букв, знаков препинания и пробелов.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    const char *inputFileName = "task2_in.txt";
    const char *outputFileName = "task2_out.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

   
    char word[1001];
    
    fscanf(inputFile, "%1000s", word);
    
    for(int i = 0; word[i] != '\0'; i++)
    {
        switch(word[i])
        { 
            case 'a':
                word[i] = 'b';
                break;
        
            case 'b':
                word[i] = 'a';
                break;
        
            case 'A':
                word[i] = 'B';
                break;
        
            case 'B':
                word[i] = 'A';
                break;
        }
        fprintf(outputFile, "%c", word[i]);
    }
    
    
    fclose(inputFile);
    fclose(outputFile);

}