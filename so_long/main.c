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
	if (ac != 2)
	{
		ft_printf("Usage : ./a.out ./map/[map].ber\n");
		exit(0);
	}
	init_game(&game, av[1]);
	mlx_hook(game.win, 2, 2, key_action, &game);
	mlx_hook(game.win, 17, 1L << 17, exit_game, &game);
	mlx_loop(game.mlx);
}