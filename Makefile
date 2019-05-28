NAME = air.exe

SRC_PATH := ./sources/
SRC_SUB_PATH :=	 
OBJ_PATH := ./objects/
LIB_PATH := ./libraries/
INC_PATH := ./includes/ \
			./includes/ECS/ \
			$(LIB_PATH)SDL2/include/ \

GCC_FLGS += -fno-exceptions -D_GLIBCXX_USE_CXX11_ABI=0
# -pedantic -g3 -g
# -Werror -Wextra -Wall
CPP_FLGS += 
#-Wno-c++11-extensions
GCC_LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

SYSCONF_LINK = g++ -std=c++11
# -m32 -W -Wall -O3 -save-temps -c

LDFLAGS      = -O3 
LIB_NAME 	=	SDL2/lib/ 

INC 		:= $(addprefix -I,$(INC_PATH) $(addprefix ./includes/, $(SRC_SUB_PATH)))
LIB 		:= $(addprefix -L$(LIB_PATH),$(LIB_NAME))

sources_sub_path = $(addprefix $(SRC_PATH), $(SRC_SUB_PATH))
object_sub_path = $(addprefix $(OBJ_PATH), $(SRC_SUB_PATH))

# object_sub_cpp := $(patsubst %.cpp, %.o, $(wildcard $(addsuffix *.cpp, $(sources_sub_path))))
objectcpp := $(patsubst %.cpp, %.o, $(wildcard $(addprefix $(SRC_PATH), *.cpp)))
objectc := $(patsubst %.c, %.o, $(wildcard $(addprefix $(SRC_PATH), *.c)))

objectcpp := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectcpp) $(object_sub_cpp))
objectc := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectc))

objectcpp := $(objectcpp:.cpp=.o)
objectc := $(objectc:.c=.o)

object := $(objectcpp)
# $(objectc)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ_PATH) $(object)
		$(SYSCONF_LINK) $(GCC_FLGS) $(LDFLAGS) -o $@ $(object) $(INC) $(LIB) $(GCC_LIBS)

$(object_sub_path) : $(OBJ_PATH)
		mkdir -p $@

$(OBJ_PATH) :
		mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		$(SYSCONF_LINK) $(GCC_FLGS) $(CPP_FLGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		gcc $(GCC_FLGS) -c $< -o $@ $(INC)

clean:
		rm -f $(object)
		rm -rf $(object_sub_path)
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -f $(NAME)

re: fclean all
