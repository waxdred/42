CCEND 		=   \033[0m
CCYAN 		=   \033[34m
CGREEN		=   \033[33m
CCRED 		=   \033[31m
CCPURPLE 	=   \033[35m



NAME 	= 	  libft.a

CC 	= 	  gcc

SRC 	=     	convert/ft_atoi.c	   	\
		convert/ft_atoi_base.c   	\
		convert/ft_itoa.c 		\
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
		lst/ft_lstnew.c			\
		lst/ft_lstsize.c     		\
		mem/ft_bzero.c	   		\
		mem/ft_calloc.c      		\
		mem/ft_strdup.c	   		\
		mem/ft_strdupcat.c		\
		mem/ft_memalloc.c   		\
		mem/ft_memchr.c	   		\
		mem/ft_memcmp.c	   		\
		mem/ft_memcpy.c	   		\
		mem/ft_memmove.c	  	\
		mem/ft_memset.c	   	        \
		mem/ft_memset.c	   	        \
		mem/ft_freetab.c	  	\
		print/ft_putchar_fd.c  	        \
		print/ft_putendl_fd.c  		\
		print/ft_putnbr_fd.c   		\
		print/ft_putstr_fd.c   		\
		str/ft_split.c       		\
		str/ft_len_tab.c       		\
		str/ft_strsplit.c       	\
		str/ft_strchr.c	 		\
		str/ft_strcpy.c	   		\
		str/ft_striteri.c    		\
		str/ft_strjoin.c		\
		str/ft_strjoin.c	   	\
		str/ft_strlcat.c	   	\
		str/ft_strlcpy.c    		\
		str/ft_strlen.c	   		\
		str/ft_strmapi.c     		\
		str/ft_strncmp.c	   	\
		str/ft_strnstr.c	   	\
		str/ft_strrchr.c	   	\
		str/ft_strtrim.c     		\
		str/ft_substr.c	   		\
		str/ft_tolower.c	   	\
		str/ft_toupper.c	   	\
      		str/ft_strcpy.c

OBJS 	= $(SRC:.c=.o)

HEADER 	= include/libft.h

FLAGS 	= -Wall -Werror -Wextra

MK 	= Makefile

%.o : %.c $(HEADER) $(MK)
	@-$(CC) $(FLAGS) -I ./includes -c $< -o $@
	@printf "\r\t\033[K$(CCYAN)[✅]\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.05

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(NAME) $(OBJS)

clean:
	@printf "[✅]\t$(CCRED)Removal of Objects...$(CCEND)\n"
	@-/bin/rm -f $(OBJS)

fclean: clean
	@printf "[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(NAME)

re: fclean all 
