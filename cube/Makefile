# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:27:10 by aartiges &        #+#    #+#              #
#    Updated: 2022/04/19 23:21:36 by aartiges         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               Présentation                                 ##
################################################################################

COLOR_NORM		=	\033[0m
COLOR_RED		=	\033[31m
COLOR_PURPLE	=	\033[35m

################################################################################
##                               SRCS                                         ##
################################################################################

MK = Makefile

# Headers

DIR_HDS				=	includes

RELATIVE_HDS		=	cub3D.h		\
						struct.h	\
						define.h	\
						includes.h

# Code

DIR_GLOBAL						=	srcs
SRC_GLOBAL						=	main.c				\
									reinit_display.c

DIR_PARSING						=	srcs/parsing
SRC_PARSING						=	gnl.c			\
									pars_color.c	\
									parsing.c		\
									parsing_util.c		\
									pars_line.c		\
									pars_map.c		\
									pars_texture.c	\
									utils.c			

DIR_ERROR						=	srcs/error
SRC_ERROR						=	alloc.c

DIR_MINI_MAP					=	srcs/minimap
SRC_MINI_MAP					=	draw_mini_map.c			\
									ft_bg_map.c

DIR_PLAYER						=	srcs/player
SRC_PLAYER						=	player.c

DIR_DRAW						=	srcs/draw
SRC_DRAW						=	draw.c		\
									draw_img.c

DIR_EVENT						=	srcs/event
SRC_EVENT						=	event.c		\
								mouse.c		\
								key.c		\
								key_status.c	\
								init_collision.c\
								move_player.c	\
								move_player1.c

DIR_RAY							=	srcs/raycasting
SRC_RAY							=	raycasting.c		\
									raycasting1.c		\
									h_raycasting.c		\
									v_raycasting.c		\
									size_wall.c			\
									extremum_wall.c		\
									origin_walls.c		\
									math.c

DIR_TEXTURE						=	srcs/texture
SRC_TEXTURE						=	texture_img.c		\
									opti_img.c			\
									walls.c				\
									walls2.c			\
									init_start_walls.c	


################################################################################
##                       Compilation Environnement                            ##
################################################################################

NAME	=	cub3D
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -O3
# -g3 -ggdb -fsanitize=address

# Library

LIBS = -Llibft -lft

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		DIR_MLX	= mlx_linux
		MLX		= $(DIR_MLX)/libmlx_Linux.a 
		LIBS	+= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 \
				-lm -lz
	endif
	ifeq ($(UNAME_S),Darwin)
		DIR_MLX	= mlx
		MLX		= $(DIR_MLX)/libmlx.a
		LIBS	+= -Lmlx -lmlx -framework OpenGL -framework AppKit
	endif

# libft

DIR_LIBFT			= 	libft
LIBFT_NAME			=	$(DIR_LIBFT)/libft.a

# Sources

DIRS_SRC			=	$(DIR_ERROR)		\
						$(DIR_PARSING) 		\
						$(DIR_TEXTURE) 		\
						$(DIR_MINI_MAP)		\
						$(DIR_PLAYER)		\
						$(DIR_DRAW)		\
						$(DIR_EVENT)		\
						$(DIR_RAY)		\
						$(DIR_GLOBAL)

DIR_OBJ				=	obj

SRCS		=	$(addprefix $(DIR_GLOBAL)/, $(SRC_GLOBAL))					\
				$(addprefix $(DIR_PARSING)/, $(SRC_PARSING))				\
				$(addprefix $(DIR_TEXTURE)/, $(SRC_TEXTURE))				\
				$(addprefix $(DIR_ERROR)/, $(SRC_ERROR))				\
				$(addprefix $(DIR_PLAYER)/, $(SRC_PLAYER))				\
				$(addprefix $(DIR_DRAW)/, $(SRC_DRAW))					\
				$(addprefix $(DIR_EVENT)/, $(SRC_EVENT))				\
				$(addprefix $(DIR_RAY)/, $(SRC_RAY))					\
				$(addprefix $(DIR_MINI_MAP)/, $(SRC_MINI_MAP))

HDS			=	$(addprefix $(DIR_HDS)/, $(RELATIVE_HDS))
OBJS		=	$(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))

DEPENDS		=	$(HDS) $(MK) $(LIBFT_NAME) $(MLX)

################################################################################
##                                 Règles                                     ##
################################################################################

all		:	$(NAME)
bonus	:	$(NAME)

define src2obj
$(DIR_OBJ)/$(1)/%.o:	$(1)/%.c $(2)
	@mkdir -p $(DIR_OBJ)/$(1)
	@printf "\r\033[K\tCompilation of $(COLOR_PURPLE)$$< ==> $$@\$(COLOR_NORM)"
	@$(CC) $(CFLAGS) -c -o $$@ $$< $(INC_INC)
endef

$(foreach dir,$(DIRS_SRC),$(eval $(call src2obj,$(dir), $(DEPENDS))))

$(NAME)	: $(DEPENDS) $(OBJS)
	@printf "\n\tCompilation of $(COLOR_PURPLE)$(NAME)\$(COLOR_NORM)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT_NAME):
	@printf "\n\tCompilation of $(COLOR_PURPLE)$(LIBFT_NAME)\$(COLOR_NORM)\n"
	@make --quiet -C $(DIR_LIBFT)

$(MLX):
	@printf "\n\tCompilation of $(COLOR_PURPLE)$(MLX)\$(COLOR_NORM)\n"
	@make --quiet -C $(DIR_MLX) 2>/dev/null

l_clean:
	@printf "\tDelete $(COLOR_RED)$(DIR_OBJ)/$(COLOR_NORM) of $(NAME)\n"
	@rm -rf $(DIR_OBJ)

clean:	l_clean
	@printf "\tDelete $(COLOR_RED)object of $(DIR_LIBFT)$(COLOR_NORM) of $(NAME)\n"
	@make --quiet -C $(DIR_LIBFT) clean
	@printf "\tDelete $(COLOR_RED)object of $(DIR_MLX)$(COLOR_NORM) of $(NAME)\n"
	@make --quiet -C $(DIR_MLX) clean >/dev/null

fclean:	l_clean
	@printf "\tDelete $(COLOR_RED)all binary on $(DIR_LIBFT)$(COLOR_NORM)\n"
	@make --quiet -C $(DIR_LIBFT) fclean
	@printf "\tDelete $(COLOR_RED)all binary on $(DIR_MLX)$(COLOR_NORM)\n"
	@make --quiet -C $(DIR_MLX) clean >/dev/null
	@printf "\tDelete $(COLOR_RED)$(NAME)$(COLOR_NORM)\n"
	@rm -rf $(NAME)

xclean:
	@rm -rf $(NAME)

re:	fclean all

norm:
	@make -C $(DIR_LIBFT) norm || true
	@norminette	$(HDS) $(SRCS) $(SRCS_BONUS) || true
