NAME	= 	pipex

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

SRCS	= 	

CFILES	= $(SRCS:%=%.c)

$(NAME):
	$(CC) $(CFLAGS) $(CFILES) -L./includes -lft -o $(NAME)

# $(NAME):
# 	$(CC) $(CFLAGS) $(CFILES) -L./includes -lft_m2 -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all, clean, fclean, re
