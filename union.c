/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:02:48 by assokenay         #+#    #+#             */
/*   Updated: 2021/02/22 23:54:50 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    char temp[255] = {0};
    int i, j;

    if (argc == 3)
    {
        i = 1;
        while (i < 3)
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
    }
    write(1, "\n", 1);
    return (0);
}
