
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = ft_atoi.c            ft_bzero.c           f_calloc.c \
       ft_chained_lst.c     ft_chained_lst2.c    ft_is.c \
       ft_itoa.c            ft_memchr.c          ft_memcmp.c \
       ft_memcpy.c          ft_memmove.c         ft_memset.c \
       ft_put_fd.c          ft_put_fd.c          ft_split.c \
       ft_strchr.c          ft_strdup.c          ft_striteri.c \
       ft_strjoin.c         ft_strlcat.c         ft_strlcpy.c \
       ft_strlen.c          ft_strmapi.c         ft_strncmp.c \
       ft_strnstr.c         ft_strchr.c          ft_strtrim.c \
       ft_substr.c          ft_tolower.c         ft_toupper.c

OBJS = $(FCTS:.c=.o)

BONUS_FCTS = ft_lst_bonus.c \
	     ft_lst2_bonus.c

BONUS_OBJS = $(BONUS_FCTS:.c=.o)

NAME = libft.a

$(NAME): $(OBJS)
	@$(AR) $@ $^

all: $(NAME)

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re
