# include "minitalk.h"


static int	power(int power)
{
	int	i;
	int	res;
	int	n;

	res = 1;
	i = 0;
	n = 2;
	if (power == 0)
		return (1);
	else
	{
		while (i < power)
		{
			res = res * n;
			i++;
		}
	}
	return (res);
}

static void	siguser_action(int sig)
{
	static unsigned char	str;
	static int				i;	

	if (sig == SIGUSR2)
		str = str + power(7 - i);
	i++;
	if (i == 8)
	{
		write(1, &str, sizeof(char));
		i = 0;
		str = 0;
	}
}
/* 

void siguser_action(int sig)
{
	static int	i;
	static int	c;

	if (sig == SIGUSR2)
		c = (c << 1) | 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0;
	i++;
	if (i > 7)
	{
		write(1,&c, 1);
		i = 0;
		c = 0;
	}

} */

int	main(void)
{
    signal(SIGUSR1, &siguser_action);
	signal(SIGUSR2, &siguser_action);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}