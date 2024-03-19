/*
Задача 3. Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4
элемента.
Данные на входе: 12 целых чисел через пробел
Данные на выходе: 12 целых чисел через пробел
Пример №1
Данные на входе: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
Пример №2
Данные на входе: 1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8
*/
#include <stdio.h>

int main()
{
    int arr[12], arr_rez[4];
    int count = 0;

    printf("Введите элементы массива через пробел: \n");
    for(int i = 0; i < 12; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 8; i < 12; i++)
    {
        arr_rez[count] = arr[i];
        count++;
    }
    for(int i = 11; i >= 0; i--)
    {
        arr[i] = arr[i-4];
    }
    for(int i = 0; i < 4; i++)
    {
        arr[i] = arr_rez[i];
    }
    for(int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }
}