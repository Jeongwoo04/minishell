/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:39:58 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/03 15:45:53 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parents_do(pid_t pid, char *full_path)
{
	int		status;
	int		res;

	free(full_path);
	res = 0;
	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		res = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		res = 128 + WTERMSIG(status);
	return (res);
}
