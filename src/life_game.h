#ifndef LIFE_GAME_H
# define LIFE_GAME_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *mlx_win;
}   t_mlx;

typedef struct s_map
{
    int     x_len;
    int     y_len;
    char    **matrix;
}   t_map;


typedef struct s_data
{
    int     speed;
    int     steps;
    t_mlx   *mlx;
    t_map   *map;
}   t_data;

// Parsing

int     get_map(t_data *data, char *map);
int     get_x(char *map);
int     get_y(char *map);

// Draw map

void    draw_cell(t_data data, int x, int y);
void    draw_map(t_data data);

// Create Life

void    create_life(t_data *data);
int     check_life(t_data data, char **tmp, int x, int y);
int     check_create(t_data data, char **tmp, int x, int y);

#endif