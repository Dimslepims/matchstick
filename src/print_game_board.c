/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** printmapboard
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

int count_pipe(int line, char **map, int size)
{
    int count = 0;

    for (int i = (size * 2 - 1); i > 0; --i) {
        if (map[line][i] == '|') {
            count++;
        }
    }
    return (count);
}

void print_ia(game_t *game, int line, int matches, char **map)
{
    game->return_val = 1;
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    print_uptade_board_map(line, matches, game->size, map);
}

void ia(int size, char **map, game_t *game)
{
    srand(time(NULL));
    int line = rand() % size + 1;
    int nb = count_pipe(line, map, size);
    int matches = rand() % game->max_matches + 1;
    int count = 0; int diviseur = 0;
    while (count == 0) {
        line = rand() % size + 1;
        nb = count_pipe(line, map, size);
        matches = rand() % game->max_matches + 1;
        if (matches > nb) {
            diviseur = matches - nb;
            matches -= diviseur;
        }
        for (int i = (size * 2 - 1); i > 0; --i) {
            if (map[line][i] == '|') {
                count++;
            }
        }
    }
    print_ia(game, line, matches, map);
}

int main(int ac, char **av)
{
    if (my_getnbr(av[1]) < 2)
        return (84);
    char **map = print_map_board(my_getnbr(av[1]));
    my_putchar('\n');
    game_t *game = malloc(sizeof(game_t));
    game->size = my_getnbr(av[1]);
    game->max_matches = my_getnbr(av[2]);
    game->stop = 0;
    if (gameloop(av, game, map) == 0)
        return (0);
    if (game->return_val == 2)
        my_putstr("You lost, too bad...\n");
    else
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (game->return_val);
}
