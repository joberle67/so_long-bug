#include "../header/so_long.h"

char	**init_tab(int fd)
{
	int		a;
	char	**str;

	str = malloc(sizeof(char *) * (100));
	a = -1;
	while (1)
	{
		str[++a] = get_next_line(fd);
		if (str[a] == NULL)
			break ;
	}
	return (str);
}

void	init_value(t_game *game)
{
	game->map.coin.x = 0;
	game->map.coin.y = 0;
	game->map.exit.x = 0;
	game->map.exit.y = 0;
	game->map.wall.x = 0;
	game->map.wall.y = 0;
	game->map.floor.x = 0;
	game->map.floor.y = 0;
}

void	init_game(t_game *game, char *av)
{
	game->path = av;
	game->map.fd = open(game->path, O_RDONLY);
	game->map.tab = init_tab(game->map.fd);
	init_value(game);
	game->player.move = 0;
	find_item(game->map.tab, game);
	error_game(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.x * 80, game->map.y * 80, "so_long");

}