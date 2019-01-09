/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 20:33:32 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

/* make sure this handles all the formatting variables */
/* something's wrong with the width return			   */

char	*handle_width(char *s, t_flag *flags)
{
	char	*c;
	char	*n;
	int		len;

	len = (int)ft_strlen(s);
	n = NULL;
	if (flags->zero && !flags->dash && ((len < flags->prec && flags->dot) ||
				(!flags->dot)))
		c = ft_strdup("0");
	else
		c = ft_strdup(" ");
	n = ft_strdup(s);
	while (len < flags->width)
	{
		if (flags->dash)
			n = swap_n_free(ft_strjoin(n, c), &n);
		else
			n = swap_n_free(ft_strjoin(c, n), &n);
		len++;
	}
	free (c);
	return (n);
}

char	*handle_space(char *s)
{
	char	*c;
	char	*n;

	c = ft_strdup(" ");
	n = NULL;
	if (s[0] != ' ' && s[0] != '-')
		n = ft_strjoin(c, s);
	else
		n = ft_strdup(s);
	free(c);
	return (n);
}

char	*handle_precision(char *s, t_flag *flags, char c)
{
	char	*t;
	char	*tmp;
	char	*n;
	int		len;

	if (*s == '-')
		return (neg_prec(s, flags, c));
	t = ft_strdup("0");
	n = ft_strdup(s);
	tmp = NULL;
	len = (int)ft_strlen(s);
	if (len < flags->prec)
		if (c != 'c' && c != 's')
			while (len < flags->prec)
			{
				tmp = ft_strjoin(t, n);
				free (n);
				n = tmp;
				tmp = NULL;
				free (tmp);
				len++;
			}
	if (len > flags->prec && (c == 'f' || c == 's'))
		tmp = ft_strndup(n, flags->prec);
	free (t);
	free (tmp);
	return (n);
}

char	*alt(char *s, char c)
{
	char	*n;

	n = NULL;
	if (s[0] != '0' && c == 'o')
		 n = ft_strjoin("0", s);
	else if ((c == 'x' || c == 'X' || c == 'p') && !(s[1] == 'x' || s[1] == 'X'))
		n = ft_strjoin("0x", s);
	else
		n = ft_strdup(s);
	return (n);
}

char	*format_string(char *s, t_flag *flags, char c)
{
	char	*n;

	n = s;
	if (!n && c == 's')
		return (ft_strdup("(null)"));
	if (!n && c == 'p')
		return (ft_strdup("0x0"));
	if (!n && c == 'c')
		return (ft_strdup(""));
	if (float_check(s))
		return (s);
	if (flags->dot && c != 'f')
		n = swap_n_free(handle_precision(n, flags, c), &n);
	if (flags->sharp)
		n = swap_n_free(alt(n, c), &n);
	if (flags->width)
		n = swap_n_free(handle_width(n, flags), &n);
	if (flags->space && c != '%')
		n = swap_n_free(handle_space(n), &n);
	return (n);
}
