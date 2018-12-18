make -C libft/ fclean && make -C libft/
gcc -Wall -Werror -Wextra -fsanitize=address -I libft/includes get_next_line.c get_next_line.h main.c libft/libft.a
./a.out test/test.txt