#include "snake.h"
#include <windows.h>
#include <conio.h>

static DWORD	g_mode;

int	ft_terminal_start(void)
{
	HANDLE	output;
	DWORD	input_mode;

	output = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &input_mode))
		return (0);
	if (!GetConsoleMode(output, &g_mode))
		return (0);
	return (SetConsoleMode(output, g_mode
			| ENABLE_VIRTUAL_TERMINAL_PROCESSING));
}

int	ft_read_key(void)
{
	int	key;

	if (!_kbhit())
		return (-1);
	key = _getch();
	if (key == 0 || key == 224)
	{
		_getch();
		return (-1);
	}
	return (key);
}

void	ft_delay(int ms)
{
	Sleep(ms);
}

void	ft_terminal_stop(void)
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), g_mode);
}
