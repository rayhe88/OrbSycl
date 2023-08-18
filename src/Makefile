CXX := icpx
CXXFLAGS :=  -fsycl -Wall 
LDFLAGS := -lm -lsycl
INC := ../include

OBJS = Evaluator.o Functions.o main.o runCommands.o

EXE = vol.x

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -fsycl $(OBJS) -o $(EXE) $(LDFLAGS)

Evaluator.o: Evaluator.cpp $(INC)/Evaluator.hpp
	$(CXX) $(CXXFLAGS) -I$(INC) Evaluator.cpp -c

Functions.o: Functions.cpp $(INC)/Functions.hpp
	$(CXX) $(CXXFLAGS) -I$(INC) Functions.cpp -c

runCommands.o: runCommands.cpp $(INC)/runCommands.hpp
	$(CXX) $(CXXFLAGS) -I$(INC) runCommands.cpp -c

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(INC) main.cpp -c

.Phony: clean
clean:
	rm -f *.o $(EXE)

