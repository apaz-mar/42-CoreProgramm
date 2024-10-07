/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:35:04 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/19 14:14:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	return ;
}

// void    del_function(void *content)
// {
//     free(content);
// }

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

//     printf("Initial list: ");
//     print_list(nodeA);
//     ft_lstdelone(nodeA, del_function);
// 	return (0);
// }
