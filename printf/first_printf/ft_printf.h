/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:48:44 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/02/24 20:26:43 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_struct
{
	int width;
	int precision;
}               t_struct;

int             ft_printf(const char *tmp, ...);
int             ft_putchar(char c, int i);
void	        print(char *str);
void	        print_len(char *str, int len);
int             is_digit(int c);
int             ft_atoi(char *str);
char            *convert(unsigned int num, int base);
size_t          ft_strlen(const char *str);
void            checkflag(const char **tmp, t_struct *list);
void            checkconversion(const char **tmp, t_struct *list, va_list arg);

#endif