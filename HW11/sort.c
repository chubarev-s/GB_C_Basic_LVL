#include "config_hw11.h"

// /*Сортировка по температуре*/
// void SortByT(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].temperature >= info[j].temperature)
//                 cgangeIJ(info, i, j);
// }

// /*Сортировка по дате*/
// void SortByDateUp(struct sensor* info, int n)
// {
//     SortByDateDownMinute(info, n);
//     SortByDateDownHours(info, n);
//     SortByDateDownDay(info, n);
//     SortByDateDownMonth(info, n);
//     SortByDateDownYear(info, n);
// }
// void SortByDateDown(struct sensor* info, int n)
// {
//     SortByDateDownYear(info, n);
//     SortByDateDownMonth(info, n);
//     SortByDateDownDay(info, n);
//     SortByDateDownHours(info, n);
//     SortByDateDownMinute(info, n);
    
    
    
    
// }
// void SortByDateDownMinute(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].year <= info[j].year){
//                 if(info[i].month <= info[j].month)
//                     if(info[i].day <= info[j].day)
//                         if(info[i].minute <= info[j].minute)
//                             if(info[i].minute <= info[j].minute)
//                                 cgangeIJ(info, i, j);
//             }
            
// }
// void SortByDateDownHours(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].year <= info[j].year){
//                 if(info[i].month <= info[j].month)
//                     if(info[i].day <= info[j].day)
//                         if(info[i].minute <= info[j].minute)
//                             cgangeIJ(info, i, j);
//             }
            
// }
// void SortByDateDownDay(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].year <= info[j].year){
//                 if(info[i].month <= info[j].month)
//                     if(info[i].day <= info[j].day)
//                         cgangeIJ(info, i, j);
//             }
            
// }
// void SortByDateDownMonth(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].year <= info[j].year){
//                 if(info[i].month <= info[j].month)
//                     cgangeIJ(info, i, j);
//             }
            
// }
// void SortByDateDownYear(struct sensor* info, int n)
// {
//     for(int i = 0; i < n; i++)
//         for(int j = i; j < n; j++)
//             if(info[i].year <= info[j].year){
//                 cgangeIJ(info, i, j);
//             }
            
// }

// /*Вспомогательные функции*/
// void cgangeIJ(struct sensor* info, int i, int j)
// {
//     struct sensor temp;
//     temp = info[i];
//     info[i] = info[j];
//     info[j] = temp;
// }

/*Среднемесячная температура*/
float average_monthly_temperature(struct sensor* info, int month)
{
    int out_while_amt = 0;
    long int i = 0;
    int count = 0;
    float sum = 0.0;
    while(out_while_amt < 1)
    {
        if(info[i].month == month)
            {
                sum += info[i].temperature;
                count++;
            }
        i++;
        if(i == SIZE)
        {
            out_while_amt = 1;
        }
    }
    if(count > 0)
    {
        return sum / count; 
    }
    return 0.0;
}

/*Минимальная температура в текущем месяце*/
int min_temperature_month(struct sensor* info, int month)
{
    int out_while_amt = 0;
    long int i = 0;
    int count = 0;
    int min_t = 99;

    while(out_while_amt < 1)
    {
        if(info[i].month == month)
            {
                if(info[i].temperature < min_t)
                    min_t = info[i].temperature;
            }
        i++;
        if(i == SIZE)
        {
            out_while_amt = 1;
        }
    }
    if(count > 0)
    {
        return min_t; 
    }
    return 0;
}

/*Максимальная температура в текущем месяце*/
int max_temperature_month(struct sensor* info, int month)
{
    int out_while_amt = 0;
    long int i = 0;
    int count = 0;
    int max_t = -99;

    while(out_while_amt < 1)
    {
        if(info[i].month == month)
            {
                if(info[i].temperature > max_t)
                    max_t = info[i].temperature;
            }
        i++;
        if(i == SIZE)
        {
            out_while_amt = 1;
        }
    }
    if(count > 0)
    {
        return max_t; 
    }
    return 0;
}

/*Среднегодовая температура*/
float average_year_temperature(struct sensor* info)
{
    long long int count_ayt = 0;
    int out_while_ayt = 0;
    float sum = 0.0; 
    while (out_while_ayt < 1)
    {
        sum += info[count_ayt].temperature;
        count_ayt++;
        if(count_ayt == SIZE)
            out_while_ayt = 1;
    }
    if(count_ayt > 0)
        return sum / count_ayt;
    
    return 0.0;
}

/*Минимальная температура*/
int min_temperature_year(struct sensor* info)
{
    long long int count_ayt = 0;
    int out_while_ayt = 0;
    int min_t = 99; 
    while (out_while_ayt < 1)
    {
        if(info[count_ayt].temperature < min_t)
            min_t = info[count_ayt].temperature;
        count_ayt++;
        if(count_ayt == SIZE)
            out_while_ayt = 1;
    }
    if(count_ayt > 0)
        return min_t;
    
    return 0.0;
}

/*Максимальная температура*/
int max_temperature_year(struct sensor* info)
{
    long long int count_ayt = 0;
    int out_while_ayt = 0;
    int max_t = -99; 
    while (out_while_ayt < 1)
    {
        if(info[count_ayt].temperature > max_t)
            max_t = info[count_ayt].temperature;
        count_ayt++;
        if(count_ayt == SIZE)
            out_while_ayt = 1;
    }
    if(count_ayt > 0)
        return max_t;
    
    return 0.0;
}







