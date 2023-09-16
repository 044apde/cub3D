NAME		=	cub3D
CC			=	cc
CFLAGS		=	
SOURCE		=	main.c \
				src/parse_map/parse_map.c src/parse_map/utils1.c src/parse_map/utils2.c\
				src/utils/error.c src/utils/string.c\
				src/gnl/get_next_line.c
HEADER		=	cub3d.h
LIBRARY 	=	libft/libft.a mlx/libmlx.a
OBJECT		=	$(SOURCE:.c=.o)

all			:	$(NAME)

$(NAME)	:	$(OBJECT) $(LIBRARY) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJECT) $(LIBRARY)

$(OBJECT)	:	%.o:%.c
	$(CC) $(CFLAGS) -c $(CFALG) $< -o $@

$(LIBRARY):
	$(MAKE) -C libft
	$(MAKE) -C mlx

clean		:
	rm -rf $(NAME) $(OBJECT)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean

fclean		:	clean
	$(MAKE) -C libft fclean

re			:	fclean all

.PHONY		:	all clean fclean re 