#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *astack;
	int count;
	
	astack = NULL;
	count = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	count = check(argv);
	if (count == -1)
		return (0);
	convert(argv, &astack);
	push_swap(&astack);
	free_stack(&astack);
	return (0);
}
