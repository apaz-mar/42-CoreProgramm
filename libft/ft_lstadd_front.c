/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:24:32 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 12:06:53 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void    print_list(t_list *lst)
// {
//     while(lst)
//     {
//         printf("%s -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int	main(void)
// {
//     t_list *nodeA = ft_lstnew("A");
//     t_list *nodeB = ft_lstnew("B");
//     t_list *nodeC = ft_lstnew("C");
//     nodeA->next = nodeB;
//     nodeB->next = nodeC;
//     t_list *head = nodeA;
//     printf("Initial list: ");
//     print_list(head);
//     t_list *new_node = ft_lstnew("N");
//     ft_lstadd_front(&head, new_node);
//     printf("Modified list: ");
//     print_list(head);
//     // free(nodeA);
//     // free(nodeB);
//     // free(nodeC);
//     // free(head);
// 	return (0);
// }
