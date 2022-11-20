#include "minitalk.h"

void send_bits(int pid, int character)
{
	int bit;

	bit = 8;
	while (0 < bit--)
	{
		if (character & 1 << bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(2500);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("ERROR WRONG NUMBERS OF ARGUMENTS \n USAGE= ./client <PID> <\"MESSAGE\">");
	}
	else
	{
		size_t i = 0;
		while (argv[2][i])
		{
			send_bits(ft_atoi(argv[1]),argv[2][i]);
			i++;
		}
	}

	kill(ft_atoi(argv[1]), SIGUSR1);
	return 0;
}
