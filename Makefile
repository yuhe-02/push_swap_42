SRCS			=	push_swap.c \
					libft/ft_split.c libft/ft_strchr.c libft/ft_lstpop.c \
					libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_lstsize.c \
					libft/ft_substr.c libft/ft_isdigit.c libft/ft_lstpoplast.c \
					libft/ft_strcmp.c libft/ft_simpleatoi.c \
					libft/ft_itoa.c libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstnew.c \
					utils/arrays.c utils/error.c utils/cross.c \
					utils/control.c utils/pattern_three.c utils/control2.c \
					utils/pattern_four.c utils/look_for_position.c utils/look_for_position2.c \
					utils/pattern_five.c utils/precure_sort.c \

OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -Iincludes/.
CFLAGS			= -Iincludes/.

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re