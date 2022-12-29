#include <stdio.h>
int main()
{
    int first_number, second_number, sum;
    
    printf("Введите два целых числа: ");

    // Читаем 2 целых числа функцией scanf()
    scanf("%d %d", &first_number, &second_number);

    // Вычисляем сумму двух чисел
    sum = first_number + second_number;

    // Отображаем сумму
    printf("%d + %d = %d\n", first_number, second_number, sum);

    return 0;
}

