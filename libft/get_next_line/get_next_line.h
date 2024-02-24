/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:46:06 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/22 15:55:06 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_node {
	struct s_node	*next;
	char			*content;
	size_t			content_len;
}	t_node;

typedef struct s_list {
	t_node	*head;
	t_node	*tail;
}	t_list;

typedef struct s_file {
	int		line;
	int		file_ended;
	char	*leftovers;
	int		leftovers_len;
}	t_file;

char	*get_next_line(int fd);
void	linked_list_free(t_list *list);
t_list	*linked_list_init(t_file *f);
void	*cleanup(t_list *list, char *buff, t_file *f, int free_leftovers);
t_node	*linked_list_new_node(ssize_t sz, t_file *f, char *buff, t_list *ls);

#endif
