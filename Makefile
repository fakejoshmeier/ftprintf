# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 14:06:03 by jmeier            #+#    #+#              #
#    Updated: 2017/11/30 18:12:29 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf \
		parse_flags parse_flags2 int_cast h_cast hh_cast l_cast ll_cast j_cast \
		z_cast

LIBFT = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_strstr \
		ft_isdigit ft_isprint ft_itoa ft_itoa_base ft_lstadd ft_lstdel \
		ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc ft_memccpy \
		ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset \
		ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr \
		ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr \
		ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter \
		ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
		ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr \
		ft_strrchr ft_strsplit ft_strsub ft_strtrim ft_tolower ft_toupper \
		ft_isspace ft_sqrt ft_lstnodecheck get_next_line ft_free ft_realloc \
		ft_putnbr_base ft_putnbr_base_fd ft_putnbr_base_lc ft_putunbr_base \
		ft_putllong_base_fd ft_putllong_base_lc ft_putlong_base_fd \
		ft_putlong_base_lc ft_putullong_base_fd ft_putulong_base_fd \
		ft_putunbr_base_fd ft_putunbr_base_lc

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

LIB_LOC = libft/src/
LIB_NAM = $(addsuffix .c, $(LIBFT))
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES) $(LIBFT))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

H_LOCS = -I inc/ -I libft/inc/

C_FLAGS = -Wall -Werror -Wextra

all:  $(NAME)

$(NAME):$(O_SRC)
	@echo Compiling $@ library...
	@ar rcs $@ $(O_SRC)
	@ranlib $(NAME)

$(O_LOC)%.o: $(C_LOC)%.c
	@echo Re-compiling $< file...
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

$(O_LOC)%.o: $(LIB_LOC)%.c
	@echo Re-compiling $< file...
	@gcc $(C_FLAGS) $(H_LOCS) -o $@ -c $<

clean:
	@echo Cleaning .o files ...
	@/bin/rm -rf $(O_SRC)
	@echo ... Successfully removed .o files

fclean: clean
	@echo Cleaning $(NAME) ...
	@/bin/rm -f $(NAME)
	@echo ...Successfully removed $(NAME)

re: fclean all

.PHONY: all test clean fclean re