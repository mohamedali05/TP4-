CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g

Analog : Analog.o Lecture.o Noeud.o Graphe.o Ecriture.o
	@echo "edl de Analog"
	g++ -o $@ $^

%.o : %.cpp %.h
	@echo "compil de $<"
	g++ -c $< $(CPPFLAGS)


clean : 
	clear
	clear
	@echo "suppresion des fichiers compilés existants"
	touch t.o
	rm *.o
	make

runCheck : 
	make clean
	valgrind ./test