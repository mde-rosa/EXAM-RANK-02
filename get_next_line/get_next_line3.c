/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:38:26 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/02/25 16:45:21 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line)
{
    char buffer;
    char ret;
    char *str;
    char temp[4096];
    int len = 0;

    if (!(line))
        return (-1);
    temp [0] = '0';
    while ((ret = read(0, &buffer, 1) > 0)
    {
        if (buffer == '\n' || buffer == '\0')
            break;
        temp[len++] = buffer;
    }
    temp[len + 1] = '\0';
    if (!(str = (char *)malloc(sizeof(char) * (len +1))))
        return (-1);
    str[len] = '\0';
    while (len-- >= 0)
        str[len] = temp[len];
    *line = str;
    return (ret);    
}