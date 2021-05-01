/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** check functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void check_alpha(char *b, game_t *game)
{
    for (int i = 0; b[i]; ++i) {
        if ((b[i] > '`') && (b[i] < '{'))
            game->alpha = 1;
    }
}

int check_lines(game_t *game, int size, int line)
{
    if (game->alpha == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        game->alpha = 0;
        return (1);
    }
    if (line <= 0 || line > size) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    else
        return (0);
}

int check_matches(game_t *game, int size, int matches, int nb)
{
    if (game->alpha == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        game->alpha = 0;
        return (1);
    }
    if (matches > game->max_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_matches);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (matches > nb) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    if (matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}