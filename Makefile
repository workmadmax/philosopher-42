# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 10:18:49 by madmax42          #+#    #+#              #
#    Updated: 2023/05/03 16:43:07 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						=	philo
CC							=	gcc -Wall -Wextra -Werror -g3 -pthread
RM							=	rm -f
INCLUDES					=	-I./include

SRCS						=	arguments.c check_routine.c \
								eating.c routine.c \
								clean_data.c init_data.c libft.c \
								message.c time_stap.c \
								main.c
									
VPATH						=	./srcs/ \
								./srcs/checkers/ \
								./srcs/routine/ \
								./srcs/utils/ \

OBJS_DIR					=	objects
OBJS						=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))


$(OBJS_DIR)/%.o:			%.c
								$(CC) -c $< -o $@ $(INCLUDES)

all:	$(OBJS_DIR) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $@ $(INCLUDES)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re