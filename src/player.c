/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** player
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

int get_input(game_t *game)
{
    char *b = NULL;
    int nb = 0;
    size_t bufsize = 32;
    size_t characters;

    characters = getline(&b, &bufsize, stdin);
    if (characters == -1)
        game->control = 1;
    check_alpha(b, game);
    nb = my_getnbr(b);
    return (nb);
}

void print_player(game_t *game, int line, int matches, char **map)
{
    game->return_val = 2;
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    print_uptade_board_map(line, matches, game->size, map);
}

int player(int size, char **map, game_t *game)
{
    int check = 0; int line = 0; int matches = 0; int nb = 0;
    while (check == 0) {
        my_putstr("Line: "); line = get_input(game);
        if (game->control == 1)
            return (0);
        if (check_lines(game, size, line) == 1)
            continue;
        my_putstr("Matches: "); matches = get_input(game);
        if (game->control == 1)
            return (0);
        nb = count_pipe(line, map, size);
        if (check_matches(game, size, matches, nb) == 1)
            continue;
        if (matches <= 0) {
            my_putstr("Error: you have to remove at least one match\n");
            continue;
        } else
            check = 1;
    }
    print_player(game, line, matches, map);
}
