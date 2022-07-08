#include "header/so_long.h"

int key_action(int key, t_game *game)
{
	if (key == ECHAP)
	     exit_game(game);
	if (key == UP)
		move_up(game);
	if (key == LEFT)
		move_left(game);
	if (key == RIGHT)
		move_right(game);
	if (key == DOWN)
		move_down(game);

	return (0);
}

int main(int ac, char *av[])
{
	t_game game;

	game.map.fd = open("map/map.txt", O_RDONLY);
	game.map.tab = init_tab(game.map.fd);
	game.player.move = 0;
	game.player.item = find_item(game.map.tab);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");

	mlx_hook(game.win, 2, 2, key_action, &game);
	/*int a = 0;
	while(game.map.tab[a])
	{
		ft_printf("%s", game.map.tab[a]);
		a++;
	}*/
	mlx_loop(game.mlx);
}