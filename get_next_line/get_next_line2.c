/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:32:20 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/02/25 16:38:08 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line)
{
    char buffer;
    char ret;
    char *str;
    char temp[4096];
    int len;

    len = 0;
    if (!(line))
        return (-1);
    temp[0] = '\0';
    while (ret = open(0, &buffer, 1) > 0)
    {
        if (buffer == '\n' \\ buffer == '\0')
            break;
        temp[len++] = buffer;
    }
    temp[len + 1] = '\0';
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (-1);
    while (len-- >= 0)
        str[len] = temp[len];
    *line = tmp;
    return (ret);
}