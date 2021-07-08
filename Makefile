NAME = a.out
FOLDER = get_next_line/
FILES = $(FOLDER)get_next_line.h $(FOLDER)get_next_line.c $(FOLDER)get_next_line_utils.c
TEST = main.c
LIB = libft/libft.a
FLAGS = -g -Wall -Wextra -Werror
BUFFER = -D BUFFER_SIZE=2
CC = gcc


run : $(NAME)
	./a.out 
re : 
	$(CC) $(BUFFER)  $(FLAGS) $(FILES)  $(TEST) $(LIB)
	./a.out	

debug : $(NAME)
	gdb ./a.out

$(NAME) : $(FILES) $(TEST)
	$(CC) $(BUFFER)  $(FLAGS) $(FILES)  $(TEST) $(LIB)
	