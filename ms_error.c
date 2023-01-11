/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:22:09 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:10 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_error_msg(char *s, int exit_code)
{
	printf("minishell: %s: %s\n", s, strerror(exit_code));
	return (exit_code);
}
