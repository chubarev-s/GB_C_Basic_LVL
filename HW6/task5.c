/*
Задача 5. Сколько раз встречается символ a
Дана строка из английских символов, пробелов и знаков препинания. В конце
строки символ точка. Необходимо реализовать рекурсивную функцию,
которая считывает данную строку со стандартного потока ввода и возвращает
целое число – количество символов 'a' в данной строке.
int acounter(void)
Используя данную функцию решить задачу.
Данные на входе: Строка состоящая из английских букв, пробелов и
знаков препинания. В конце строки символ '.'
Данные на выходе: Одно целое число.
Пример №1
Данные на входе: abcd a.
Данные на выходе: 2
Пример №2
Данные на входе: Hello world.
Данные на выходе: 0
*/

#include <stdio.h>

int count = 0;
char input_char;
int acounter(void)
{   
        input_char = getchar();
        if (input_char == 'a')
            count++;            
        if (input_char == '.')
            return count;
        count = acounter();
    
}

int main()
{
    int res = 0;
    printf("Введите строку: ");
    printf("%d", res = acounter());

}

