main: ./src/maj.h ./src/maj.cpp ./src/input.cpp ./src/output.cpp ./src/analysis.cpp ./src/main.cpp
	g++ -o main ./src/maj.cpp ./src/input.cpp ./src/output.cpp ./src/analysis.cpp ./src/main.cpp -O2