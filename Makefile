all:
	g++ -c src/game.cpp -o build/game.o
	g++ -c src/main.cpp -o build/main.o
	g++ -c src/globals.cpp -o build/globals.o
	g++ -c src/entity.cpp -o build/entity.o
	g++ -c src/zombie.cpp -o build/zombie.o
	g++ -c src/entityManager.cpp -o build/entityManager.o
	g++ -c src/player.cpp -o build/player.o
	g++ -c src/tileManager.cpp -o build/tileManager.o
	g++ -c src/tile.cpp -o build/tile.o
	g++ -c src/textures.cpp -o build/textures.o

	g++ build/game.o build/player.o build/textures.o build/tileManager.o build/tile.o build/zombie.o build/globals.o build/main.o build/entityManager.o build/entity.o -o game -lsfml-graphics -lsfml-window -lsfml-system -Wall
	./game