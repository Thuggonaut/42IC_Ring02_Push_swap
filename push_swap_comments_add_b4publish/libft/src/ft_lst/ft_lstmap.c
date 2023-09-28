#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current_node;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		current_node = ft_lstnew(f(lst->content));
		if (!current_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, current_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
TEST FRANCINETTE STRICT:

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;
	void	*content;

	new_list = NULL;
	head = new_list;
	if (!(f || del))
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			return (free(content), ft_lstclear(&head, del), NULL);
		}
		new_list = ft_lstnew(content);
		if (!new_list)
		{
			return (free(content), ft_lstclear(&head, del), NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
*/