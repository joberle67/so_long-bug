#include "../header/so_long.h"

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

int error_map(char **str , t_game *game)
{
	int a;
	int i;

	a = 0;
	i = 0;
	while(str[a])
	{
		while(str[a][i])
			i++;
		if(i > game->map.x)
			return (0);
		game->map.y = a + 1;
		game->map.x = ft_strlen(str[a]);
		a++;
		i = 0;
	}
	if (game->map.y == game->map.x )
			return (0);
	return (1);
}

int if_not_close(char **str)
{
	int a;
	int i;

	a = 1;
	i = 0;
	while(str[0][i + 1])
	{
		if (str[0][i] != '1')
			return (0);
		i++;
	}
	while(str[a])
	{
		if (str[a][0] != '1' || str[a][i-1] != '1')
			return (0);
		a++;
	}
	i = 0;
	while(str[a - 1][i + 1])
	{
		if (str[a - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int is_ber(char *str)
{
	int i;
	int a;
	char *tab;

	i = ft_strlen(str);
	a = 0;
	tab = ".ber";
	while (str[i] != '.' && i > 0)
		i--;
	while(str[i])
	{
		if (str[i] != tab[a])
			error_exit();
		i++;
		a++;
	}
	if (i == 0)
		error_exit();
	return (0);
}

void error_game(t_game *game)
{
	//if (error_map(game->map.tab, game))
	//	error_exit();
	if (!find_player(game) || !find_item(game->map.tab, game))
		error_exit();
	if (!find_exit(game->map.tab) || !if_not_close(game->map.tab))
		error_exit();
	if (is_ber(game->path))
		error_exit();
}