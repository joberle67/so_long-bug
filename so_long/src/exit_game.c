#include "../header/so_long.h"

int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}