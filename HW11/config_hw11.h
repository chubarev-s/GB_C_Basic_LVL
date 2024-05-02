#ifndef __CONFIG_HW11
#define __CONFIG_HW11

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
// #include <unistd.h> //для теста

#define SIZE 365
/*Структура информации с датчика*/
struct sensor {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minute;
    int8_t temperature;
};

//Функции:
void SortByT(struct sensor* info, int n);
void SortByDateUp(struct sensor* info, int n);
void SortByDateDown(struct sensor* info, int n);
int AddInfo(struct sensor* info, char *inputFileName);
void print_data(struct sensor* info, int number);
float average_monthly_temperature(struct sensor* info, int month);
int max_temperature_month(struct sensor* info, int month);
int min_temperature_month(struct sensor* info, int month);
float average_year_temperature(struct sensor* info);
int min_temperature_year(struct sensor* info);
int max_temperature_year(struct sensor* info);
extern int arr_minus[SIZE];

#endif //end __CONFIG_HW11