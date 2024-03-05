/*
Задача 5*. Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность.
Данные на входе: На вход подается строка состоящая из символов '(', ')'
и заканчивающаяся символом '.'. Размер строки не более 1000 символов.
Данные на выходе: Необходимо напечатать слово YES если скобки
расставлены верно и NO в противном случае.
Пример №1
Данные на входе: (()()).
Данные на выходе: YES
Пример №2
Данные на входе: ()(.
Данные на выходе: NO
*/
#include <stdio.h>

int check_brackets(char brackets[])
{
    int count_left_brackets = 0, count_right_brackets = 0;
    int size = 1000;
    while (size > 0)
    {
        if (brackets[size-1] == ')')
            count_right_brackets ++;
        else
            {
                if (brackets[size-1] == '(')
                        count_left_brackets++;
            }
        size--;
    }
    return count_left_brackets==count_right_brackets?1:0;
}

int main()
{
    char string_brackets[1000];
    int check_string = 0;
    printf("Введите строку содержащую скобки (): ");
    scanf("%s", &string_brackets);
    /*while( (string_brackets = getchar()) != '.') //думаю через getchar нужно ограничение по "." ставить, но не получилось как-то 
        putchar(string_brackets);*/
    check_string = check_brackets(string_brackets);
    if (check_string == 1)
        printf("Yes");
    else
        printf("No");
}