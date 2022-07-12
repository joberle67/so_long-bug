#include "../header/so_long.h"

void    load_img(t_game *game)
{
    game->x = 80;
    game->y = 80;
    game->player.img.img = mlx_xpm_file_to_image(game->mlx, PLAYER, 
        &game->x, &game->y);
    game->map.floor.img = mlx_xpm_file_to_image(game->mlx, FLOOR, 
       &game->x, &game->y);
     game->map.exit.img = mlx_xpm_file_to_image(game->mlx, EXIT, 
       &game->x, &game->y);
    game->map.coin.img = mlx_xpm_file_to_image(game->mlx, ITEM, 
       &game->x, &game->y);
    game->map.wall.img = mlx_xpm_file_to_image(game->mlx, WALL, 
       &game->x, &game->y);
    game->map.die.img = mlx_xpm_file_to_image(game->mlx, DIE, 
       &game->x, &game->y);
}

void    print_floor(t_game *game)
{
    int nb;
    int y;

    nb = 0;
    y = 0;

    while (y < game->map.y)
    {
        while (nb < game->map.x)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->map.floor.img, 
                game->map.floor.x,  game->map.floor.y);
            game->map.floor.x += 80;
            nb++;
        }
        game->map.floor.x = 0;
        game->map.floor.y += 80;
        y++;
        nb = 0;
    }
     game->map.floor.x = 0;
    game->map.floor.y = 0;
}

void    print_player(t_game *game)
{
    find_player(game);
    mlx_put_image_to_window(game->mlx, game->win, game->player.img.img, 
                game->player.x * 80,  game->player.y * 80);
}

void    print_wall(t_game *game)
{
    int i;
    int a;

    a = 0;
    i = 0;

    while (game->map.tab[a])
    {
        while(game->map.tab[a][i])
        {
            if (game->map.tab[a][i] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->map.wall.img, 
                i * 80,  a * 80);
            else if(game->map.tab[a][i] == 'E')
                 mlx_put_image_to_window(game->mlx, game->win, game->map.exit.img, 
                i * 80,  a * 80);
            else if (game->map.tab[a][i] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->map.coin.img, 
                    i * 80,  a * 80);
            else if (game->map.tab[a][i] == 'D')
                mlx_put_image_to_window(game->mlx, game->win, game->map.die.img, 
                    i * 80,  a * 80);
            i++;
        }
        a++;
        i = 0;
    }
}

int    print_img(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    print_floor(game);
    print_wall(game);
    print_player(game);
    mlx_string_put(game->mlx, game->win, 10, 10, 255255255 , ft2_itoa(game->player.move));
    return (0);
}