LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		sources/ft_treatment.c \
		sources/ft_treat_width.c \
		sources/ft_u_itoa.c \
		sources/ft_u_dec_to_hexa.c \
		sources/ft_putchar.c \
		sources/ft_str_tolower.c \
		sources/ft_putstr.c \
		sources/ft_treat_string.c \
		sources/ft_treat_char.c \
		sources/ft_treat_pointer.c \
		sources/ft_treat_int.c \
		sources/ft_treat_uint.c \
		sources/ft_treat_percent.c \
		sources/ft_treat_hexa.c \
		sources/ft_treat_flags.c 

HEADER = includes/ft_printf.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I./includes

OBJS = $(SRCS:%.c=%.o) 

all : make_libft $(NAME)

make_libft : 
	$(MAKE) -C ./libft

${LIBFT} : make_libft

%.o : %.c ${HEADER}
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) ${LIBFT}
	cp ${LIBFT} $(NAME)
	ar -rcs $(NAME) $(OBJS)

norme :
	norminette sources includes ft_printf.c libft

bonus : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

PHONY : all make_libft norme bonus clean fclean re 