/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:46:08 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/04 01:30:41 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	file_add_leftovers(char *buff, ssize_t index, ssize_t sz, t_file *f)
{
	char	*res;
	ssize_t	i;

	res = malloc(sizeof(char) * (sz - index));
	if (!res)
	{
		if (f->leftovers)
			free(f->leftovers);
		f->leftovers = NULL;
		return ;
	}
	i = 0;
	while ((i + 1) < (sz - index))
	{
		res[i] = buff[index + i + 1];
		i++;
	}
	res[i] = '\0';
	if (f->leftovers)
		free(f->leftovers);
	f->leftovers = res;
	f->leftovers_len = i;
}

static char	*node_add_content(ssize_t sz, char *buff, t_file *f, t_node *node)
{
	char	*res;
	ssize_t	i;

	res = malloc(sizeof(char) * (sz + 1));
	if (!res)
		return (0);
	i = 0;
	while (buff[i])
	{
		res[i] = buff[i];
		if (buff[i] == '\n')
		{
			file_add_leftovers(buff, i++, sz, f);
			f->line++;
			break ;
		}
		i++;
	}
	res[i] = '\0';
	node->content = res;
	node->content_len = i;
	return (res);
}

void	linked_list_free(t_list *list)
{
	t_node	*next;
	t_node	*curr;

	curr = list->head;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
	free(list);
}

t_node	*linked_list_new_node(ssize_t sz, t_file *f, char *buff, t_list *list)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	if (!node_add_content(sz, buff, f, node))
	{
		free(node);
		return (0);
	}
	node->next = NULL;
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
		return (node);
	}
	list->tail->next = node;
	list->tail = node;
	return (node);
}

t_list	*linked_list_init(t_file *f)
{
	t_list	*list;
	t_node	*node;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->head = NULL;
	list->tail = NULL;
	if (f->leftovers && f->leftovers_len > 0)
	{
		node = linked_list_new_node(f->leftovers_len, f, f->leftovers, list);
		if (!node)
		{
			free(list);
			return (0);
		}
	}
	return (list);
}
