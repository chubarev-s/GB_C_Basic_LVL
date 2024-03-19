// Задача 4. Отсортировать по последней цифре
// Считать массив из 10 элементов и отсортировать его по последней цифре.
// Данные на входе: 10 целых чисел через пробел
// Этот же массив отсортированный по последней цифре
// Пример №1
// Данные на входе: 14 25 13 30 76 58 32 11 41 97
// Данные на выходе: 30 11 41 32 13 14 25 76 97 58
// Пример №2
// Данные на входе: 109 118 100 51 62 73 1007 16 4 555
// Данные на выходе: 100 51 62 73 4 555 16 1007 118 109
#include <stdio.h>

int main()
{
    int arr[10], arr_sort[10];
    int last_num = 10, min_num = 0;

    printf("Введите элементы массива через пробел: \n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    min_num = 9;
    printf("%d \n", min_num);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {

            if (j != last_num)
            {
                if((arr[j]%10) < (min_num%10))
                {
                    min_num = arr[j];
                    last_num = j;
                }
            }
        }
        //printf("%d ", min_num);
        arr_sort[i] = min_num;
        //last_num = min_num%10;
        min_num = 9;

        //printf(" last num = %d", last_num);
    }
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr_sort[i]);
    }

}


/*
if((arr[j]%10) == last_num)
            {
                count++;
            }
            else
                if((arr[j]%10) < min_num)
                {
                    min_num = arr[j];
                }
            if (count > 1)
            {
                min_num = arr[j];
            }
            
        }
        printf("%d ", min_num);
        arr_sort[i] = min_num;
        
        last_num = min_num%10;
*/