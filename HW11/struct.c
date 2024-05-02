#include "config_hw11.h"
#define COUNT_PARAM 6 //кол-во параметров
int arr_minus[SIZE];


/*Заполнение структуры*/
void AddRecord(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minute, int8_t temperature)
{ 
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hours = hours;
    info[number].minute = minute;
    if(arr_minus[number] == 1)
        info[number].temperature = -temperature;
    else
        info[number].temperature = temperature;
}

/*Считывание данных из файла данных датчика*/
int AddInfo(struct sensor* info, char *inputFileName)
{
    int counter = 0, count_line = 0;
    int arr[COUNT_PARAM];
    int line = 0;
    char ch = 0;
    for(int i = 0; i < COUNT_PARAM; i++){
        arr[i] = 0;
    }
    FILE *file = fopen(inputFileName, "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    printf("Init data\n");
    /*Считываем данные из файла*/
    while((ch = fgetc(file)) != EOF)
    {
        if(ch==';')
        {
            counter++;
            if(counter > COUNT_PARAM)
            {
                counter = 0;
            }
        }
        else if(ch == '\n') //дошли до конца строки
        {
            if(counter == COUNT_PARAM - 1) //если строка была корректная и мы считали все параметры
                {
                    AddRecord(info, line, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
                    // printf("data line %d add \n", line);
                }
            
            
            counter = 0;
            
            for(int i = 0; i < COUNT_PARAM; i++){
                arr[i] = 0;
            }
            line++;
        }
        else if(ch >= '0' && ch <= '9' || ch == '-') //если поймали число
            {
                if(ch == '-')
                    {
                        arr[counter] = -arr[counter];
                        arr_minus[line] = 1;
                    }
                else
                    arr[counter] = arr[counter]*10 + ch - '0';
            }
        else if(ch != 0xD) //анализ на перевод строки в ascii
            {
                
                counter = 0;
            }
    }
    count_line = line;
    line = 0;
    printf("struct writes\n");
    fclose(file);
    return count_line;
}


/*Вывод данных*/
void print_data(struct sensor* info, int number)
{
    printf("=================================================\n");
    for(int i = 0; i < number; i++)
    {   
        if(info[i].year > 1900 && info[i].year < 2100)
            printf("%04d-%02d-%02d in %02d:%02d - t = %3d\n", info[i].year, info[i].month, info[i].day, info[i].hours, info[i].minute, info[i].temperature);
    }
}
