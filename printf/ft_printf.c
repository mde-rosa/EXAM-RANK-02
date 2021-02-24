/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:27:11 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/02/24 15:41:36 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_struct
{
	int width;
	int precision;
}              t_struct;

t_struct    initlist(void)
{
	t_struct    list;

	list.width = 0;
	list.precision = -1;
	return (list);
}

int     ft_putchar(char c, int i)
{
	static int pcc;

	if (i == -1)
		pcc = 0;
	if (i == 0)
	{
		write(1, &c, 1);
		pcc++;
	}
	if (i == 1)
		return (pcc);
	return (0);
}

void	print(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i], 0);
		i++;
	}
}

void	print_len(char *str, int len)
{
	int i = 0;
	while (i < len)
	{
		ft_putchar(str[i], 0);
		i++;
	}
}

int     is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

char 	*convert(unsigned int num, int base)
{
	static char	representation[] = "0123456789abcdef";
	static char	buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t i = 0;
	
	while (str[i])
		i++;
	return (i);
}

void    checkflag(const char **tmp, t_struct *list)
{
	char str[11] = {0};
	int i = 0;

	if (**tmp == '-')
		(*tmp)++;
	if (is_digit(**tmp))
	{
		while (is_digit(**tmp))
			str[i++] = (char)*(*tmp)++;
		str[i] = '\0';
		list->width = ft_atoi(str);
		str[0] = '\0';
	}
	if (**tmp == '.')
	{
		(*tmp)++;
		i = 0;
		if (!(is_digit(**tmp)))
			list->precision = 0;
		while (is_digit(**tmp))
			str[i++] = (char)*(*tmp)++;
		str[i] = '\0';
		list->precision = ft_atoi(str);
		str[0] = '\0';
	}
} 

void    checkconversion(const char **tmp, t_struct *list, va_list arg)
{
	int i;

	i = list->precision;
	i++;

	if (**tmp == 's')
	{
		char *s;
		int len;

		s = va_arg(arg, char *);
		if (s == NULL)
			s = "(null)";
		len = ft_strlen(s);
		if (list->precision > -1 && len > list->precision)
		{
			len = list->precision;
			if (list->width > 0)
			{
				while (list->width - len++ > 0)
					ft_putchar(' ', 0);
			}
			len = list->precision;
			print_len(s, len);
		}
		else
		{
			while (list->width - len++ > 0)
				ft_putchar(' ', 0);
			print(s);
		}

	}
	else if (**tmp == 'd')
	{
		int nbr;
		int len;
		int zero = 0;
		int space = 0;
		int neg = 0;
		nbr = va_arg(arg, int);
		if (nbr < 0)
		{
			nbr *= -1;
			neg = 1;
		}
		len = ft_strlen(convert(nbr, 10));
		
		if (list->precision > -1 && list->precision > len)
		{
			zero = list->precision - len;
			len = list->precision;
		}
		if (list->width > 0 && list->width > len)
		{
			space = list->width - len;
			if (neg == 1)
				space -= 1;
			if (list->precision == 0 && nbr == 0)
				space++;
		}
		while (space-- > 0)
			ft_putchar(' ', 0);
		if (neg == 1)
			ft_putchar('-', 0);
		while (zero-- > 0)
			ft_putchar('0', 0);
		if (!(list->precision == 0 && nbr == 0))
			print(convert(nbr, 10));
	}
	else if (**tmp == 'x')
	{
		int nbr;
		int len;
		int zero = 0;
		int space = 0;

		nbr = va_arg(arg, int);
		len = ft_strlen(convert(nbr, 16));
		if (list->precision > 0 && list->precision > len)
		{
			zero = list->precision - len;
			len = list->precision;
		}
		if (list->width > 0 && list->width > len)
		{
			space = list->width - len;
		}
		while (space-- > 0)
			ft_putchar(' ', 0);
		while (zero-- > 0)
			ft_putchar('0', 0);
		print(convert(nbr, 16));
	}
	else if (**tmp == '\0')
		return ;
	(*tmp)++;

}

int     ft_printf(const char *tmp, ...)
{
	va_list		arg;
	t_struct	list;
	ft_putchar('0', -1);
	va_start(arg, tmp);
	while (*tmp != '\0')
	{
		if (*tmp != '%')
		{
			ft_putchar(*tmp, 0);
			tmp++;
		}
		if (*tmp == '%')
		{
			tmp++;
			if (*tmp == '\0')
				break ;
			list = initlist();
			checkflag(&tmp, &list);
			checkconversion(&tmp, &list, arg);
		}
	}
	va_end(arg);
	return (ft_putchar('c', 1));
}
