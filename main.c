/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:34:29 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/13 14:36:49 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void){
	printf("expected %#x %s %c\n", 69420, "big chungus", 'd');
	ft_printf("result   %#x %s %c\n", 69420, "big chungus", 'd');
	return (0);}
