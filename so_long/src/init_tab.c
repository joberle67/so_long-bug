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