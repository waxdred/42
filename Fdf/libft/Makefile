NAME = libft.a

CC = gcc

SRC =     ft_atoi.c	   \
	  ft_bzero.c	   \
	  ft_calloc.c      \
	  ft_count_words_sep.c\
	  ft_isalnum.c	   \
	  ft_isalpha.c	   \
	  ft_isascii.c	   \
	  ft_isdigit.c	   \
	  ft_isprint.c	   \
	  ft_itoa.c 	   \
	  ft_max.c 	   \
	  ft_memalloc.c	   \
	  ft_memchr.c	   \
	  ft_memcmp.c	   \
	  ft_memcpy.c	   \
	  ft_memmove.c	   \
	  ft_memset.c	   \
	  ft_memset.c	   \
	  ft_putchar_fd.c  \
	  ft_putchar.c     \
	  ft_putendl_fd.c  \
	  ft_putstr.c      \
	  ft_putnbr_fd.c   \
	  ft_putstr_fd.c   \
	  ft_split.c       \
	  ft_strchr.c	   \
	  ft_strcpy.c	   \
	  ft_strdup.c	   \
	  ft_striteri.c    \
	  ft_strjoin.c	   \
	  ft_strjoin.c	   \
	  ft_strsplit.c	   \
	  ft_strcat.c	   \
	  ft_strlcat.c	   \
	  ft_strlcpy.c     \
	  ft_strlen.c	   \
	  ft_strlen_sep.c  \
	  ft_strmapi.c     \
	  ft_strncmp.c	   \
	  ft_strnstr.c	   \
	  ft_strrchr.c	   \
	  ft_strtrim.c     \
	  ft_substr.c	   \
	  ft_tolower.c	   \
	  ft_toupper.c	   \
      	  ft_strcpy.c	   

FILESO = $(SRC:.c=.o)

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@

all: $(NAME)

$(NAME): $(FILESO)
	@echo "\033[34mCreation of $(NAME) ..."
	@ar rc $(NAME) $(FILESO)

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) ..."
	@-/bin/rm -f $(FILESO)

fclean: clean
	@echo "\033[33mRemoval of $(NAME) $(OUT) $(OBJS)..."
	@-/bin/rm -f $(NAME)

re: fclean all 

