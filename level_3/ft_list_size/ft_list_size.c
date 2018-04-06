#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	return (begin_list) ? (ft_list_size(begin_list->next) + 1) : (0);
}
