/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynlauro <lynlauro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:44:25 by lynlauro          #+#    #+#             */
/*   Updated: 2026/06/03 22:44:26 by lynlauro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new;
    t_list *node;
    void *content;

    new = NULL;
    if (!lst || !f || !del)
        return (NULL);
    while (lst)
    {   
        content = f(lst->content);
        node = ft_lstnew(content);
        if (!node)
        {
            del(node->content);
            ft_lstclear(&new, del);
            return (NULL);
        }
        ft_lstadd_back(&new, node);
        lst = lst->next;
    }
    return (new);
}
