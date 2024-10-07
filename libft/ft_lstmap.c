/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:37:00 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 16:12:20 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void *add_one(void *content)
// {
//     int *num = (int *)content;
//     int *new_num = malloc(sizeof(int));
//     if (new_num)
//         *new_num = (*num) + 1;
//     return (new_num);
// }

// void del(void *content)
// {
//     free(content);
// }

// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d -> ", *((int *)lst->content));
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int main(void)
// {
//     t_list *node1 = ft_lstnew("1");
//     t_list *node2 = ft_lstnew("2");
//     t_list *node3 = ft_lstnew("3");
//     node1->next = node2;
//     node2->next = node3;
//     t_list *mapped_list = ft_lstmap(node1, add_one, del);
//     printf("Original list: ");
//     print_list(node1);
//     printf("Mapped list: ");
//     print_list(mapped_list);
//     ft_lstclear(&node1, del);
//     ft_lstclear(&mapped_list, del);
//     return (0);
// }
