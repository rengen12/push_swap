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
LIBFT = ./libft/libft.a
OBJ1 = $(addprefix $(OBJFOLD), $(pathsubstr %.c, %.o, $(SRC1))) 
# OBJ2 = $(addprefix $(OBJFOLD), $(pathsubstr %.c, %.o, $(SRC2)))

all: 		$(NAME1)

 $(NAME1):	$(OBJ1)
	@make -C $(LIBDIR) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIBFT)
	@echo "push_swap: done"

$(OBJFOLD)%.o: %.c
	@mkdir -p $(OBJFOLD)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBDIR) -f Makefile clean

fclean: clean
	@rm -f $(NAME1)

re: fclean all
	@make -C $(LIBDIR) -f Makefile re
