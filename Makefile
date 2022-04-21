NAME 	= 	push_swap
FILES	= 	creation_stack	\
			errors			\
			tools_swap_push \
			tools_rotate	\
			push_swap		\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIR)
HEADERS = -I$(LIBFT_DIR) 
.c.o		:
				${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} 	:	$(LIBFT) ${OBJS}
				@${CC} ${CFLAGS} ${LIBRARIES} ${OBJS} -o $@
				@echo "\033[32mPush_swap Compiled !\n"

$(LIBFT)	:	
				@echo "\033[32m<< Compiling ... >>\033[33;1m"
				@$(MAKE) -C $(LIBFT_DIR)
				@echo "\033[32mLibft Compiled !\n\033[33;1m"

all			:	${NAME}

clean		:	
				@echo "\033[32m<< clean process ... >>\033[33;1m"
				@rm -rf ${OBJS} ${OBJS_B}
				@$(MAKE) clean -C $(LIBFT_DIR)
				@echo "\033[32;1mDeleting all '.o' files !\n"

fclean 		:	clean
				@echo "\033[32m<< fclean process ... >>\033[33;1m"
				@rm -rf ${NAME}
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@echo "\033[32;1mDeleting everything !\n"

re 			:	fclean all
				@echo "\033[32;1mReset made !\n"

.PHONY		: re all bonus clean fclean libft
