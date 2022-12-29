#include <stdio.h>
int main()
{
    double first_number, second_number, product;
    printf("Введите два числа: ");

    // Читаем 2 вещественных числа функцией scanf()
    scanf("%lf %lf", &first_number, &second_number);

    // Результат умножения сохраняем в переменную product
    product = first_number * second_number;

    // Выводим результат, после запятой 2 знака, формат %.2lf
    printf("Product = %.2lf\n", product);

    return 0;
}

