
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = ft_caib.c \
       ft_is.c \
       ft_mem.c \
       ft_str1.c \
       ft_str2.c \
       ft_str3.c \
       ft_split.c \
       ft_to.c \
       ft_put_fd.c 

OBJS = $(FCTS:.c=.o)

BONUS_FCTS = ft_lst_bonus.c \
	     ft_lst2_bonus.c

BONUS_OBJS = $(BONUS_FCTS:.c=.o)

NAME = libft.a

$(NAME): $(OBJS)
	@$(AR) $@ $^

all: $(NAME)

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $@ $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re
