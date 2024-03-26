/*
Задача 1. Сортировка по возрастанию
Написать только одну функцию, которая сортирует массив по возрастанию.
Необходимо реализовать только одну функцию, всю программу составлять не
надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть:
void sort_array(int size, int a[])
Всю программу загружать не надо, только одну эту функцию. Можно просто
закомментировать текст всей программы, кроме данной функции.
Данные на входе: Функция принимает на вход, первый аргумент - размер
массива, второй аргумент - адрес нулевого элемента.
Данные на выходе: Функция ничего не возвращает. Производит
сортировку переданного ей массива по возрастанию.
*/
#include <stdio.h>



void sort_array(int size, int a[])
{
    int min = 0;
    int swap = 0;
    for(int i = 0; i < size-1 ; i ++ ) 
    {
        for (int j = i+1; j < size; j ++)
            if( a[j] < a[min] ) 
            {
                min = j;
            }
        if( min != i ) 
        {
            swap = a[i];
            a[i] = a[min];
            a[min] = swap;
        }    
    }
}
