/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:02:48 by assokenay         #+#    #+#             */
/*   Updated: 2021/02/25 16:05:28 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    char temp[256] = {0};
    int i, j;

    i = 1;
    while (i < 3 && argc == 3)
   {
        j = 0;
        while (argv[i][j])
        {
            if (!temp[(unsigned char)argv[i][j]])
            {
                temp[(unsigned char)argv[i][j]] = 1;    
                write(1, &argv[i][j], 1);          
            }
            j++;         
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
