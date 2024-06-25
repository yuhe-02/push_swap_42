SRCS			=	push_swap.c \
					libft/ft_split.c libft/ft_strchr.c \
					libft/ft_strlcpy.c libft/ft_strlen.c \
					libft/ft_substr.c libft/ft_isdigit.c \
					libft/ft_strcmp.c libft/ft_simpleatoi.c \
					libft/ft_itoa.c libft/ft_lstadd_back.c \
					libft/ft_lstlast.c libft/ft_lstadd_front.c \
					libft/ft_lstnew.c \
					utils/arrays.c utils/error.c utils/cross.c\

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