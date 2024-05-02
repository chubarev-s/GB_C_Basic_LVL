/*
Необходимо реализовать консольное приложение, которое осуществляет
считывание текстового файла csv, состоящего из строк следующего формата:
YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE
dddd;mm;dd;hh;mm;temperature
dddd - год 4 цифры
mm - месяц 2 цифры
dd - день 2 цифры
hh - часы 2 цифры
mm - минуты 2 цифры
temperature - целое число от -99 до 99
temperature_small
temperature_big

Необходимо вывести статистику по каждому месяцу, с учетом исходных данных:
● среднемесячная температура
● минимальная температура в текущем месяце
● максимальная температура в текущем месяце
Также необходимо вывести статистику за год:
● среднегодовая температура
● минимальная температура
● максимальная температура

Требования к аргументам командной строки
Приложение должно обрабатывать аргументы командной строки:
минимальный набор поддерживаемых ключей:
● -h Описание функционала приложения. Список ключей, которые
обрабатывает данное приложение и их назначение
● -f <filename.csv> входной файл csv для обработки
● -m <номер месяца> если задан данный ключ, то выводится только статистика
за указанный месяц
● если нет параметров, то выдается help
*/

#include "config_hw11.h"


/*Обработка имени месяца в число*/
int get_month_number(char *month_name) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++) {
        if (strcmp(month_name, months[i]) == 0) {
            return i + 1;  // номер месяца начинается с 1
        }
    }

    return -1;  // вернуть -1 в случае если месяц не найден
}


int main() {
    int out_while = 0, num = 0;
    long long int count_line = 0;
    int max_t = 0, min_t = 0;
    float avr_t = 0.0;
    char *read_key, *read_file_name, *read_month;
    char inputString[100];    
    //char *help = "Описание доступных ключей:\n-h Описание функционала приложения. Список ключей, которые обрабатывает данное приложение и их назначение.\n-f <filename.csv> входной файл csv для обработки.\n-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц.\n-y выводит информацию за весь год.\n-e - выход из программы";
    char help[500];
    strcpy(help, "Available keys description:\n\
-h Description of the application functionality. List of keys processed by the application and their purpose.\n\
-f <filename.csv> input csv file for processing.\n\
-m <month> if this key is specified, only statistics for the specified month is output.\n\
month: January, February, March, April, May, June, July, August, September, October, November, December.\n\
-y outputs information for the entire year.\n\
-e - exit the program.\n");
    printf("Hello!\n");
    uint64_t count_date = 0;
    struct sensor Sensor_date[SIZE];
    printf("%s", help);
    while (out_while != 1)
    {
        printf("\n\nEnter a key: ");
        fgets(inputString, 100, stdin);
        // Почистим входной буфер
        int newlineIndex = strcspn(inputString, "\n");
        if (newlineIndex < strlen(inputString)) 
        {
            inputString[newlineIndex] = '\0'; 
        }

        read_key = strtok(inputString, " ");
        
        while (read_key != NULL) {
            if (strcmp(read_key, "-f") == 0)    //Проверяем ключ
            {
                read_key = strtok(NULL, " ");   //пропускаем пробел
                read_file_name = read_key;           //считываем токен в имя файла
                printf("\nOpening file: %s\n", read_file_name);
                char *inputFileName = read_file_name;
                count_line = AddInfo(Sensor_date, inputFileName);
                if(count_line != 0)
                    {
                        printf("\nIf you would like to view the contents of the selected file, enter 1, otherwise 2\n");
                        scanf("%d", &num);
                        if(num == 1)
                            print_data(Sensor_date, count_line);
                    }
            } else if(strcmp(read_key, "-m") == 0)
            {
                read_key = strtok(NULL, " ");   //пропускаем пробел
                read_month = read_key;           //считываем токен в месяц
                int month_number = get_month_number(read_month);
                if (month_number != -1) {
                    printf("\nDisplaying information for the selected month:\nSelected month - %s\n", read_month);
                    min_t = min_temperature_month(Sensor_date, month_number);
                    max_t = max_temperature_month(Sensor_date, month_number);
                    avr_t = average_monthly_temperature(Sensor_date, month_number);
                    printf("Average monthly temperature: %.2f\n", avr_t);
                    printf("Minimum temperature: %d\n", min_t);
                    printf("Maximum temperature: %d\n", max_t);
                } else {
                    printf("Incorrect month name entered.\n");
                }
                
            } else if(strcmp(read_key, "-h") == 0)
            {
                printf("%s", help);
            }  else if(strcmp(read_key, "-y") == 0)
            {
                min_t = min_temperature_year(Sensor_date);
                max_t = max_temperature_year(Sensor_date);
                avr_t = average_year_temperature(Sensor_date);
                printf("Average annual temperature: %.2f\n", avr_t);
                printf("Minimum temperature: %d\n", min_t);
                printf("Maximum temperature: %d\n", max_t);
            }else if(strcmp(read_key, "-e") == 0)
            {
                out_while = 1;
            }else {
                for (int i = 1; read_key[i]; i++) {
                    if (!isspace(read_key[i])) {
                        printf("\nIncorrect key entered!\n\n");
                        printf("%s", help);
                    }
                }
            }
            read_key = strtok(NULL, " ");
        }

        
    }
    
}
