#include "life_game.h"

void    draw_cell(t_data data, int x, int y)
{
    int xx;
    int yy;

    yy = 0;
    while (yy < 10)
    {
        xx = 0;
        while (xx < 10)
        {
            mlx_pixel_put(data.mlx->mlx_ptr, data.mlx->mlx_win,
                x + xx, y + yy, 0xFFFFFF);
            xx++;
        }
        yy++;
    }
}

void    draw_map(t_data data)
{
    int x;
    int y;

    y = 0;
    while (y < data.map->y_len)
    {
        x = 0;
        while (x < data.map->x_len)
        {
            if (data.map->matrix[y][x] == '1')
                draw_cell(data, (x * 10), (y * 10));
            x++;
        }
        y++;
    }
}