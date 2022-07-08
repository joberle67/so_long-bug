#include "../header/so_long.h"

void	find_player(t_game *game)
{
	int a;
	int i;

	a = 1;
	i = 1;

	while(game->map.tab[a])
	{
		while(game->map.tab[a][i] != '\0')
		{
			if (game->map.tab[a][i] == 'P')
			{
				game->player.x = i;
				game->player.y = a;
				return ;
			}
			i++;
		}
		a++;
		i = 1;
	}
}

int find_item(char **s)
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
	return (item);
}