CC = g++
CFLAGS = -std=c++17 -fopenmp -O2
SRC = main.cpp
OBJ = main.o

all: out

out: $(OBJ)
	$(CC) $(CFLAGS) -o out $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -p $@

clean:
	rm -f *.o out

run:
	@echo "Type 'make help' for Instructions"
	./out $(ARGS)

help:
	@echo "===================================="
	@echo "       Run Program Instructions     "
	@echo "===================================="
	@echo "Usage: make run ARGS='<arguments>'"
	@echo "Arguments:"
	@echo "  --parallel          : Makes program parallel"
	@echo "    --num <int>       : The number of threads to use (default: 4)"
	@echo "  --speed <slow/fast> : Adjusts the game speed"
	@echo "  --dynamic           : Makes the game speed dynamic (independent from --speed)"
	@echo "===================================="