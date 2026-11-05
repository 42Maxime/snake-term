#include "snake.h"
#include <stdlib.h>

static int	ft_on_snake(t_game *game, t_point pos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (game->body[i].x == pos.x && game->body[i].y == pos.y)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_place_food(t_game *game)
{
	game->food.x = rand() % WIDTH;
	game->food.y = rand() % HEIGHT;
	while (ft_on_snake(game, game->food, game->len))
	{
		game->food.x = rand() % WIDTH;
		game->food.y = rand() % HEIGHT;
	}
}

void	ft_init(t_game *game)
{
	int	i;

	game->len = 3;
	game->started = 0;
	game->dir.x = 1;
	game->dir.y = 0;
	i = 0;
	while (i < game->len)
	{
		game->body[i].x = 10 - i;
		game->body[i].y = HEIGHT / 2;
		i++;
	}
	ft_place_food(game);
}

int	ft_turn(t_game *game, int key)
{
	t_point	dir;

	dir.x = 0;
	dir.y = 0;
	if (key == 'w' || key == 'z')
		dir.y = -1;
	else if (key == 's')
		dir.y = 1;
	else if (key == 'a' || key == 'q')
		dir.x = -1;
	else if (key == 'd')
		dir.x = 1;
	else
		return (0);
	if (dir.x != -game->dir.x || dir.y != -game->dir.y)
		game->dir = dir;
	return (1);
}

/* The tail leaves its square on this turn unless the snake eats. */
int	ft_move(t_game *game)
{
	t_point	head;
	int		eats;
	int		i;

	head.x = game->body[0].x + game->dir.x;
	head.y = game->body[0].y + game->dir.y;
	eats = (head.x == game->food.x && head.y == game->food.y);
	if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT)
		return (0);
	if (ft_on_snake(game, head, game->len - 1 + eats))
		return (0);
	game->len += eats;
	i = game->len - 1;
	while (i > 0)
	{
		game->body[i] = game->body[i - 1];
		i--;
	}
	game->body[0] = head;
	if (eats && game->len - 3 < TARGET)
		ft_place_food(game);
	return (1);
}
