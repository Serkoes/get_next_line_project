NAME = programm
FOLDER = get_next_line/
FILES = $(FOLDER)get_next_line.h $(FOLDER)get_next_line.c $(FOLDER)get_next_line_utils.c
TEST = main.c
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc


run : $(NAME)
	./a.out

debug : $(NAME)
	gdb ./a.out

$(NAME) : $(FILES) $(TEST)
	$(CC)  $(FLAGS) $(FILES)  $(TEST) $(LIB)
	