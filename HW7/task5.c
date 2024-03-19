/*
Задача 5. Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у
которых вторая с конца цифра (число десятков) – ноль.
Данные на входе: 10 целых чисел через пробел.
Данные на выходе: Целые числа через пробел, у которых вторая с конца
цифра - ноль
Пример
Данные на входе: 40 105 203 1 14 1000 22 33 44 55
Данные на выходе: 105 203 1 1000
*/

#include <stdio.h>

int main()
{
    int arr[10], arr_rez[10], arr_result[10], count = 0;

    printf("Введите элементы массива через пробел: \n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        arr_rez[i] = arr[i]/10; 
    }
    for(int i = 0; i < 10; i++)
    {
        if((arr_rez[i]%10) == 0)
        {
            arr_result[count] = arr[i];
            count++;
        }
    }
    for(int i = 0; i < count; i++)
    {
         printf("%d ", arr_result[i]);
    }
}