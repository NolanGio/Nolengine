windows:
	g++ -I include -L lib -L ./ -o bin/main src/main.cpp -l mingw32 -l SDL2main -l SDL2 -l SDL2_image

linux:
	g++ -o bin/main.out src/main.cpp -lSDL2 -lSDL2_image

wasm:
	em++ src/main.cpp -o bin/index.html -g -lm --bind -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file bin/assets/ --use-preload-plugins