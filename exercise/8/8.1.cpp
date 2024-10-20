#include <iostream>
static int	g_count = 0;
void	t_puts(const char *str, int flag = 0);

int main(void)
{
	t_puts("hello world!", 1);
	return 0;
}

void	t_puts(const char *str, int flag)
{
	int	i;

	i = -1;
	if (!flag)
	{
		std::cout << str << std::endl;
		g_count++;
	}
	else
	{
		while (++i < g_count)
			std::cout << str << std::endl;
	}
}