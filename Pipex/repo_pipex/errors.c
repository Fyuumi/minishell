/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:07:43 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/19 12:15:03 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(t_pipex *px, const char *msg, int exit_code)
{
	if (msg)
		ft_printf("Error: %s\n", msg);
	pipex_cleanup(px);
	exit(exit_code);
}

void	free_strtab(char **strtab)
{
	int	i;

	if (!strtab)
		return ;
	i = 0;
	while (strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	free(strtab);
}
