.PHONY:		all clean fclean re $(NAME1) $(NAME2)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap
NAME2 = checker
HEADER = -I ./
SRC0 = stack.c interface.c get_next_line.c old_func.c
SRC1 = push_swap.c mysort.c
SRC2 = checker.c
OBJFOLD = ./obj/
LIBFOLD = ./libft/
LIBFT = -L. libft/libft.a
OBJ0 = $(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC0)))
OBJ1 = $(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC1)))
OBJ2 = $(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC2)))
# OBJ1 = $(addprefix $(OBJFOLD), $(SRC1:.c=.o))
# OBJ2 = $(addprefix $(OBJFOLD), $(SRC2:.c=.o))

all:			$(NAME1) $(NAME2)

$(NAME1):		$(OBJ0) $(OBJ1) $(NAME2)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ0) $(OBJ1) $(LIBFT)
	@echo "push_swap: done"

$(NAME2):		$(OBJ2)
	@make -C $(LIBFOLD) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ0) $(OBJ2) $(LIBFT)
	@echo "checker: done"

$(OBJFOLD)%.o:  %.c
	@mkdir -p $(OBJFOLD)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBFOLD) -f Makefile clean
	@echo "Objects removed"

fclean:         clean
	@rm -f $(NAME1)
	@make -C $(LIBFOLD) -f Makefile fclean
	@echo "push_swap binary removed"
	@echo "checker binary removed"

re:             fclean all
