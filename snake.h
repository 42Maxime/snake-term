#ifndef SNAKE_H
# define SNAKE_H

# define WIDTH 42
# define HEIGHT 14
# define TARGET 42
# define KEY_ERROR -2

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	t_point	body[WIDTH * HEIGHT];
	t_point	dir;
	t_point	food;
	int		len;
	int		started;
}	t_game;

void	ft_init(t_game *game);
int		ft_turn(t_game *game, int key);
int		ft_move(t_game *game);
void	ft_draw(const t_game *game);
int		ft_terminal_start(void);
int		ft_read_key(void);
void	ft_delay(int ms);
void	ft_terminal_stop(void);
int		ft_error(const char *msg);

#endif
