#include "snake.h"
#include <stdio.h>
#include <string.h>

static void	ft_border(void)
{
	int	x;

	putchar('+');
	x = 0;
	while (x++ < WIDTH)
		putchar('-');
	puts("+");
}

static void	ft_fill_board(const t_game *game, char board[HEIGHT][WIDTH])
{
	int	i;

	memset(board, ' ', WIDTH * HEIGHT);
	board[game->food.y][game->food.x] = '*';
	i = game->len - 1;
	while (i > 0)
	{
		board[game->body[i].y][game->body[i].x] = 'o';
		i--;
	}
	board[game->body[0].y][game->body[0].x] = '@';
}

static void	ft_row(const char *row)
{
	int	x;

	putchar('|');
	x = 0;
	while (x < WIDTH)
	{
		if (row[x] == '@' || row[x] == '*')
			printf("\033[38;5;205m%c\033[0m", row[x]);
		else
			putchar(row[x]);
		x++;
	}
	puts("|");
}

void	ft_draw(const t_game *game)
{
	char	board[HEIGHT][WIDTH];
	int		y;

	ft_fill_board(game, board);
	printf("\033[H\033[38;5;205m42 / snake\033[0m     snacks %2d / %d\n",
		game->len - 3, TARGET);
	ft_border();
	y = 0;
	while (y < HEIGHT)
		ft_row(board[y++]);
	ft_border();
	printf("\033[K");
	if (game->started)
		puts("WASD / ZQSD to move    x to exit");
	else
		puts("Press WASD / ZQSD to start    x to exit");
	puts("\033[KGitHub @42Maxime");
	fflush(stdout);
}
