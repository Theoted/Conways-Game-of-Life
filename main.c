#include "life_game.h"

int render_next_frame(void *arg)
{
    int     i;
    char    *steps;
    t_data *data;

    data = arg;
    i = 0;
    steps = ft_itoa(data->steps);
    create_life(data);
    mlx_string_put(data->mlx->mlx_ptr, data->mlx->mlx_win, 10, 20, 0xFF0000, steps);
    data->steps++;
    usleep(data->speed * 1000);
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    t_data  data;
    t_mlx   mlx;
    t_map   map;

    data.map = &map;
    data.speed = ft_atoi(av[2]);
    data.steps = 1;
    get_map(&data, av[1]);
    mlx.mlx_ptr = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 
        (data.map->x_len * 10), (data.map->y_len * 10),
        "Life Game!");
    data.mlx = &mlx;
    draw_map(data);
    usleep(data.speed * 1000);
    mlx_loop_hook(data.mlx->mlx_ptr, render_next_frame, &data);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}