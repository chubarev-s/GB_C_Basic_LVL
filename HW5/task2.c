/*
Задача 2. НОД
Составить функцию, которая определяет наибольший общий делитель двух
натуральных и привести пример ее использования

int nod(int a, int b)
Данные на входе: Два целых положительных числа
Данные на выходе: Одно целое число - наибольший общий делитель.
*/
#include <stdio.h>

int nod(int a, int b)
{
    while((a != 0)&&(b != 0))
    {
        if(a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    return (a + b);
}


int main(){
    int num1 = 0, num2 = 0;
    printf("Введите два числа через пробел: ");
    scanf("%d %d", &num1, &num2);
    printf("Наибольший общий делитель: %d", nod(num1, num2));

}