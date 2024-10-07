/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:29:05 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 12:49:42 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
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
//     printf("List: ");
//     print_list(head);
//     t_list *result = ft_lstlast(head);
//     printf("El ultimo nodo es :");
//     print_list(result);
//     t_list *temp;
//     while (head)
//     {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
// 	return (0);
// }
