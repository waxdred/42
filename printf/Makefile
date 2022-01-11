NAME = libftprintf.a

CC = gcc

LIB =		libft/ft_atoi.c			\
		libft/ft_atoi_base.c		\
		libft/ft_bzero.c		\
		libft/ft_calloc.c		\
		libft/ft_conv_hex.c		\
		libft/ft_convert_base.c		\
		libft/ft_isalnum.c		\
		libft/ft_isalpha.c		\
		libft/ft_isascii.c		\
		libft/ft_isdigit.c		\
		libft/ft_isprint.c		\
		libft/ft_itoa.c			\
		libft/ft_lstadd_back.c		\
		libft/ft_lstadd_front.c		\
		libft/ft_lstclear.c		\
		libft/ft_lstdelone.c		\
		libft/ft_lstiter.c		\
		libft/ft_lstlast.c		\
		libft/ft_lstmap.c		\
		libft/ft_lstnew.c		\
		libft/ft_lstsize.c		\
		libft/ft_memalloc.c		\
		libft/ft_memchr.c		\
		libft/ft_memcmp.c		\
		libft/ft_memcpy.c		\
		libft/ft_memmove.c		\
		libft/ft_memset.c		\
		libft/ft_putchar.c		\
		libft/ft_putchar_fd.c		\
		libft/ft_putendl_fd.c		\
		libft/ft_putnbr.c		\
		libft/ft_putnbr_base.c		\
		libft/ft_putnbr_fd.c		\
		libft/ft_putnbr_unbase.c	\
		libft/ft_putnbr_unsigned.c	\
		libft/ft_putstr.c		\
		libft/ft_putstr_fd.c		\
		libft/ft_split.c		\
		libft/ft_strchr.c		\
		libft/ft_strcpy.c		\
		libft/ft_strdup.c		\
		libft/ft_striteri.c		\
		libft/ft_strlcat.c		\
		libft/ft_strlcpy.c		\
		libft/ft_strlen.c		\
		libft/ft_strmapi.c		\
		libft/ft_strncmp.c		\
		libft/ft_strnstr.c		\
		libft/ft_strrchr.c		\
		libft/ft_strtrim.c		\
		libft/ft_substr.c		\
		libft/ft_tolower.c		\
		libft/ft_toupper.c		

PRINTF = 	srcs/printf.c

FILEPO = $(PRINTF:.c=.o)

FILELO = $(LIB:.c=.o)

HEADERLIB   = /libft/libft.h
HEADERPRINT = /includes/ft_printf.h

FLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADERPRINT)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@

$(NAME): $(FILELO)
	ar rc $(NAME) $(FILELO) $(FILEPO)

all: $(NAME)

clean:
	/bin/rm -f $(FILELO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

