/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** gameloop
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

int check(char **map, game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->size + 2; ++i) {
        for (int j = 0; j < (game->size * 2 + 1); ++j) {
            if (map[i][j] == '|')
                ++count;
        }
    }
    if (count == 0)
        return (1);
    return (0);
}

int gameloop(char **av, game_t *game, char **map)
{
    while (1) {
        my_putstr("Your turn:\n");
        if (player(my_getnbr(av[1]), map, game) == 0)
            return (0);
        if (check(map, game) == 1)
            break;
        my_putchar('\n');
        my_putstr("AI's turn...\n");
        ia(my_getnbr(av[1]), map, game);
        if (check(map, game) == 1)
            break;
        my_putchar('\n');
    }
}