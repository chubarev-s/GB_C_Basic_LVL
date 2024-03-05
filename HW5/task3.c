/*
Задача 3. Сумма цифр равна произведению
Составить логическую функцию, которая определяет, верно ли, что в заданном
числе сумма цифр равна произведению.
int is_happy_number(int n)
Данные на входе: Целое не отрицательное число
Данные на выходе: YES или NO
*/
#include <stdio.h>

int is_happy_number(int n)
{
    int count = 0, sum = 0, mult = 1;
    int n_2 = 0;
    n_2 = n;
    while(n > 0)
    {
        n /= 10;
        count++;
    }
    int arr[count];
    for(int i = 0; i < count; i++)
    {
        arr[i] = 0;
    }
    for(int i = 0; i < count; i++)
    {
        arr[i] = n_2 % 10;
        n_2 /= 10;
    }
    for(int i = 0; i < count; i++)
    {
        sum += arr[i];
        mult *= arr[i];
    }
    return sum==mult?1:0;  
}
int main()
{
    int num = 0, happy = 0;
    printf("Введите число: ");
    scanf("%d", &num);
    happy = is_happy_number(num);
    if (happy == 1)
        printf("Число %d - счастливое!", num);
    else
        printf("Число %d - обычное", num);
}