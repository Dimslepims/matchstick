/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

#include "struct.h"


    int my_putstr(char const *);
    int my_getnbr(char const *);
    int my_put_nbr(int);
    void my_putchar(char);
    char **print_map_board(int);
    void print_uptade_board_map(int, int, int, char **);
    int check(char **, game_t *);
    int gameloop(char **, game_t *, char **);
    void ia(int, char **, game_t *);
    int player(int, char **, game_t *);
    int count_pipe(int, char **, int);
    void check_alpha(char *, game_t *);
    int check_lines(game_t *, int, int);
    int check_matches(game_t *, int, int, int);

#endif
