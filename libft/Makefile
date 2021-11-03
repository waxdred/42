NAME = libft.a

SRC = ft_memset.c	\
      	  ft_strcpy.c	\
	  ft_bzero.c	\
	  ft_memcpy.c	\
	  ft_memmove.c	\
	  ft_memcmp.c	\
	  ft_strlen.c	\
	  ft_strdup.c	\
	  ft_strcpy.c	\
	  ft_strlcat.c	\
	  ft_strchr.c	\
	  ft_strrchr.c	\
	  ft_strnstr.c	\
	  ft_strncmp.c	\
	  ft_atoi.c	\
	  ft_isalpha.c	\
	  ft_isdigit.c	\
	  ft_isalnum.c	\
	  ft_isascii.c	\
	  ft_isprint.c	\
	  ft_toupper.c	\
	  ft_tolower.c	\
	  ft_strjoin.c	\
	  ft_strjoin.c	\
	  ft_memalloc.c	\
	  main.c

FILEO = $(SRC:.c=.o)

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I ./includes
	ar rc $(NAME) $(FILEO)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(FILEO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

