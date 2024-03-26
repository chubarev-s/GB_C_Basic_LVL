/*
Задача 5. Поменять местами
Составить функцию, которая меняет в массиве минимальный и максимальный
элемент местами. Прототип функции
void change_max_min(int size, int a[])
Данные на входе: Функция принимает на вход размер массива и
массив чисел типа int
Данные на выходе: Функция не возвращает значения, измененный
массив сохраняется на месте исходного.
Пример
Данные на входе: 1 2 3 4 5 6 7 8 9 10
Данные на выходе: 10 2 3 4 5 6 7 8 9 1
*/

#include <stdio.h>

void change_max_min(int size, int a[])
{
    int max = a[0], min_id = 0;
    int min = a[0], max_id = 0;
    int swap = 0;

    for(int i = 0; i < size; i++)
    {
        if(a[i] > max)
            {
                max = a[i];
                max_id = i;
            }

    }
    for(int i = 0; i < size; i++)
    {
        if(a[i] < min)
            {
                min = a[i];
                min_id = i;
            }
    }
    swap = a[min_id];
    a[min_id] = a[max_id];
    a[max_id] = swap;
}



