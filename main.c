#include "life_game.h"

int render_next_frame(void *arg)
{
    int     i;
    t_data *data;

    data = arg;
    i = 0;
    create_life(data);
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