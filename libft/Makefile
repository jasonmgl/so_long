# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:38:10 by jmougel           #+#    #+#              #
#    Updated: 2024/03/19 06:35:45 by jmougel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VAR**************************************#

NAME				=	libft.a

CC					=	gcc

CFLAGS				=	-Wall -Werror -Wextra -I include/ -I ../libft/include

HEADER				=	include/libft.h

RM					=	rm -rf

#DIR**************************************#

SRC_D				=	src/

OBJ_D				=	.obj/

FT_PRINTF_D			=	ft_printf/

OBJ_FT_PRINTF_D		=	.obj_ft_printf/

GNL_D				=	get_next_line/

OBJ_GNL_D			=	.obj.get_next_line/

LST_D				=	lst/

OBJ_LST_D			=	.obj_lst/


#SRCS*************************************#

SRC					=	${SRC_D}ft_atoi.c \
						${SRC_D}ft_bzero.c \
						${SRC_D}ft_calloc.c \
						${SRC_D}ft_isalnum.c \
						${SRC_D}ft_isalpha.c \
						${SRC_D}ft_isascii.c \
						${SRC_D}ft_isdigit.c \
						${SRC_D}ft_isprint.c \
						${SRC_D}ft_itoa.c \
						${SRC_D}ft_memchr.c \
						${SRC_D}ft_memcmp.c \
						${SRC_D}ft_memcpy.c \
						${SRC_D}ft_memmove.c \
						${SRC_D}ft_memset.c \
						${SRC_D}ft_putchar_fd.c \
						${SRC_D}ft_putendl_fd.c \
						${SRC_D}ft_putnbr_fd.c \
						${SRC_D}ft_putstr_fd.c \
						${SRC_D}ft_split.c \
						${SRC_D}ft_strchr.c \
						${SRC_D}ft_strdup.c \
						${SRC_D}ft_striteri.c \
						${SRC_D}ft_strjoin.c \
						${SRC_D}ft_strlcat.c \
						${SRC_D}ft_strlcpy.c \
						${SRC_D}ft_strlen.c \
						${SRC_D}ft_strmapi.c \
						${SRC_D}ft_strncmp.c \
						${SRC_D}ft_strnstr.c \
						${SRC_D}ft_strrchr.c \
						${SRC_D}ft_strtrim.c \
						${SRC_D}ft_substr.c \
						${SRC_D}ft_tolower.c \
						${SRC_D}ft_toupper.c

SRC_LST				=	${LST_D}ft_lstadd_back.c \
						${LST_D}ft_lstadd_front.c \
						${LST_D}ft_lstclear.c \
						${LST_D}ft_lstdelone.c \
						${LST_D}ft_lstlast.c \
						${LST_D}ft_lstnew.c \
						${LST_D}ft_lstsize.c \
						${LST_D}ft_lstiter.c \
						${LST_D}ft_lstmap.c

SRC_PRINTF			=	${FT_PRINTF_D}ft_functions.c \
						${FT_PRINTF_D}ft_printf.c

SRC_GNL				=	${GNL_D}get_next_line_utils.c \
						${GNL_D}get_next_line.c

#OBJS*************************************#

OBJ					=	${patsubst ${SRC_D}%.c, ${OBJ_D}%.o, ${SRC}}

OBJ_FT_PRINTF		=	${patsubst ${FT_PRINTF_D}%.c, ${OBJ_FT_PRINTF_D}%.o, ${SRC_PRINTF}}

OBJ_GNL				=	${patsubst ${GNL_D}%.c, ${OBJ_GNL_D}%.o, ${SRC_GNL}}

OBJ_LST				=	${patsubst ${LST_D}%.c, ${OBJ_LST_D}%.o, ${SRC_LST}}

#RULES*************************************#

all:					${NAME}

${OBJ_D}%.o:			${SRC_D}%.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_FT_PRINTF_D}%.o:	${FT_PRINTF_D}%.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_GNL_D}%.o:		${GNL_D}%.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_LST_D}%.o:		${LST_D}%.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:				${OBJ_D} ${OBJ_FT_PRINTF_D} ${OBJ_GNL_D} ${OBJ_LST_D} ${OBJ} ${OBJ_FT_PRINTF} ${OBJ_GNL} ${OBJ_LST} ${HEADER} Makefile
	@ar rc $@ ${OBJ} ${OBJ_FT_PRINTF} ${OBJ_GNL} ${OBJ_LST}

${OBJ_D}:
	@mkdir -p $@

${OBJ_FT_PRINTF_D}:
	@mkdir -p $@

${OBJ_GNL_D}:
	@mkdir -p $@

${OBJ_LST_D}:
	@mkdir -p $@

clean:
	${RM} ${OBJ_D}
	${RM} ${OBJ_FT_PRINTF_D}
	${RM} ${OBJ_GNL_D}
	${RM} ${OBJ_LST_D}

fclean:					clean
	${RM} ${NAME}

re:						fclean all

#PHONY*************************************#

.PHONY:	all clean fclean re