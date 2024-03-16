NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code
AR = ar rcs
RM = rm -rf

SRCS = ft_printf.c ft_put.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/
HEADER = libftprintf.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(HEADER)
	make bonus -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME) $(OBJS)
	@make fclean -C $(LIBFT)

re: fclean all

$(OBJS): libftprintf.h

.PHONY: clean fclean re all