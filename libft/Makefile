# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/12 21:56:14 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2019/11/19 17:06:45 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
# **************************************************************************** #
#								VARIABLES									   #
# **************************************************************************** #

HEADER		=	includes/

SRC_PATH	=	sources

SRCS_NAME	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
				ft_strdup.c	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
				ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putchar.c ft_putstr.c ft_putnbr.c \
				ft_lstnew.c ft_lstlast.c ft_lstadd_front.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstsize.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				ft_strnew.c get_next_line.c ft_to_string.c ft_strjoin_free.c \
				ft_itoa_base.c ft_putaddr.c ft_strlower.c ft_longlonglen.c \
				ft_tohexhigh_fd.c ft_tohexlow_fd.c ft_strdupnb.c ft_hexlen.c \
				ft_intlen.c ft_putjoinfree.c ft_have.c \
				ft_printf.c ft_printf_print.c ft_printf_parse.c \
				ft_printf_assign.c ft_print_string.c ft_print_nb.c\
				ft_print_flag.c ft_printf_bool.c \

SRCS 		= 	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

OBJS		= 	${SRCS:.c=.o}

NAME		= 	libft.a

RM			= 	rm -f

FLAGS 		= 	-Wall -Wextra -Werror

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #


all:		LIBFT $(NAME)

%.o: %.c 	$(HEADER)
			@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
			@gcc $(FLAGS)  -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling the library\033[0m"
			@ar rcs $(NAME) $(OBJS)

clean:
			@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
			@$(RM) $(OBJS)

fclean:		clean
			@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m"
			@$(RM) $(NAME)

re:			fclean all

LIBFT:
			@echo "	_,  _ __, __, ___"
			@echo "	|   | |_) |_   | "
			@echo "	| , | |_) |    | "
			@echo "	~~~ ~ ~   ~    ~ "
			@echo ""

COFEE:
			@echo "\n"
			@echo "             (         ) "
			@echo "	              )        ("
			@echo "               ___)...----)----....___"
			@echo '           .-""      )    (           ""-.'
			@echo "      .-''''|-._      (       )        _.-|"
			@echo '     /  .--.|   `""---...........---""`   |'
			@echo "    /  /    |                             |"
			@echo "    |  |    |                             |"
			@echo "     \  \   |                             |"
			@echo "      '\ '\ |                             |"
			@echo "        '\ '|                             |"
			@echo "        _/ /\                             /"
			@echo "       (__/  \                           /"
			@echo '    _..---""` \                         /`""---.._'
			@echo " .-'           \                       /          '-."
			@echo ":               '-.__             __.-'              :"
			@echo ':                  ) ""---...---"" (                :'
			@echo "\'._                '"--...___...--"'              _.'"
			@echo '   \""--..__                              __..--""/'
			@echo "     '._     """----.....______.....----"""         _.'"
			@echo '         ""--..,,_____            _____,,..--"""'''
			@echo '                      """------"""'

.PHONY: 	clean fclean
