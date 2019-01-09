/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:34:29 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 20:14:38 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void){
	float one;
	float zero;
	float nan;
	float inf;

	one = 1;
	zero = 0;
	inf = one / zero;
	nan = zero / zero;
	printf("expected:\n%f\n%f\n\n", inf, nan);
	ft_printf("result:\n%f\n%f\n", inf, nan);
	return (0);}
