# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amichak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 13:15:45 by amichak           #+#    #+#              #
#    Updated: 2017/11/15 19:41:01 by amichak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re $(NAME1) $(NAME2)

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
NAME1 =			push_swap
NAME2 =			checker
HEADER =		-I ./
SRC0 =			stack1.c stack2.c stack3.c interface.c is_sorted.c \
				error.c helpers.c
SRC1 =			push_swap.c sort3_1.c sort3_2.c opt_cmds.c myqsort.c \
				pushing_qsort.c pushing_qsort_addition.c select_sort.c
SRC2 =			checker.c
OBJFOLD =		./obj/
LIBFOLD =		./libft/
LIBFT =			-L. libft/libft.a
OBJ0 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC0)))
OBJ1 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC1)))
OBJ2 =			$(addprefix $(OBJFOLD), $(patsubst %.c, %.o, $(SRC2)))

all:			$(NAME1) $(NAME2)

$(NAME1):		$(OBJ0) $(OBJ1)
	@make -C $(LIBFOLD) -f Makefile
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ0) $(OBJ1) $(LIBFT)
	@echo "push_swap: done"

$(NAME2):		$(OBJ0) $(OBJ2)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ0) $(OBJ2) $(LIBFT)
	@echo "checker: done"

$(OBJFOLD)%.o:	%.c
	@mkdir -p $(OBJFOLD)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBFOLD) -f Makefile clean
	@echo "Objects removed"

fclean:			clean
	@rm -f $(NAME1) $(NAME2)
	@make -C $(LIBFOLD) -f Makefile fclean
	@echo "push_swap binary removed"
	@echo "checker binary removed"

re:				fclean all
