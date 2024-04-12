#include "push_swap.h"

int	main(void)
{
	t_list	*a;
	int	i = 0;

	a = NULL;
	while (i < 5)
	{
		ft_lstadd_front(a, ft_lstnew((int*)i));
		i++;
	}
	
}
