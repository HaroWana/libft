NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc

SRCDIR = srcs/
OBJDIR = objs/

FCTS = ft_atoi.c            ft_bzero.c           ft_calloc.c \
       ft_chained_lst.c     ft_chained_lst2.c    ft_is.c \
       ft_itoa.c            ft_memchr.c          ft_memcmp.c \
       ft_memcpy.c          ft_memmove.c         ft_memset.c \
       ft_put_fd.c          ft_put_fd.c          ft_split.c \
       ft_strchr.c          ft_strdup.c          ft_striteri.c \
       ft_strjoin.c         ft_strlcat.c         ft_strlcpy.c \
       ft_strlen.c          ft_strmapi.c         ft_strncmp.c \
       ft_strnstr.c         ft_strchr.c          ft_strtrim.c \
       ft_substr.c          ft_tolower.c         ft_toupper.c 

SRCS = $(addprefix $(SRCDIR),$(FCTS))
OBJS = $(addprefix $(OBJDIR),$(notdir $(FCTS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rmdir $(OBJDIR) || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re
