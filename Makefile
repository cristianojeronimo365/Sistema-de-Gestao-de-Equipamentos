NAME= sistema_gestao
CC= cc
CFLAGS= -Wall -Wextra -Werror -Iinclude

SRCS= ./src/componentes.c ./src/empresas.c ./src/funcionarios.c\
		./src/main.c ./src/operacoes.c ./src/postos.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re