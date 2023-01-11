/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:50:29 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:28:23 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 0x7f=127, inverting it means all bits represeting 0~127 are 0
** if AND with ~0x7f results in 0, it means it includes 
** only the bits representing 0~127
*/
int	ft_isascii(int c)
{
	return (!(c & (~0x7f)));
}
