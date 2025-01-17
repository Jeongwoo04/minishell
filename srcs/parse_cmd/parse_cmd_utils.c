/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 00:00:30 by sangjeon          #+#    #+#             */
/*   Updated: 2021/12/27 21:21:15 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmd.h"

int	_isspace(char chr)
{
	if (chr == '\t')
		return (1);
	if (chr == ' ')
		return (1);
	return (0);
}

int	is_multi_cmd(const char *str)
{
	if (!ft_strncmp(">>", str, 2))
		return (REDIRECT_APPEND);
	else if (!ft_strncmp("<<", str, 2))
		return (REDIRECT_HEREDOC);
	else if (!ft_strncmp(">", str, 1))
		return (REDIRECT_OUTPUT);
	else if (!ft_strncmp("<", str, 1))
		return (REDIRECT_INPUT);
	else
		return (0);
}

void	redi_move_ptr(char **line_ptr, int redi_status)
{
	(*line_ptr)++;
	if (redi_status == REDIRECT_APPEND)
		(*line_ptr)++;
	if (redi_status == REDIRECT_HEREDOC)
		(*line_ptr)++;
	while (**line_ptr && _isspace(**line_ptr))
		(*line_ptr)++;
}

char	**list_to_arr(t_list *list)
{
	char	**arr;
	int		len;
	t_list	*tmp;

	tmp = list;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (0);
	len = 0;
	while (list)
	{
		arr[len] = (char *)(list->content);
		len++;
		list = list->next;
	}
	arr[len] = 0;
	return (arr);
}

void	del_redi_one(void *content)
{
	if (!content)
		return ;
	free(((t_redi *)content)->arg);
	free(content);
}
