NAME=fratol

$(shell mkdir -p obj/ini obj/renderer)

CC=gcc
SDLFLAGS=-ISDL/include -LSDL/build/build -Wl,-rpath,SDL/build/build -Wl,--enable-new-dtags -lSDL2 
FLAGS=-Wall
FLAGS+=-Werror
FLAGS+=-Wextra

DEBUG?=0
ifeq ($(DEBUG), 1)
  FLAGS+=-g3 -fsanitize=address
endif

VALGRIND_CHECK?=0
ifeq ($(VALGRIND_CHECK), 1)
  FLAGS+=-g
endif

OPTI?=0
ifeq ($(OPTI), 1)
  FLAGS+=-Ofast -ffast-math -march=native
endif

SRC_PATH=src/
SRC_NAME=main.c\
	fractal.c\
	error.c\
	init.c\
	render.c\
	ini/check_parameters.c\
	ini/window.c\
	renderer/update_event.c\
	mandelbrot.c\
	renderer/renderer.c\
	ini/init-fractal.c\
	renderer/zoom.c
  
SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH=include/
INC_NAME=main.h

INC=$(addprefix $(INC_PATH), $(INC_NAME))

OBJ_PATH=obj/
OBJ_NAME=$(addprefix $(OBJ_PATH), $(SRC_NAME))
OBJS=$(OBJ_NAME:.c=.o)

all: SDL $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(SDLFLAGS) -o $(NAME)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@printf "Compiling $@"
	@printf "                     \\n\r"
	@$(CC) $(FLAGS) -I$(INC_PATH) -o $@ -c $<

SDL: 
	@sudo ./install_sdl2

clean:
	rm -rf $(OBJ_PATH)*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
