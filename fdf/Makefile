# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 16:40:56 by aluzingu          #+#    #+#              #
#    Updated: 2024/07/16 16:40:58 by aluzingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := fdf
CC              := cc
RM              := rm -f
FLAGS           := -Wall -Wextra -Werror

HEADDIR         := ./includes/
HEADLIST        := fdf.h
HEADERS         := $(addprefix ${HEADDIR}, ${HEADLIST})

SRCSDIR         := ./src/
SRCSLIST        := main.c init.c utils.c utils2.c color.c controls_utils.c draw.c project.c read_map.c utils3.c
SRCS            := $(addprefix ${SRCSDIR}, ${SRCSLIST})

OBJSDIR         := ./obj/
OBJSLIST        := ${SRCSLIST:.c=.o}
OBJS            := $(addprefix ${OBJSDIR}, ${OBJSLIST})

LIBFTDIR        := ./libft/
LIBFT           := ${LIBFTDIR}libft.a

MLXDIR          := ./minilibx-linux/
MLX             := ${MLXDIR}libmlx.a

LIBS            := -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -lX11 -lm
INCS            := -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}

CYAN            := \033[0;36m
RESET           := \033[0m

${NAME}:        ${MLX} ${LIBFT} ${OBJSDIR} ${OBJS}
		${CC} $(FLAGS) ${OBJS} -o ${NAME} ${LIBS} ${INCS}

${LIBFT}:
		make -C ${LIBFTDIR}

${MLX}:
		make -C ${MLXDIR}

${OBJSDIR}%.o: ${SRCSDIR}%.c ${HEADERS}
		${CC} $(FLAGS) ${INCS} -c $< -o $@
		
${OBJSDIR}:
		mkdir -p ${OBJSDIR}

PHONY: all clean fclean re

all: ${NAME}

clean:
		${RM} -r ${OBJSDIR}
		${RM} -r ${OBJSDIRBONUS}
		make -C ${LIBFTDIR} clean
		make -C ${MLXDIR} clean

fclean: clean
		${RM} ${NAME}
		${RM} ${BONUSNAME}
		make -C ${LIBFTDIR} fclean

re: fclean all
