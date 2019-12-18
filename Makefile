# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/20 13:23:24 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2019/12/18 16:54:15 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
# **************************************************************************** #
#								VARIABLES									   #
# **************************************************************************** #

HEAD_PATH	=					includes

HEAD_NAME	=					ft_cube3d_define.h ft_cube3d_header.h \
								ft_cube3d_struct.h ft_cube3d.h

HEADER		=					$(addprefix $(HEAD_PATH)/,$(HEAD_NAME))

MINILIBX	=					libmlx.a

MINILIBXS	=					minilibx/libmlx.a

LIB			=					libft.a

LIBS		=					libft/libft.a

SRC_PATH	=					sources

SRCS_NAME	= 					main.c map.c error.c key.c bool.c init_struct.c \
								parse_map.c utils.c raycasting.c draw.c \
								ft_move_player.c init_textur.c sprite.c \
								sprite_casting.c \

OBJS		= 					${SRCS:.c=.o}

NAME		= 					Cube3D

RM			= 					rm -f

FLAGS 		= 					-Wall -Wextra -Werror -g3 -fsanitize=address

GFLAGS 		=					-lmlx -framework OpenGL -framework AppKit

SRCS 		= 					$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all:							$(MINILIBX) $(LIB) CUBE $(NAME)

%.o: %.c 						$(HEADER) $(LIBS) $(MINILIBXS)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc $(FLAGS) -c $< -o $@

$(NAME):						$(OBJS) $(HEADER)
								@gcc $(FLAGS) $(OBJS) -L minilibx $(GFLAGS) $(LIBS) -o $(NAME) -lm
								@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Cube3D\033[0m"

$(MINILIBX) :
								@$(MAKE) -C minilibx all

$(LIB):
								@$(MAKE) -C libft all

clean:
								@$(MAKE) -C libft clean
								@$(MAKE) -C minilibx clean
								@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing ALL File object\033[0m"
								@$(RM) $(OBJS)

fclean:							clean
								@$(MAKE) -C libft fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[32m All is Removing\033[0m"
								@$(RM) $(NAME)

re:								fclean all

CUBE:
								@echo ---------------------------------------------
								@echo "	 __,,  ,__, __,  __   _ , "
								@echo "	|   |  ||_)|__   __| |  \ "
								@echo "	|__ |__||_)|__   __| |_ / "
								@echo "	~~   ~~ ~  ~~    ~~  ~~   "
								@echo ""

.PHONY: 						clean fclean
