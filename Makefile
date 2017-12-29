.PHONY:		all clean fclean re $(NAME1) $(NAME2)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap
NAME2 = checker
HEADER = -I ./
SRC1 = main.c stack.c
# SRC2 =
OBJFOLD = ./obj/
LIBFOLD = ./libft/
LIBFT = -L. libft/libft.a
OBJ1 = $(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC1)))
# MKOBJ2 = $(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC2)))
# OBJ1 = $(addprefix $(OBJFOLD), $(SRC1:.c=.o))
# OBJ2 = $(addprefix $(OBJFOLD), $(SRC2:.c=.o))

all: 		    $(NAME1)

$(NAME1):	    $(OBJ1)
	@make -C $(LIBFOLD) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIBFT)
	@echo "push_swap: done"

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
