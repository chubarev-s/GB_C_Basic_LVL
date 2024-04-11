/*
Задача 3. Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.html
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *file = fopen("task3_in.txt", "r"); 

    char address[100];
    fgets(address, 100, file); // Считываем адрес файла из файла input.txt
    fclose(file); 

    char new_address[100];
    strcpy(new_address, address); // Копируем адрес в новую строку

    char *dot_extension = strrchr(new_address, '.'); // Находим последнее вхождение точки - расширения файла
    char *dot_path = strrchr(new_address, '/'); // Находим последнее вхождение слэша - разделителя пути

    if (dot_extension != NULL && (dot_path == NULL || dot_path < dot_extension)) // Проверяем, что точка является частью расширения и не частью пути
    { 
        *dot_extension = '\0'; // Убираем расширение файла, обрезая строку
    }
   
    FILE *output_file = fopen("task3_out.txt", "w"); // Открываем файл для записи
    fputs(new_address, output_file); // Записываем измененный адрес в файл output.txt
    fputs(".html", output_file); // Если точка часть пути, добавляем расширение .html к адресу
    fclose(output_file); // Закрываем файл

    return 0; // Возвращаем 0 в качестве успешного завершения
}

