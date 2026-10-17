NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = push_swap.a
INCLUDES = -I. -I./printf -I./printf/libft
LIBFTPRINTF = ./printf/libftprintf.a
SRCS =  argv_checker.c \
	base_operations.c \
	choose_algo.c \
	chunk_sort.c \
	fill_nodes.c \
	ft_atoi_vol2.c \
	indexing.c \
	main.c \
	push.c \
	radix_sort.c \
	reverse_rotate.c \
	rotate.c \
	selection_sort.c \
	swap.c \
	utils.c \
	small_sort.c \
	benchmark.c \
	benchmark_helper.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFTPRINTF):
	$(MAKE) -C ./printf

$(LIBRARY): $(OBJS) $(LIBFTPRINTF)
	cp $(LIBFTPRINTF) $(LIBRARY)
	ar rcs $(LIBRARY) $(OBJS)

$(NAME): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBRARY)
	$(MAKE) -C ./printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re test
