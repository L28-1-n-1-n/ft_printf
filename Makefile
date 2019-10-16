# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 18:11:40 by hlo               #+#    #+#              #
#    Updated: 2019/08/27 04:40:48 by hlo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra -g

CC = gcc

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

SRCS = ft_printf.c count_arg.c parse.c parse_arg.c big_int.c \
			coms.c treat_arg.c treat_arg_helper.c treat_arg_helper_two.c string_hex.c \
			string_digit.c decode_float.c add_modifier.c add_unsigned_modifier.c ft_itoamax.c \
			big_int_80.c print_float_str.c float_special.c sub_array.c sub_array_80.c \
			print_e_str.c print_g_str.c string_bin.c treat_time.c check_buff.c \
			format_final.c alter_format.c parse_arg_helper.c helper_hex_one.c helper_hex_two.c\
			helper_hex_snippet.c convert_base.c test_array.c print_result_helper.c \
			decode_float_helper.c decode_float_helper_two.c sub_array_helper.c


HEAD = printf.h

LIBFT = libft/libft.a

HEADP = $(addprefix $(INCDIR)/, $(HEAD))
OBJP = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCP = $(foreach dir, $(INCDIR), -I$(dir))

BLACK =	\033[0;30m
RED =	\033[0;31m
GREEN =	\033[0;32m
YELLOW =\033[0;33m
BLUE =	\033[0;34m
PURPLE =\033[0;35m
CYAN =	\033[0;36m
WHITE =	\033[0;37m
RESET=	\033[0m

.PHONY : clean fclean re all

all: $(LIBFT) $(OBJDIR) $(NAME)

re: fclean all

$(LIBFT):
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	    $(CC) $(FLAGS) -c -o $@ $< -I$(LIBFT) $(INCP)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@echo "$(GREEN)All object files in ft_printf are now deleted\n$(RESET)"

fclean:
	@make fclean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(NAME)
	@echo "$(YELLOW)All object and binary files in ft_printf are now deleted\n$(RESET)"

$(NAME): $(LIBFT) $(OBJDIR) $(OBJP)
#	$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	#	    $(CC) $(FLAGS) -c -o $@ $< -I$(LIBFT) $(INCP)

#	$(OBJDIR):
	#	mkdir -p $(OBJDIR)


#	$(CC) $(FLAGS) -o $@ $^ -I$(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJP)
	ranlib $(NAME)
	@echo "$(PURPLE)ft_printf has now been built.\n$(RESET)"
