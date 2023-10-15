# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = libft.a

INCLUDE = -I.

SRCDIR = ./
SRCS = ft_calloc.c
SRCS += ft_isdigit.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_strlen.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	ar r $@ $^

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
