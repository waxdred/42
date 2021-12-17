CCEND =   \033[0m
CCYAN =   \033[34m
CGREEN=   \033[33m



NAME = 	  libft.a

CC = 	  gcc

SRC =     convert/ft_atoi.c	   	\
	  convert/ft_atoi_base.c   	\
	  convert/ft_itoa.c 	   	\
	  isa/ft_isalnum.c	   	\
	  isa/ft_isalpha.c	   	\
	  isa/ft_isascii.c	   	\
	  isa/ft_isdigit.c	   	\
	  isa/ft_isprint.c	   	\
	  lst/ft_lstadd_back.c 		\
	  lst/ft_lstadd_front.c		\
	  lst/ft_lstclear.c    		\
	  lst/ft_lstdelone.c   		\
	  lst/ft_lstiter.c     		\
	  lst/ft_lstlast.c     		\
	  lst/ft_lstmap.c      		\
	  lst/ft_lstnew.c		\
	  lst/ft_lstsize.c     		\
	  mem/ft_bzero.c	   	\
	  mem/ft_calloc.c      		\
	  mem/ft_strdup.c	   	\
	  mem/ft_memalloc.c	   	\
	  mem/ft_memchr.c	   	\
	  mem/ft_memcmp.c	   	\
	  mem/ft_memcpy.c	   	\
	  mem/ft_memmove.c	   	\
	  mem/ft_memset.c	   	\
	  mem/ft_memset.c	   	\
	  print/ft_putchar_fd.c  	\
	  print/ft_putendl_fd.c  	\
	  print/ft_putnbr_fd.c   	\
	  print/ft_putstr_fd.c   	\
	  str/ft_split.c       		\
	  str/ft_strchr.c	 	\
	  str/ft_strcpy.c	   	\
	  str/ft_striteri.c    		\
	  str/ft_strjoin.c		\
	  str/ft_strjoin.c	   	\
	  str/ft_strlcat.c	   	\
	  str/ft_strlcpy.c     		\
	  str/ft_strlen.c	   	\
	  str/ft_strmapi.c     		\
	  str/ft_strncmp.c	   	\
	  str/ft_strnstr.c	   	\
	  str/ft_strrchr.c	   	\
	  str/ft_strtrim.c     		\
	  str/ft_substr.c	   	\
	  str/ft_tolower.c	   	\
	  str/ft_toupper.c	   	\
      	  str/ft_strcpy.c

OBJS = $(SRC:.c=.o)

HEADER = include/libft.h

FLAGS = -Wall -Werror -Wextra

%.o : %.c $(HEADER)
	@-$(CC) $(FLAGS) -I ./includes -c $< -o $@
	@echo "$(CCYAN)$< --> $@ $(CGREEN)[✅]$(CCEND)"

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CCYAN)Creation of $(NAME)...$(CCEND)"
	@ar rc $(NAME) $(OBJS)

clean:
	@echo "$(CCYAN)Removal of $(NAME)...   ✅$(CCEND)"
	@-/bin/rm -f $(OBJS)

fclean: clean
	@echo "$(CCYAN)Removal of $(NAME)...   ✅$(CCEND)"
	@-/bin/rm -f $(NAME)

re: fclean all 

