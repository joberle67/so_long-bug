#include "../header/so_long.h"

void move_up(t_game *game)
{
	find_player(game);

	if (game->map.tab[game->player.y][game->player.x] == 'P')
		if (game->map.tab[game->player.y - 1][game->player.x] != '1')
		{
			if (game->map.tab[game->player.y - 1][game->player.x] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y - 1][game->player.x] == 'E' && game->player.item == 0)
				exit(0);
			if (game->map.tab[game->player.y - 1][game->player.x] == 'E' && game->player.item != 0)
				return ;
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y - 1][game->player.x] = 'P';
			game->player.move++;
		}
		int a = 0;
	while(game->map.tab[a])
	{
		ft_printf("%s", game->map.tab[a]);
		a++;
	}
	ft_printf("\nnombre de deplacement : %d\n", game->player.move);
	return ;
}

void move_down(t_game *game)
{
	find_player(game);

	if (game->map.tab[game->player.y][game->player.x] == 'P')
		if (game->map.tab[game->player.y + 1][game->player.x] != '1')
		{
			if (game->map.tab[game->player.y + 1][game->player.x] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y + 1][game->player.x] == 'E' && game->player.item == 0)
				exit(0);
			if (game->map.tab[game->player.y + 1][game->player.x] == 'E' && game->player.item != 0)
				return ;
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y + 1][game->player.x] = 'P';
			game->player.move++;
		}
		int a = 0;
	while(game->map.tab[a])
	{
		ft_printf("%s", game->map.tab[a]);
		a++;
	}
	ft_printf("\nnombre de deplacement : %d\n", game->player.move);
	return ;
}

void move_left(t_game *game)
{
	find_player(game);

	if (game->map.tab[game->player.y][game->player.x] == 'P')
		if (game->map.tab[game->player.y][game->player.x - 1] != '1')
		{
			if (game->map.tab[game->player.y][game->player.x - 1] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y][game->player.x - 1] == 'E' && game->player.item == 0)
				exit(0);
			if (game->map.tab[game->player.y][game->player.x - 1] == 'E' && game->player.item != 0)
				return ;
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y][game->player.x - 1] = 'P';
			game->player.move++;
		}
		int a = 0;
	while(game->map.tab[a])
	{
		ft_printf("%s", game->map.tab[a]);
		a++;
	}
	ft_printf("\nnombre de deplacement : %d\n", game->player.move);
	return ;
}

void move_right(t_game *game)
{
	find_player(game);

	if (game->map.tab[game->player.y][game->player.x] == 'P')
		if (game->map.tab[game->player.y][game->player.x + 1] != '1')
		{
			if (game->map.tab[game->player.y][game->player.x + 1] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y][game->player.x + 1] == 'E' && game->player.item == 0)
				exit(0);
			if (game->map.tab[game->player.y][game->player.x + 1] == 'E' && game->player.item != 0)
				return ;
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y][game->player.x + 1] = 'P';
			game->player.move++;
		}
	int a = 0;
	while(game->map.tab[a])
	{
		ft_printf("%s", game->map.tab[a]);
		a++;
	}
	ft_printf("\nnombre de deplacement : %d\n", game->player.move);
	return ;
}

