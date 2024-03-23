/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:38:11 by dlariono          #+#    #+#             */
/*   Updated: 2023/05/27 17:40:04 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
		return (ft_putstr("(null)"));
	count = 0;
	while (*str)
	{
		count = count + write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_atoi(const char *a)
{
	int	nb;
	int	is_neg;
	int	found;

	found = 1;
	nb = 0;
	is_neg = 1;
	while (*a == 32 || (*a >= 9 && *a <= 13))
		a++;
	if (*a == 45)
		is_neg = -1;
	if (*a == 43 || *a == 45)
		a++;
	while (*a && found)
	{
		if (*a >= '0' && *a <= '9')
			nb = nb * 10 + *a - '0';
		else
			found = 0;
		a++;
	}
	return (nb * is_neg);
}

void	handler(int signum)
{
	static int	bits;
	static char	final_msg;

	if (signum == SIGUSR1)
		final_msg = ((1 << bits) | final_msg);
	else
		final_msg = ((0 << bits) | final_msg);
	bits++;
	if (bits == 8)
	{
		write(1, &final_msg, 1);
		bits = 0;
		final_msg = '\0';
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	(void) argv;
	i = 0;
	if (argc != 1)
	{
		ft_putstr("Please, verify the input\0");
		return (0);
	}
	pid = getpid();
	printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}
