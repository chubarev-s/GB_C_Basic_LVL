/*
Задача 2. Найти минимум
Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
Данные на входе: 5 целых чисел через пробел
Данные на выходе: Одно единственное целое число
Пример №1
Данные на входе: 4 15 3 10 14
Данные на выходе: 3
Пример №2
Данные на входе: 1 2 3 4 -5
Данные на выходе: -5
*/
#include <stdio.h>

int main()
{
    int arr[5];
    int min = 0;
    printf("Введите элементы массива через пробел: \n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for(int i = 1; i < 5; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    printf("Минимальное значение элемента в массиве: %d", min);

}


