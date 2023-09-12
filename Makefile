NAME		=	cub3D
CC			=	cc
CFLAGS		=	
SOURCE		=	main.c
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
	$(MAKE) -C mlx clean
	$(MAKE) -C mlx clean

fclean		:	clean
	$(MAKE) -C mlx fclean
	$(MAKE) -C mlx fclean

re			:	fclean all

.PHONY		:	all clean fclean re 