/*
** EPITECH PROJECT, 2019
** my comp
** File description:
** comp
*/

#include <unistd.h>
#include "../include/my.h"

int my_put_nbr(int nb)
{
    if (nb > 9)
        my_put_nbr(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
