#include "../header/so_long.h"

int	find_player(t_game *game)
{
	int a;
	int i;
	int nb;

	a = 1;
	i = 1;
	nb = 0;
	while(game->map.tab[a])
	{
		while(game->map.tab[a][i] != '\0')
		{
			if (game->map.tab[a][i] == 'P')
			{
				game->player.x = i;
				game->player.y = a;
				nb++;
			}
			i++;
		}
		a++;
		i = 1;
	}
	if (nb == 1)
		return (1);
	return (0);
}

int find_item(char **s, t_game *game)
{
	int a;
	int i;
	int item;

	a = 1;
	i = 1;
	item = 0;
	while(s[a])
	{
		while(s[a][i] != '\0')
		{
			if (s[a][i] == 'C')
				item++;
			i++;
		}
		a++;
		i = 1;
	}
	if (item > 0)
	{
		game->player.item = item;
		return (item);
	}
	return (0);
}

int find_exit(char **s)
{
	int a;
	int i;
	int item;

	a = 1;
	i = 1;
	item = 0;
	while(s[a])
	{
		while(s[a][i] != '\0')
		{
			if (s[a][i] == 'E')
				item++;
			i++;
		}
		a++;
		i = 1;
	}
	if (item == 1)
		return(1);	
	return (0);
}