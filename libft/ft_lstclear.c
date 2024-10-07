/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:35:03 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 15:04:48 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
	return ;
}

// void	del_function(void *content)
// {
// 	free(content);
//     return ;
// }

// void    print_list(const t_list *lst)
// {
//     while(lst)
//     {
//         printf("%s -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
//     return ;
// }

// int	main(void)
// {
//     t_list *nodeA = ft_lstnew("A");
//     t_list *nodeB = ft_lstnew("B");
//     t_list *nodeC = ft_lstnew("C");
//     nodeA->next = nodeB;
//     nodeB->next = nodeC;
//     t_list *head = nodeA;
//     nodeC->next = NULL;
//     printf("Initial list: ");
//     print_list(head);
//     ft_lstclear(&head, del_function);
// 	return (0);
// }
