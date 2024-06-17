all:

	g++ -c src/game.cpp -o build/game.o
	g++ -c src/main.cpp -o build/main.o
	g++ -c src/globals.cpp -o build/globals.o
	g++ -c src/objectManager.cpp -o build/objectManager.o
	g++ -c src/player.cpp -o build/player.o
	g++ -c src/tileManager.cpp -o build/tileManager.o
	g++ -c src/tile.cpp -o build/tile.o
	g++ -c src/textures.cpp -o build/textures.o
	g++ -c src/object.cpp -o build/object.o
	g++ -c src/key.cpp -o build/key.o

	g++ build/game.o build/key.o build/player.o build/textures.o build/object.o build/tileManager.o build/tile.o build/globals.o build/main.o build/objectManager.o -o game -lsfml-graphics -lsfml-window -lsfml-system -Wall
	./game