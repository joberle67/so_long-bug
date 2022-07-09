#include "../header/so_long.h"

char **init_tab(int fd)
{
	int a;
	char **str;

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

void	init_game(t_game *game, char *av)
{

	game->path = av;
	game->map.fd = open(game->path, O_RDONLY);
	game->player.move = 0;
	find_item(game->map.tab, game);
	game->map.tab = init_tab(game->map.fd);
	error_game(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
}