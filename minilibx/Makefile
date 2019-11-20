#
#

NOM=libmlx.a
MAKEFLAGS+= --silent
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: MINILIB $(NOM)

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling Minilibx\033[0m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing File Minilib\033[0m"

re: clean all

MINILIB:
			@echo "	,    _,     _, ,  _,  _ __,"
			@echo "	|\/| | |\ | | |   |   | |_)"
			@echo "	|  | | | \| | |__ | , | |_)"
			@echo "	~~~  ~ ~~~  ~ ~~  ~   ~ ~  "
			@echo ""
