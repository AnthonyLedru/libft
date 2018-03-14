# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 14:26:59 by aledru            #+#    #+#              #
#*   Updated: 2018/02/16 17:20:14 by aledru           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME := libft.a

INCLUDE_FOLDERS := -I includes/
SOURCES_FOLDER := srcs/
OBJECTS_FOLDER := objs/

vpath %.c srcs

FLAGS := -Wall -Werror -Wextra

SOURCES := \
		mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memccpy.c \
		mem/ft_memmove.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memalloc.c \
		mem/ft_memdel.c \
		str/ft_strlen.c \
		str/ft_strdup.c \
		str/ft_strcpy.c \
		str/ft_strncpy.c \
		str/ft_strcat.c \
		str/ft_strncat.c \
		str/ft_strlcat.c \
		str/ft_strstr.c \
		str/ft_strnstr.c \
		str/ft_strcmp.c \
		str/ft_toupper.c \
		str/ft_tolower.c \
		str/ft_strchr.c \
		str/ft_strncmp.c \
		str/ft_strrchr.c \
		str/ft_strnew.c \
		str/ft_strdel.c \
		str/ft_strclr.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strmap.c \
		str/ft_strmapi.c \
		str/ft_strequ.c \
		str/ft_strnequ.c \
		str/ft_strsub.c \
		str/ft_strjoin.c \
		str/ft_strtrim.c \
		str/ft_strtrim.c \
		str/ft_strsplit.c \
		char/ft_isblank.c \
		char/ft_islower.c \
		char/ft_isupper.c \
		char/ft_isspace.c \
		char/ft_isxdigit.c \
		char/ft_isalpha.c \
		char/ft_isdigit.c \
		char/ft_isalnum.c \
		char/ft_isascii.c \
		char/ft_isprint.c \
		put/ft_putchar.c \
		put/ft_putchar_fd.c \
		put/ft_putstr.c \
		put/ft_putendl.c \
		put/ft_putnbr.c \
		put/ft_putstr_fd.c \
		put/ft_putendl_fd.c \
		put/ft_putnbr_fd.c \
		lst/ft_lstnew.c \
		lst/ft_lstdelone.c \
		lst/ft_lstdel.c \
		lst/ft_lstadd.c \
		lst/ft_lstiter.c \
		lst/ft_lstmap.c \
		others/ft_htoi.c \
		others/ft_atoi.c \
		others/ft_itoa.c \
		others/get_next_line.c \
		num/ft_abs.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_dprintf.c \
		ft_printf/ft_error.c \
		ft_printf/ft_env.c \
		ft_printf/ft_env_setters.c \
		ft_printf/ft_put.c \
		ft_printf/ft_parser.c \
		ft_printf/ft_arg_cast.c \
		ft_printf/ft_conversion_selector.c \
		ft_printf/ft_string_conversion.c \
		ft_printf/ft_number_conversion.c \
		ft_printf/ft_char_conversion.c \
		ft_printf/ft_base_converter.c \
		ft_printf/ft_unicode.c \


OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED := NO

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\n$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@ar rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)\n"

objs/%.o: %.c
	@if [ "$(HEADER_PRINTED)" = "NO" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)------------ LIBFT -------------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
		$(eval HEADER_PRINTED := YES) \
	fi
	@mkdir -p $(dir $@)
	@if [ "$(notdir $<)" = "ft_printf.c" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)---------- FT_PRINTF -----------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
	fi
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)libft : Objects removed$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)libft : Library removed$(NO_COLOR)\n"

re:
	@make fclean
	@make

.PHONY: all re clean fclean header
