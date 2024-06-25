#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	create_cross(t_cross **stack, int argc, int *array, t_cross **stack_b)
{
	t_cross *node;
	t_cross *node2;
	int		i;
	t_cross *head;

	node = ft_lstnew(0, -1);
	node2 = ft_lstnew(0, -1);
	i = 0;
	if (!node || !node2)
		exit(0);
	*stack = NULL;
	*stack_b = NULL;
	ft_lstadd_back(stack, node);
	ft_lstadd_back(stack_b, node2);
	while (i < argc)
	{
		node = ft_lstnew(array[i], 0);
		if (!node)
			exit(0);
		ft_lstadd_back(stack, node);
		i++;
	}
}

void assign_order(t_cross *stack, int argc, int *array)
{
	int i;

	stack = stack->next;
	while (stack->rank != -1)
	{
		i = 0;
		while (i < argc)
		{
			if (stack->value == array[i])
			{
				stack->rank = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	output_cross(t_cross *stack)
{
	t_cross *head;

	head = stack->next;
	while (head->rank != -1)
	{
		printf("後ろのノードの値：%d 現在のノードの値：%d 次のノードの値：%d 大きさ: %d\n", (head->prev)->value, head->value, (head->next)->value, head->rank);
		printf("-----------------------------------------------------------------------\n");
		head = head->next;
	}
}