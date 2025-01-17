/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:30:20 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/03 13:08:04 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_perr_and_init(void)
{
	if (!errno)
		return ;
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	errno = 0;
}

void	exec_free_split(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
}

char	*get_tmpf_name(int num)
{
	char	*num_str;
	char	*res;

	num_str = ft_itoa(num);
	if (!num_str)
		return (0);
	res = ft_strjoin("my_tmp_", num_str);
	if (!res)
	{
		free(num_str);
		return (0);
	}
	free(num_str);
	return (res);
}

void	rlw_tmpf(int fd, char *arg)
{
	char	*line;
	int		len;

	len = ft_strlen(arg);
	line = readline(">");
	while (line && ft_strncmp(line, arg, len))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(">");
	}
	if (line)
		free(line);
}
