main: ./src/main.cpp ./src/input.cpp ./src/output.cpp ./src/analysis.cpp
	g++ -o main ./src/main.cpp ./src/input.cpp ./src/output.cpp ./src/analysis.cpp -O2