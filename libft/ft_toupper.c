/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:25:09 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:39:26 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** uppercase and lowercase both have 7th bit(64) as 1
** the only difference between the two is that lowercase has 6th bit(32) as 0
** 95 = 64 + 31 so AND with 95 only sets 6th bit(32) to 0(resulting in -32)
*/
int	ft_toupper(int c)
{
	if ((unsigned)c - 'a' < 26)
		return (c & 95);
	return (c);
}
