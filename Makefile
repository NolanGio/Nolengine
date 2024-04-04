all:
	g++ -I include -L lib -L ./ -o bin/main src/main.cpp -l mingw32 -l SDL2main -l SDL2 -l SDL2_image 