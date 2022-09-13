#include "so_long.h"

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(char content)
{
	t_list	*n_list;

	printf("print content : %c\n", content);
	n_list = (t_list *)malloc(sizeof(t_list));
	if (n_list == 0)
		return (0);
	n_list -> content = content;
	n_list -> next = 0;
	return (n_list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->next = 0;
}

void	make_temp_list(t_list *temp_list, char *temp)
{
	int	i;

	i = 0;
	if (0 == temp)
		return ;
	while (0 != temp[i] && '\n' != temp[i])
	{
		printf("str[%d]: %c\n", i, temp[i]);
		ft_lstadd_back(&temp_list, ft_lstnew(temp[i]));
		i++;
	}
}

void	init_map(char **av)
{
	int		fd;
	size_t	length;
	int		line_number;
	char	*temp;
	t_list	*temp_list;
	int	i;

	fd = open(av[1], O_RDONLY);
	temp = get_next_line(fd);
	length = ft_strlen(temp);
	temp_list = 0;
	line_number = 0;
	while (0 != temp)
	{
		i = 0;
		printf("before str: %s\n", temp); // 이상없음 부분
		while ('\0' != temp[i])
		{
			// printf("%d", temp[i]);
			ft_lstadd_back(&temp_list, ft_lstnew(temp[i]));
			i++;
		}
		// 임시코드
		// t_list *merong = temp_list;
		// while (merong)
		// {
		// 	printf("%c", merong->content);
		// 	merong = merong->next;
		// }
		printf("\n\n");
		printf("str: %s\n", temp); // 이상있는 부분
		temp = get_next_line(fd);
		// printf("str: %s\n", temp); // 이상없음
		line_number++;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	t_game	so_long;
	t_position	position;
	(void) ac;

	init_game(&so_long);
	init_position(&position);
	so_long.window = mlx_new_window(so_long.start, 500, 500, "so_long");
	init_map(av);
	mlx_hook(so_long.window, X_EVENT_KEY_PRESS, 0, &press_key, &position);
	mlx_loop(so_long.start);
	return (0);
}