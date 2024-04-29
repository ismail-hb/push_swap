DEBUG	=	1

NAME	=	push_swap
INC_DIR	=	src
SRC_DIR	=	src
OBJ_DIR	=	obj
INC	  	=	$(addprefix $(INC_DIR)/,	push_swap.h)
SRC	  	=	$(addprefix $(SRC_DIR)/,	\
																		algorithm.c	\
																		push_swap.c		\
																		algorithm.c	\
																		movement.c	\
																		movement2.c	\
																		push_swap_utils.c	\
																		put_index.c)
OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_A =	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror
CINC	=	-I./libft -I
LLIB	=	-L./libft -lft -L

ifeq ($(DEBUG), 1)
	CFLAGS	+=	-g3 -fsanitize=address
endif

all: libft $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) $(LLIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CINC) -c $< -o $@

libft:
	make -C ./libft

re: fclean all

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

print:
	@echo "\n-------------------- FILES --------------------\n"
	@echo "NAME		$(NAME:%=\n%)\n"
	@echo "INC		$(INC:%=\n%)\n"
	@echo "SRC		$(SRC:%=\n%)\n"
	@echo "OBJ		$(OBJ:%=\n%)\n"
	@echo "\n-------------------- FLAGS --------------------\n"
	@echo "LLIB		$(LLIB:%=\n%)\n"
	@echo "LFLAGS	$(LFLAGS:%=\n%)\n"
	@echo "CFLAGS	$(CFLAGS:%=\n%)\n"
	@echo "CINC		$(CINC:%=\n%)\n"

.PHONY: all libft re clean fclean print
