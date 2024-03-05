/*
Задача 4. Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и
привести пример ее использования.
Пример №1
Данные на входе: Одно целое положительное число N
Данные на выходе: Целое число - сумма чисел от 1 до N
*/

#include <stdio.h>

void out_sum(int n)
{
    int count_num = 0;
    for(int i = 1; i <= n; i++)
    {
        count_num += i;
    }
    printf("Сумма чисел от 1 до %d = %d", n, count_num);
}

int main()
{
    int num = 0;
    printf("Введите число N: ");
    scanf("%d", &num);
    out_sum(num);
}

