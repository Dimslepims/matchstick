/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print map
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

char **fill_tab(int size, int spaces, int nb_al, char **map)
{
    int i = 1;

    for (int j = 1; j < size + 1; ++j) {
        map[j][0] = '*';
        for (int m = 0; m < spaces; ++m, ++i)
            map[j][i] = ' ';
        for (int m = 0; m < nb_al; ++m, ++i)
            map[j][i] = '|';
        for (int m = 0; m < spaces; ++m, ++i)
            map[j][i] = ' ';
        map[j][i] = '*';
        nb_al += 2;
        spaces -= 1;
        i = 1;
    }
    return (map);
}

char **print_map_board(int size)
{
    int nb_al = 1;
    int spaces = size - 1;
    char **map = malloc(sizeof(char *) * (size + 5));
    int i = 1;
    for (int i = 0; i < size + 2; ++i) {
        map[i] = malloc(sizeof(char) * (size * 2 + 2));
    }
    for (int i = 0; i < (size * 2 + 1); ++i) {
        map[0][i] = '*';
    }
    map = fill_tab(size, spaces, nb_al, map);
    for (int i = 0; i < (size * 2 + 1); ++i) {
        map[size + 1][i] = '*';
    }
    for (int i = 0; i < size + 2; ++i) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (map);
}

void print_uptade_board_map(int line, int nb_matches, int size, char **map)
{
    for (int i = (size * 2 - 1); i > 0; --i) {
        if (map[line][i] == '|') {
            for (int j = nb_matches; j > 0; --j, --i)
                map[line][i] = ' ';
            break;
        }
    }
    for (int m = 0; m < size + 2; ++m) {
        my_putstr(map[m]);
        my_putchar('\n');
    }
}