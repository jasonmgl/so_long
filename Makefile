# ********************************************************************* #
#  __   __  _______  ___   _  _______  _______  ___   ___      _______  #
# |  |_|  ||   _   ||   | | ||       ||       ||   | |   |    |       | #
# |       ||  |_|  ||   |_| ||    ___||    ___||   | |   |    |    ___| #
# |       ||       ||      _||   |___ |   |___ |   | |   |    |   |___  #
# |       ||       ||     |_ |    ___||    ___||   | |   |___ |    ___| #
# | ||_|| ||   _   ||    _  ||   |___ |   |    |   | |       ||   |___  #
# |_|   |_||__| |__||___| |_||_______||___|    |___| |_______||_______| #
#                                                                       #
# ********************************************************************* #


# ************************************************** #


NAME			= 		so_long

NAME_BONUS		=		so_long_bonus

NAME_BONUS_D	= 		${BONUS_D}so_long_bonus

CC				=		cc

CFLAGS			=		 -O2 -Wall -Wextra -Werror -I libft/include/ -I minilibx-linux/ -I include/ -g3

HEADER			=		include/so_long.h

HEADER_BONUS	=		bonus/include/so_long_bonus.h

LIB_H			=		libft/include/libft.h

LIB_A			=		libft/libft.a

MLX_H			=		minilibx-linux/mlx.h

MLX_A			=		minilibx-linux/libmlx.a

BONUS_D			=		bonus/

BONUS_SRC_D		=		${BONUS_D}${SRC_D}

SRC_D			=		src/
				
OBJ_D			=		.obj/

OBJ_BONUS_D		=		bonus/.obj_bonus/

SRC				=		${SRC_D}so_long.c 			\
						${SRC_D}check_map.c 		\
						${SRC_D}check_mapbis.c 		\
						${SRC_D}check_validity.c	\
						${SRC_D}error_utils.c 		\
						${SRC_D}init.c 				\
						${SRC_D}get_map.c			\
						${SRC_D}exit_utils.c		\
						${SRC_D}make_map.c			\
						${SRC_D}get_display.c		\
						${SRC_D}display_utils.c		\
						${SRC_D}key_event.c			\

SRC_BONUS		=		${BONUS_SRC_D}so_long_bonus.c 		\
						${BONUS_SRC_D}check_map_bonus.c 		\
						${BONUS_SRC_D}check_mapbis_bonus.c 	\
						${BONUS_SRC_D}check_validity_bonus.c	\
						${BONUS_SRC_D}error_utils_bonus.c 	\
						${BONUS_SRC_D}init_bonus.c 			\
						${BONUS_SRC_D}get_map_bonus.c			\
						${BONUS_SRC_D}exit_utils_bonus.c		\
						${BONUS_SRC_D}make_map_bonus.c		\
						${BONUS_SRC_D}get_display_bonus.c		\
						${BONUS_SRC_D}display_utils_bonus.c	\
						${BONUS_SRC_D}key_up_bonus.c			\
						${BONUS_SRC_D}key_down_bonus.c		\
						${BONUS_SRC_D}key_right_bonus.c		\
						${BONUS_SRC_D}key_left_bonus.c		\
						${BONUS_SRC_D}anim_open_bonus.c		\
						${BONUS_SRC_D}anim_close_bonus.c		\
						${BONUS_SRC_D}anim_right_bonus.c		\
						${BONUS_SRC_D}anim_left_bonus.c		\
						${BONUS_SRC_D}anim_down_bonus.c		\
						${BONUS_SRC_D}anim_up_bonus.c			\
						${BONUS_SRC_D}anim_die_bonus.c		\

OBJ				=		${patsubst ${SRC_D}%.c, ${OBJ_D}%.o, ${SRC}}

OBJ_BONUS		=		${patsubst ${BONUS_SRC_D}%.c, ${OBJ_BONUS_D}%.o, ${SRC_BONUS}}

# ************************************************** #

all :					${NAME}

${NAME} :				${OBJ_D} ${OBJ} ${HEADER} Makefile
	@${MAKE} -C libft/ --no-print-directory
	@${MAKE} -C minilibx-linux/ --no-print-directory
	${CC} ${CFLAGS} ${OBJ} ${LIB_A} ${MLX_A} -lXext -lX11 -lm -lz -o $@
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m   _____ ____       __    ____  _   ________ \n\
  / ___// __ \     / /   / __ \/ | / / ____/ \n\
  \__ \/ / / /    / /   / / / /  |/ / / __   \n\
 ___/ / /_/ /    / /___/ /_/ / /|  / /_/ /   \n\
/____/\____/____/_____/\____/_/ |_/\____/    \n\
											\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"

${OBJ_D}%.o :			${SRC_D}%.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_D}:
	@mkdir -p $@

${NAME_BONUS_D} :			${OBJ_BONUS_D} ${OBJ_BONUS} ${HEADER_BONUS} Makefile
	@${MAKE} -C libft/ --no-print-directory
	@${MAKE} -C minilibx-linux/ --no-print-directory
	@${CC} ${CFLAGS} ${OBJ_BONUS} ${LIB_A} ${MLX_A} -lXext -lX11 -lm -lz -o ${NAME_BONUS_D}
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m   _____ ____       __    ____  _   ________ \n\
  / ___// __ \     / /   / __ \/ | / / ____/ \n\
  \__ \/ / / /    / /   / / / /  |/ / / __   \n\
 ___/ / /_/ /    / /___/ /_/ / /|  / /_/ /   \n\
/____/\____/____/_____/\____/_/ |_/\____/    \n\
          /_____/____  _   ____  _______     \n\
          / __ )/ __ \/ | / / / / / ___/     \n\
         / __  / / / /  |/ / / / /\__ \      \n\
        / /_/ / /_/ / /|  / /_/ /___/ /      \n\
       /_____/\____/_/ |_/\____//____/       \n\
											\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"
	@echo "\e[32m_____________________________________________\e[0m"

${OBJ_BONUS_D}%.o :		${BONUS_SRC_D}%.c ${HEADER_BONUS} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_BONUS_D}:
	@mkdir -p $@

bonus :					${NAME_BONUS_D}

clean :
	${MAKE} clean -C libft --no-print-directory
	${MAKE} clean -C minilibx-linux --no-print-directory
	rm -rf ${OBJ_D}
	rm -rf ${OBJ_BONUS_D}

fclean : clean
	${MAKE} fclean -C libft --no-print-directory
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS_D}

re :	fclean all

rebonus : fclean bonus


# ************************************************** #


.PHONY :		all clean fclean re bonus rebonus


# ************************************************** #