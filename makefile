hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/kisi.o -c ./src/kisi.cpp
	g++ -I ./include/ -o ./lib/yigit.o -c ./src/yigit.cpp
	g++ -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp
	g++ -I ./include/ -o ./lib/avlagaci.o -c ./src/avlagaci.cpp
	g++ -I ./include/ -o ./bin/program ./lib/kisi.o ./lib/yigit.o ./lib/dugum.o ./lib/avlagaci.o ./src/main.cpp
calistir:
	./bin/program