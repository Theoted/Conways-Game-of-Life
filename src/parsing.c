#include "life_game.h"

int get_y(char *map)
{
    int     fd;
    int     r;
    int     y;
    char    buffer[1];

    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Open Error\n", 12);
        exit(1);
    }
    r = read(fd, buffer, 1);
    if (r < 0)
    {
        write(2, "Read Error\n", 12);
        exit(1);
    }
    y = 0;
    while (r)
    {
        if (buffer[0] == '\n')
            y++;
        r = read(fd, buffer, 1);
    }
    close(fd);
    return (y);
}

int get_x(char *map)
{
    int     fd;
    int     r;
    int     x;
    char    buffer[1];

    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Open Error\n", 12);
        exit(1);
    }
    r = read(fd, buffer, 1);
    if (r < 0)
    {
        write(2, "Read Error\n", 12);
        exit(1);
    }
    x = 0;
    while (buffer[0] != '\n' && r)
    {
        r = read(fd, buffer, 1);
        x++;
    }
    close(fd);
    return (x);
}

int get_map(t_data *data, char *map)
{
    int     i;
    int     fd;
    char    *tmp;

    data->map->x_len = get_x(map);
    data->map->y_len = get_y(map);
    data->map->matrix = malloc(sizeof(char *) * (data->map->y_len + 1));
    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Open Error\n", 12);
        exit(1);
    }
    i = 0;
    while (i < data->map->y_len)
    {
        tmp = get_next_line(fd);
        data->map->matrix[i] = ft_strtrim(tmp, "\n");
        free(tmp);
        i++;
    }
    data->map->matrix[i] = 0;
    close(fd);
    return (0);
}