
FLAGS = -c -g -iquote inc -pedantic -Wall
FINAL = -pedantic -Wall


#	#	#	#	#	#	#	#

./output: obj obj/main.o obj/ogolny.o obj/grafMacierz.o obj/grafLista.o obj/kruskal.o obj/prima.o
	g++ ${FINAL} -o ./output obj/main.o obj/ogolny.o obj/grafMacierz.o obj/grafLista.o obj/kruskal.o obj/prima.o
	rm -r obj
	clear

obj:
	mkdir -p obj

#	#	#	#	#	#	#	#

obj/main.o: main.cpp
	g++ ${FLAGS} -o obj/main.o main.cpp

obj/ogolny.o: src/ogolny.cpp inc/ogolny.hh
	g++ ${FLAGS} -o obj/ogolny.o src/ogolny.cpp

obj/grafMacierz.o: src/grafMacierz.cpp inc/grafMacierz.hh
	g++ ${FLAGS} -o obj/grafMacierz.o src/grafMacierz.cpp

obj/grafLista.o: src/grafLista.cpp inc/grafLista.hh
	g++ ${FLAGS} -o obj/grafLista.o src/grafLista.cpp

obj/kruskal.o: src/kruskal.cpp inc/kruskal.hh
	g++ ${FLAGS} -o obj/kruskal.o src/kruskal.cpp

obj/prima.o: src/prima.cpp inc/prima.hh
	g++ ${FLAGS} -o obj/prima.o src/prima.cpp

#	#	#	#	#	#	#	#

clean:
	rm -f -r obj/*.o ./output
