/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 19:27:11 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

/* make sure this handles all the formatting variables */

char	*handle_width(char *s, t_flag *flags)
{
	char	*c;
	char	*n;
	int		len;

	c = ft_strnew(1);
	len = (int)ft_strlen(s);
	if (flags->zero && !flags->dash && len < flags->prec && flags->dot)
		c[0] = '0';
	else
		c[0] = ' ';
	n = s;
	while (len < flags->width)
	{
		if (flags->dash)
			n = ft_strjoin(n, c);
		else
			n = ft_strjoin(c, n);
		len++;
	}
	return (n);
}

char	*handle_space(char *s)
{
	char	*c;
	char	*n;

	c = ft_strnew(1);
	*c = (*s == '-') ? '-' : ' ';
	n = s;
	n = ft_strjoin(c, n);
	return (n);
}

char	*handle_precision(char *s, t_flag *flags, char c)
{
	char	*t;
	char	*n;
	int		len;

	t = ft_strnew(1);
	*t = '0';
	n = s;
	len = (int)ft_strlen(s);
	if (len < flags->prec)
		if (c != 'c' && c != 's')
			while (len < flags->prec)
			{
				n = ft_strjoin(t, n);
				len++;
			}
	if (len > flags->prec)
		n = ft_strndup(n, flags->prec);
	return (n);
}

char	*alt(char *s, char c)
{
	char	*n;

	n = s;
	if (s[0] != '0' && (s[1] != 'x' || s[1] != 'X'))
	{
		if (c == 'x' || c == 'X')
			n = ft_strjoin("0x", s);
		if (c == 'o')
			n = ft_strjoin("0", s);
	}
	return (n);
}

char	*format_string(char *s, t_flag *flags, char c)
{
	char	*n;

	n = s;
	if (!n && c == 's')
		n = ft_strdup("(null)");
	if (!n && c == 'p')
		n = ft_strdup("0x0");
	if (!n && c == 'c')
		n = ft_strdup("");
	if (flags->sharp || c == 'p')
		n = c == 'p' ? alt(n, 'x') : alt(n, c);
	if (flags->space)
		n = handle_space(n);
	if (flags->dot && c != 'f')
		n = handle_precision(n, flags, c);
	if (flags->width)
		n = handle_width(n, flags);
	return (n);
}
