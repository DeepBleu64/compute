
NAME = compute
VERSION = 0.1

SRC = src/*.c
DIR = /usr/bin


install:
	gcc $(SRC) -o $(DIR)/$(NAME)


uninstall:
	rm  $(DIR)/$(NAME)
