#include "snake.h"
#include <stdio.h>

int	ft_error(const char *msg)
{
	fprintf(stderr, "snake: %s\n", msg);
	return (1);
}
