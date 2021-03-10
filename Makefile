# Makefile copiado (com permissão) do código da Cristiane Naves
CC = g++
RMDIR = rm -rf
RM = rm -f
 
RUN = ./
 
DEP_FLAGS = -M -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d
 
DIRECTIVES = -std=c++11 -Wall -Wextra -c -I $(HEADER_PATH)
 
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

INC_PATHS = -I$(INC_PATH) $(addprefix -I,$(SDL_INC_PATH))

INC_PATH = include 
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep
 
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(INC_PATH)/*.h)
FILE_NAMES = $(sort $(notdir $(CPP_FILES:.cpp=)) $(notdir $(INC_FILES:.h=)))
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
 
EXEC = JOGO
 
ifeq ($(OS),Windows_NT)
 
RMDIR = rd /s /q
RM = del /q
 
RUN =
 
SDL_PATH = C:\SDL2\SDL2-2.0.5\x86_64-w64-mingw32 C:/Tools/msys64/mingw64

SDL_INC_PATH += $(addsuffix /include,$(SDL_PATHS))
LINK_PATH = $(addprefix -L,$(addsuffix /lib,$(SDL_PATHS)))
FLAGS += -mwindows
DFLAGS += -mconsole
LIBS := -lmingw32 -lSDL2main $(LIBS)
 
DIRECTIVES += -I $(SDL_PATH)\include\SDL2
 
LIBS = -L $(SDL_PATH)\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
 
EXEC := $(EXEC).exe
 
else
UNAME_S := $(shell uname -s)
 
ifeq ($(UNAME_S), Darwin)
LIBS = -lm -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf
endif
endif
 
all: $(EXEC)
 
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LINK_PATH) $(LIBS) $(FLAGS)
 
$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | folders
	$(CC) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | folders
	$(CC) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)
 

 


folders:
ifeq ($(OS), Windows_NT)
	@if not exist $(DEP_PATH) ( mkdir $(DEP_PATH) )
	@if not exist $(BIN_PATH) ( mkdir $(BIN_PATH) )
	@if not exist $(INC_PATH) ( mkdir $(INC_PATH) )
	@if not exist $(SRC_PATH) ( mkdir $(SRC_PATH) )


else
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)
endif

print-% : ; @echo $* = $($*)
 
debug: DIRECTIVES += -ggdb -O0 -DDEBUG
debug: all
 
dev: debug run
 
gdb: RUN := gdb $(RUN)
gdb: dev
 
release: DIRECTIVES += -Ofast -mtune=native
release: all
 
run:
	$(RUN)$(EXEC)
 
clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)
 
.PRECIOUS: $(DEP_PATH)/%.D
 
.PHONY: debug clean release
 
-include $(DEP_FILES)