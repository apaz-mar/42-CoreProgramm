/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:18:11 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 15:25:07 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}

// void	f(void *content)
// {
// 	int *ptr = (int *)content;
//     *ptr = *ptr + 2;
//     return ;
// }

// void    print_list(t_list *lst)
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
//     ft_lstiter(head, f);
//     printf("List after f application: ");
//     print_list(head);
// 	return (0);
// }
