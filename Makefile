#
# Chugine simple 2d game engine made in C
# Copyright (C) 2023-2024 Chugine developers
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

CC = gcc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CFLAGS = -Wall -Iinclude -c
	LDFLAGS = -framework GLUT -framework OpenGL -framework Cocoa -shared
else
	CFLAGS = -Wall -Iinclude -c
	LDFLAGS = -shared -L/usr/X11R6/lib -lGL -lGLU -lglut
endif

SRC_DIR = ./src
LIB_DIR = ./lib

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(LIB_DIR)/%.o,$(SRC_FILES))

LIBRARY = $(LIB_DIR)/chugine.so

all: create_lib_folder $(LIBRARY)

create_lib_folder:
	mkdir -p lib

$(LIBRARY): $(OBJ_FILES)
	make -p $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIBRARY) $(OBJ_FILES)

install:
	sudo cp -r ./lib/chugine.so /usr/lib/

.PHONY: all clean
