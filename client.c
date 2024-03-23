/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:38:13 by dlariono          #+#    #+#             */
/*   Updated: 2023/05/27 17:35:06 by dlariono         ###   ########.fr       */
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

void	convert_signal_to_bytes(int server_pid, char client_msg)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((client_msg >> bits) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(150);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Please, verify the input\0");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		convert_signal_to_bytes(pid, argv[2][i]);
		printf("%c", argv[2][i]);
		i++;
	}
}
