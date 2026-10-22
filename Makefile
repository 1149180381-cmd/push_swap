NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -I./printf -I./printf/libft

LIBRARY         = push_swap.a
BONUS_LIBRARY   = checker.a
LIBFTPRINTF     = ./printf/libftprintf.a

SRCS = argv_checker.c \
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
       benchmark_helper.c \
       ft_split_mod.c \
       argv_filter.c

BONUS_SRCS = get_next_line.c utils_bonus.c checker.c

OBJS            = $(SRCS:.c=.o)
BONUS_OBJS      = $(BONUS_SRCS:.c=.o)
OBJS_NO_MAIN    = $(filter-out main.o,$(OBJS))

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFTPRINTF):
	$(MAKE) -C ./printf

$(LIBRARY): $(OBJS) $(LIBFTPRINTF)
	cp $(LIBFTPRINTF) $@
	ar rcs $@ $(OBJS)

$(BONUS_LIBRARY): $(OBJS_NO_MAIN) $(BONUS_OBJS) $(LIBFTPRINTF)
	cp $(LIBFTPRINTF) $@
	ar rcs $@ $(OBJS_NO_MAIN) $(BONUS_OBJS)

$(NAME): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBRARY) -o $@

$(BONUS_NAME): $(BONUS_LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_LIBRARY) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(LIBRARY) $(BONUS_LIBRARY)
	$(MAKE) -C ./printf clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C ./printf fclean

re: fclean all

.PHONY: all bonus clean fclean re
