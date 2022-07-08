#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include "ft_printf.h"
# include "../get_next_line/get_next_line.h"

#define UP 13
#define LEFT 0
#define RIGHT 2
#define DOWN 1
#define ECHAP 53


typedef struct s_img
{
	void	*img;
	int     x;
	int 	y;
} t_img;

typedef struct s_player
{
	int item;
	int move;
	int exit;
	int x;
	int y;
} t_player;

typedef struct s_map
{
	char **tab;
	int item;
	int  fd;
} t_map;


typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map   map;
	t_img   img;
	t_player player;
} t_game;

char **init_tab(int fd);
int exit_game(t_game *game);
void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
int find_item(char **s);
void	find_player(t_game *game);


#endif
