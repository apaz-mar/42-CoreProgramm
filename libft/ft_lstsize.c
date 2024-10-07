/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:08:10 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 12:28:26 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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
//     int len = 0;
//     t_list *nodeA = ft_lstnew("A");
//     t_list *nodeB = ft_lstnew("B");
//     t_list *nodeC = ft_lstnew("C");
//     nodeA->next = nodeB;
//     nodeB->next = nodeC;
//     t_list *head = nodeA;
//     printf("List: ");
//     print_list(head);
//     len = ft_lstsize(head);
//     printf("El tamano de la lista es: %d\n", len);
//     // t_list *new_node = ft_lstnew("N");
//     // ft_lstadd_front(&head, new_node);
//     // printf("Modified list: ");
//     // print_list(head);
//     t_list *temp;
//     while (head)
//     {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
// 	return (0);
// }
