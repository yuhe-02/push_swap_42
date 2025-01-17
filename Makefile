SRCS			=	push_swap.c \
					libft/ft_split.c libft/ft_strchr.c libft/ft_lstpop.c \
					libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_lstsize.c \
					libft/ft_substr.c libft/ft_isdigit.c libft/ft_lstpoplast.c \
					libft/ft_strcmp.c libft/ft_simpleatoi.c \
					libft/ft_itoa.c libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstnew.c \
					utils/arrays.c utils/error.c utils/cross.c utils/error2.c \
					utils/control.c utils/pattern_three.c utils/control2.c \
					utils/pattern_four.c utils/look_for_position.c utils/look_for_position2.c \
					utils/pattern_five.c utils/precure_sort.c utils/optimize.c \
					utils/frees.c \

SRCS_BONUS		=	bonus/checker.c bonus/get_next_line.c \
					libft/ft_split.c libft/ft_strchr.c libft/ft_lstpop.c \
					libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_lstsize.c \
					libft/ft_substr.c libft/ft_isdigit.c libft/ft_lstpoplast.c \
					libft/ft_strcmp.c libft/ft_simpleatoi.c \
					libft/ft_itoa.c libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c libft/ft_strjoin_custom.c \
					libft/ft_lstnew.c libft/ft_strdup.c libft/ft_strndup.c \
					utils/arrays.c utils/error.c utils/cross.c utils/error2.c \
					utils/control.c utils/control2.c \
					utils/frees.c \


OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -Iincludes/. -g -fsanirize=address
CFLAGS			= -Iincludes/.

NAME			= push_swap
NAME_BONUS		= checker

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS):	${OBJS_BONUS}
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)


clean:
				$(RM) $(OBJS) 
				$(RM) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)

re:				fclean $(NAME)

bonus:			${NAME_BONUS}

.PHONY:			all clean fclean re