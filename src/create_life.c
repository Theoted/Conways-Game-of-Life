#include "life_game.h"

// Les regles

// Cell survie au tour suivant si elle est entoure de 2
// ou 3 voisines
// En dessous de 2 voisines elle meurt d'isolement
// Au dessus de 3 elle meurt de sur population

// Si une case vide est entouree par exactement 3 cellule
// elle devient vivante au tour suivant

char **dup_map(t_data data, char **map)
{
    int     i;
    char    **tmp;
    
    i = 0;
    tmp = malloc(sizeof(char *) * data.map->y_len + 1);
    while (map[i])
    {
        tmp[i] = ft_strdup(map[i]);
        i++;
    }
    tmp[i] = 0;
    return (tmp);
}

int check_create(t_data data, char **tmp, int x, int y)
{
    int cells;

    cells = 0;
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < data.map->x_len && y + 1 < data.map->y_len)
    {
        if (tmp[y - 1][x - 1] == '1')
            cells++;
        if (tmp[y - 1][x] == '1')
            cells++;
        if (tmp[y - 1][x + 1] == '1')
            cells++;
        if (tmp[y][x - 1] == '1')
            cells++;
        if (tmp[y][x + 1] == '1')
            cells++;
        if (tmp[y + 1][x - 1] == '1')
            cells++;
        if (tmp[y + 1][x] == '1')
            cells++;
        if (tmp[y + 1][x + 1] == '1')
            cells++;
    }
    if (cells == 3)
        return (1);
    else
        return (0);
}

int check_life(t_data data, char **tmp, int x, int y)
{
    int cells;

    cells = 0;
    if (x - 1 > 0 && y - 1 > 0 && x + 1 < data.map->x_len && y + 1 < data.map->y_len)
    {
        if (tmp[y - 1][x - 1] == '1')
            cells++;
        if (tmp[y - 1][x] == '1')
            cells++;
        if (tmp[y - 1][x + 1] == '1')
            cells++;
        if (tmp[y][x - 1] == '1')
            cells++;
        if (tmp[y][x + 1] == '1')
            cells++;
        if (tmp[y + 1][x - 1] == '1')
            cells++;
        if (tmp[y + 1][x] == '1')
            cells++;
        if (tmp[y + 1][x + 1] == '1')
            cells++;
    }
    if (cells == 2 || cells == 3)
        return (1);
    else
        return (0);
}

void create_life(t_data *data)
{
    int     x;
    int     y;
    int     i;
    char    **tmp;

    y = 0;
    i = 0;
    tmp = dup_map(*data, data->map->matrix);
    while (y < data->map->y_len - 1)
    {
        x = 0;
        while (x < data->map->x_len - 1)
        {
            if (data->map->matrix[y][x] == '0')
            {
                if (check_create(*data, tmp, x, y))
                    data->map->matrix[y][x] = '1';
            }
            else if (data->map->matrix[y][x] == '1')
            {
                if (!check_life(*data, tmp, x, y))
                    data->map->matrix[y][x] = '0';
            }
            x++;
        }
        y++;
        i++;
    }
    mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
    draw_map(*data);
}
