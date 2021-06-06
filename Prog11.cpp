// Prog11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>

#define DOSTAVKA1   6.50 // до 5 фунтов
#define DOSTAVKA2   14.00 // от 14 до 20 фунтов
#define DOSTAVKA3   0.5 // больше 20 фунтов
#define SKIDKA      0.05 // Скидка
#define SUM         100.0 // Сумма заказа $
#define ARTISHOKI   2.05 // Стоимость за фунт
#define SVEKLA      1.15 // Стоимость за фунт
#define MORKOV      1.09 // Стоимость за фунт
#define FUNT        20.0

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char n = 0;
    double funt = 0, funt1 = 0;
    double sum = 0, dostavka = 0, zatraty = 0, cost_art = 0, cost_sv = 0, cost_m = 0;
    double zatraty_art = 0, zatraty_sv = 0, zatraty_obs = 0, zatraty_m = 0, skidka = 0;
   
    while (1)
    {
        printf("Введите желаемый заказ:\na) Артишоки\nb) Свекла\nc) Морковь\nq) Выход\n");
        scanf_s("%c", &n, sizeof(n));

        if (n == 'q')
            break;

        switch (n)
        {
        case 'a':
            printf("Введите желаемый вес.\n");
            scanf_s("%lf", &funt1);        

            zatraty = ARTISHOKI * funt1;
            cost_art = ARTISHOKI;
            funt = funt + funt1;
            zatraty_art = zatraty_art + zatraty;

            while (getchar() != '\n')
                continue;
            break;
        zatraty = 0;

        case 'b':
            printf("Введите желаемый вес.\n");
            scanf_s("%lf", &funt1);
       
            zatraty = SVEKLA * funt1;
            cost_sv = SVEKLA;
            funt = funt + funt1;
            zatraty_sv = zatraty_sv + zatraty;
   
            while (getchar() != '\n')
                continue;
            break;

        case 'c':
            printf("Введите желаемый вес.\n");
            scanf_s("%lf", &funt1);

            zatraty = MORKOV * funt1;
            cost_m = MORKOV;
            funt = funt + funt1;
            zatraty_m = zatraty_m + zatraty;

            while (getchar() != '\n')
                continue;
            break;
        default:
            while (getchar() != '\n')
                continue;
            printf("Вы ввели неверные данные. Доступно a-c\n");
        }
        zatraty_obs = zatraty_sv + zatraty_art + zatraty_m;
       
        if (funt <= 5)
        {
            dostavka = DOSTAVKA1;
            sum = dostavka + zatraty_obs;
        }
        else if (funt > 5 && funt <= 20)
        {
            dostavka = DOSTAVKA2;
            sum = dostavka + zatraty_obs;
        }
        else 
        {
            dostavka = (funt * DOSTAVKA3) + (DOSTAVKA2 * FUNT) - 10;
            sum = zatraty_obs + dostavka;
            if (sum >= SUM)
            {
                skidka = SKIDKA * sum;
                sum = sum - skidka;

            }
        } 
    }
        printf("За %.lf фунтов заказа следующий расчет:\nКоличество фунтов %1.2f\n", funt, funt);
        if (cost_art)
        {
            printf("Стоимость фунта артишоков $%1.2f\n", cost_art);
            printf("Стоимость заказа артишоков $%1.2f\n", zatraty_art);
        }
        else if (cost_sv)
        {
            printf("Стоимость фунта свеклы $%1.2f\n", cost_sv);
            printf("Стоимость заказа свеклы $%1.2f\n", zatraty_sv);
        }
        else
        {
            printf("Стоимость фунта моркови $%1.2f\n", cost_m);
            printf("Стоимость заказа моркови $%1.2f\n", zatraty_m);
        }
            printf("Общая стоимость заказа $%1.2f\n\
Скидка $%1.2f\nДоставка $%1.2f\nСумма заказа $%1.2f\n", zatraty_obs, skidka, dostavka, sum);
   
    return 0;
}