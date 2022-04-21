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
				${CC} ${CFLAGS} ${LIBRARIES} ${OBJS} -o $@

$(LIBFT)	:	
				$(MAKE) -C $(LIBFT_DIR)

all			:	${NAME}

clean		:	
				rm -rf ${OBJS} ${OBJS_B}
				$(MAKE) clean -C $(LIBFT_DIR)

fclean 		:	clean
				rm -rf ${NAME}
				$(MAKE) fclean -C $(LIBFT_DIR)
re 			:	fclean all

.PHONY		: re all bonus clean fclean libft
