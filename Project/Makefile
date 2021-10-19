GCCW = gcc -Wall -Wextra -Werror
NAME = bsq
INCL = includes/head.h
SRCS = src/main.c \
	   src/ft_valid_map.c \
	   src/ft_read_map.c \
	   src/ft_solution.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(GCCW) $? -o $(NAME)

%.o:
	$(GCCW) -c $(@:.o=.c) -o $@

clean:
	rm $(NAME)

fclean: clean
	rm $(OBJS)

re: fclean all

.PHONY: all clean fclean re
