TARGET  = chess
CC      = g++
CFLAGS  = -Wshadow    							\
		   -std=c++17							\
		   -Winit-self 							\
		   -Wredundant-decls 					\
		   -Wcast-align							\
		   -Wundef 								\
		   -Wfloat-equal 						\
		   -Winline 							\
		   -Wunreachable-code 					\
		   -Wmissing-declarations 				\
		   -Wmissing-include-dirs 				\
		   -Wswitch-enum 						\
		   -Wmain 								\
		   -Wextra 								\
		   -Wall 								\
		   -g 									\
		   -pipe 								\
		   -fexceptions 						\
		   -Wcast-qual 							\
		   -Wconversion 						\
		   -Wctor-dtor-privacy 					\
		   -Wempty-body 						\
		   -Wformat-security 					\
		   -Wformat=2 							\
		   -Wignored-qualifiers 				\
		   -Wlogical-op 						\
		   -Wmissing-field-initializers 		\
		   -Wnon-virtual-dtor 					\
		   -Woverloaded-virtual 				\
		   -Wpointer-arith 						\
		   -Wsign-promo 						\
		   -Wstack-usage=8192 					\
		   -Wstrict-aliasing 					\
		   -Wstrict-null-sentinel 				\
		   -Wtype-limits 						\
		   -Wwrite-strings 						\
		   -D_DEBUG 							\
		   -D_EJUDGE_CLIENT_SIDE

OBJ_DIR = ./obj

DEBUG_DIR = ./debug_utils/
PIECE_DIR = ./ch_piece/

##################################################################################################################

#SRC
CHESS_SRC = $(wildcard *.cpp)
CHESS_OBJ = $(patsubst $(OBJ_DIR)%.cpp, %.o, $(CHESS_SRC))
#PIECE
PIECE_SRC = $(wildcard $(PIECE_DIR)*.cpp)
PIECE_OBJ = $(patsubst $(OBJ_DIR)%.cpp, %.o, $(PIECE_SRC))
#Debug
DEBUG_SRC = $(wildcard $(DEBUG_DIR)*.cpp)
DEBUG_OBJ = $(patsubst $(OBJ_DIR)%.cpp, %.o, $(DEBUG_SRC))

##################################BACK_AND_FRONT####################################################################

all: $(TARGET)
$(TARGET):  $(CHESS_OBJ) $(DEBUG_OBJ) $(PIECE_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(CHESS_OBJ) $(DEBUG_OBJ) $(PIECE_OBJ)

$(OBJ_DIR)%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@


################################PHONIES################################################################################

.PHONY: valgrind
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(TARGET)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)*.o  $(TARGET) *.aux *.log vgcore.*
