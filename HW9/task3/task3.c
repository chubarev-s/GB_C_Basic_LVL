// Задача 3. Числа в массив
// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.
// Данные на входе: Строка из английских букв, цифр и знаков
// препинания
// Данные на выходе: Последовательность целых чисел
// отсортированная по возрастанию
// Пример
// Данные на входе: data 48 call 9 read13 blank0a
// Данные на выходе: 0 9 13 48


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1001

// Функция для сравнения для qsort
int int_compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() 
{
    const char *inputFileName = "task3_in.txt";
    const char *outputFileName = "task3_out.txt";
    char line[MAX_LEN];
    int numbers[MAX_LEN];
    int numberCount = 0;
    FILE *inputFile = fopen(inputFileName, "r");
    
    fgets(line, MAX_LEN, inputFile);
    fclose(inputFile);
    
    char *ptr = line;
    
    while (*ptr) {
        if (isdigit(*ptr)) 
        {   // Проверка на цифру
            // Преобразование последовательности цифр в число
            int num = strtol(ptr, &ptr, 10);
            numbers[numberCount++] = num;
        } else {
            // Перемещение указателя, если символ не является цифрой
            ptr++;
        }
    }
    
    qsort(numbers, numberCount, sizeof(int), int_compare);

    FILE *outputFile = fopen(outputFileName, "w");
    for (int i = 0; i < numberCount; i++) {
        fprintf(outputFile, "%d ", numbers[i]);
    }
    fclose(outputFile);

}