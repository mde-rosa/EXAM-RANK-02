/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:08:29 by assokenay         #+#    #+#             */
/*   Updated: 2021/02/25 16:05:32 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char temp[256] = {0};
	int i, j;

	i = 2;
	while ( i > 0 && argc == 3)
	{     
		j = 0;
		while (argv[i][j])
		{
			if (i == 2 && !temp[(unsigned char)argv[i][j]])
				temp[(unsigned char)argv[i][j]] = 1;
			else if (i == 1 && temp[(unsigned char)argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				temp[(unsigned char)argv[i][j]] = 0;
			}
			j++;
		}
		i--;
	}
	write(1, "\n", 1);
	return (0);
}