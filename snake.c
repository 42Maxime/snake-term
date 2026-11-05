#include "snake.h"
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

static volatile sig_atomic_t	g_stop;

static void	ft_stop(int sig)
{
	(void)sig;
	g_stop = 1;
}

static int	ft_play(t_game *game)
{
	int	key;

	ft_draw(game);
	while (!g_stop && game->len - 3 < TARGET)
	{
		key = ft_read_key();
		if (key == KEY_ERROR)
			return (ft_error("Could not read the keyboard."));
		if (key == 'x' || key == 'X')
			break ;
		if (ft_turn(game, key))
			game->started = 1;
		if (game->started && !ft_move(game))
			return (puts("Game over."), 0);
		if (game->started)
			ft_draw(game);
		ft_delay(145);
	}
	if (game->len - 3 == TARGET)
		puts("42 snacks. You win!");
	return (0);
}

int	main(void)
{
	t_game	game;
	int		status;

	signal(SIGINT, ft_stop);
	signal(SIGTERM, ft_stop);
	if (!ft_terminal_start())
		return (ft_error("Run snake in an interactive terminal."));
	srand((unsigned int)time(NULL));
	ft_init(&game);
	printf("\033[2J");
	status = ft_play(&game);
	ft_terminal_stop();
	return (status);
}
