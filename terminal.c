#include "snake.h"
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

static struct termios	g_mode;

int	ft_terminal_start(void)
{
	struct termios	mode;

	if (!isatty(STDOUT_FILENO) || tcgetattr(STDIN_FILENO, &g_mode) < 0)
		return (0);
	mode = g_mode;
	mode.c_lflag &= ~(ICANON | ECHO);
	mode.c_cc[VMIN] = 0;
	mode.c_cc[VTIME] = 0;
	return (tcsetattr(STDIN_FILENO, TCSANOW, &mode) == 0);
}

int	ft_read_key(void)
{
	unsigned char	key;
	ssize_t			count;

	count = read(STDIN_FILENO, &key, 1);
	if (count == 1)
		return (key);
	if (count < 0 && errno != EINTR && errno != EAGAIN)
		return (KEY_ERROR);
	return (-1);
}

void	ft_delay(int ms)
{
	struct timespec	delay;

	delay.tv_sec = ms / 1000;
	delay.tv_nsec = (ms % 1000) * 1000000L;
	nanosleep(&delay, NULL);
}

void	ft_terminal_stop(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_mode);
}
