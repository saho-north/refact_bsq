# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2023/08/11 02:19:47 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = bsq
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS += -fsanitize=address -fno-omit-frame-pointer
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	-rm -f $(OBJS)

fclean:
	-rm -f $(TARGET) $(OBJS)

re: fclean all

test: test1 test2 test3

test1: $(TARGET)
	./$(TARGET) ./maps/example_file

test2: $(TARGET)
	cat ./maps/example_file | ./$(TARGET)

test3: $(TARGET)
	./$(TARGET) ./maps/example_file1 ./maps/example_file2

.PHONY: all clean re test1 test2 test fclean
