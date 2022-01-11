NAME = libft.a

CC = gcc

LIBPRINT= libft/lib_print/ft_putchar_fd.c  \
	  libft/lib_print/ft_putendl_fd.c  \
	  libft/lib_print/ft_putnbr_fd.c   \
	  libft/lib_print/ft_putstr_fd.c   

LIBSTR  = libft/lib_str/ft_atoi.c	 \
	  libft/lib_str/ft_isalpha.c	 \
	  libft/lib_str/ft_isascii.c	 \
	  libft/lib_str/ft_isdigit.c	 \
	  libft/lib_str/ft_isprint.c	 \
	  libft/lib_str/ft_itoa.c 	 \
	  libft/lib_str/ft_split.c       \
	  libft/lib_str/ft_strchr.c	 \
	  libft/lib_str/ft_striteri.c    \
	  libft/lib_str/ft_strjoin.c	 \
	  libft/lib_str/ft_strjoin.c	 \
	  libft/lib_str/ft_strlcat.c	 \
	  libft/lib_str/ft_strlcpy.c     \
	  libft/lib_str/ft_strlen.c	 \
	  libft/lib_str/ft_strmapi.c     \
	  libft/lib_str/ft_strncmp.c	 \
	  libft/lib_str/ft_strnstr.c	 \
	  libft/lib_str/ft_strrchr.c	 \
	  libft/lib_str/ft_strtrim.c     \
	  libft/lib_str/ft_substr.c	 \
	  libft/lib_str/ft_tolower.c	 \
	  libft/lib_str/ft_toupper.c	 \
	  libft/lib_str/ft_isalnum.c	 


LIBMEM  = libft/lib_mem/ft_bzero.c	 \
	  libft/lib_mem/ft_calloc.c      \
	  libft/lib_mem/ft_strdup.c	 \
	  libft/lib_mem/ft_memset.c	 \
	  libft/lib_mem/ft_memchr.c	 \
	  libft/lib_mem/ft_memcmp.c	 \
	  libft/lib_mem/ft_memcpy.c	 \
	  libft/lib_mem/ft_memmove.c	 \
	  libft/lib_mem/ft_memset.c	   

LIBLST  = libft/lib_lst/ft_lstadd_back.c \
	  libft/lib_lst/ft_lstadd_front.c\
	  libft/lib_lst/ft_lstclear.c    \
	  libft/lib_lst/ft_lstdelone.c   \
	  libft/lib_lst/ft_lstlast.c     \
	  libft/lib_lst/ft_lstmap.c      \
	  libft/lib_lst/ft_lstnew.c	 \
	  libft/lib_lst/ft_lstsize.c     \
	  libft/lib_lst/ft_lstiter.c     


PRINTO = $(LIBPRINT:.c=.o)
STRO = $(LIBSTR:.c=.o)
MEMO = $(LIBMEM:.c=.o)
LSTO = $(LIBLST:.c=.o)

HEADER = /libft/libft.h

FLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I ./includes -c $< -o $@


$(NAME): $(PRINTO) $(STRO) $(MEMO) $(LSTO)
	@echo "\033[36m"
	@ar rc $(NAME) $(PRINTO) $(STRO) $(MEMO) $(LSTO)
	@ls */*/*.o 2>/dev/null | cut -d '/' -f3- | sed 's/^/- ar rc libft.a /'


all: $(NAME)

clean:
	@echo "\033[91m"
	@ls */*/*.o 2>/dev/null | cut -d '/' -f3- | sed 's/^/rm -rf /'
	@/bin/rm -f $(PRINTO) $(STRO) $(MEMO) $(LSTO)

fclean: clean
	@echo "\033[91m"
	@/bin/rm -f $(NAME)
	@echo "Delete libft.a"

re: fclean all 
