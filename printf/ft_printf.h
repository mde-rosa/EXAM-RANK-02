/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:51:41 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/02/25 19:04:46 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_struct
{
    int width;
    int precision;
}               t_struct;

int ft_printf(const char *tmp, ... );
int ft_putchar(char c, int nbr);
void	print(char *str);
void	print_len(char *str, int len);
int	ft_atoi(char *str);
size_t	ft_strlen(char *str);
char	*convert(unsigned int num, int base);
void	checkflag(const char **tmp, t_struct *list);
void	checkconversion(const char **tmp, t_struct *list, va_list arg);

#endif