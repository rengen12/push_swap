.PHONY:		all clean fclean re $(NAME1) $(NAME2)

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
NAME1 =			push_swap
NAME2 =			checker
HEADER =		-I ./
SRC0 =			stack1.c stack2.c stack3.c interface.c get_next_line.c \
				old_func.c ft_strjoin_fr_frst.c
SRC1 =			push_swap.c mysort.c
SRC2 =			checker.c
OBJFOLD =		./obj/
LIBFOLD =		./libft/
PRINTFFOLD =	./ft_printf/
LIBFT =			-L. libft/libft.a
PRINTFLIB =		-L. ft_printf/libftprintf.a
OBJ0 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC0)))
OBJ1 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC1)))
OBJ2 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC2)))

all:			$(NAME1) $(NAME2)

$(NAME1):		$(OBJ0) $(OBJ1) $(NAME2)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ0) $(OBJ1) $(LIBFT) $(PRINTFLIB)
	@echo "push_swap: done"

$(NAME2):		$(OBJ2)
	@make -C $(LIBFOLD) -f Makefile
	@make -C $(PRINTFFOLD) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ0) $(OBJ2) $(LIBFT) $(PRINTFLIB)
	@echo "checker: done"

$(OBJFOLD)%.o:	%.c
	@mkdir -p $(OBJFOLD)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBFOLD) -f Makefile clean
	@make -C $(PRINTFFOLD) -f Makefile clean
	@echo "Objects removed"

fclean:			clean
	@rm -f $(NAME1)
	@make -C $(LIBFOLD) -f Makefile fclean
	@make -C $(PRINTFFOLD) -f Makefile fclean
	@echo "push_swap binary removed"
	@echo "checker binary removed"

re:				fclean all
