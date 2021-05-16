#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: graf
	./graf

obj:
		mkdir -p obj

graf: obj/main.o obj/Dijkstra.o obj/BellFord.o obj/Read_From_File.o obj/functions.o obj/N_Matrix.o obj/N_List.o obj/Test.o obj/BellFord_List.o
	g++ -Wall -pedantic -o graf obj/main.o obj/Read_From_File.o obj/BellFord.o obj/Dijkstra.o obj/functions.o obj/N_Matrix.o obj/N_List.o obj/Test.o obj/BellFord_List.o
								   

obj/main.o: src/main.cpp inc/Dijkstra.hh inc/BellFord.hh inc/Read_From_File.hh\
     inc/Read_From_File.hh inc/functions.hh inc/BellFord_List.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dijkstra.o: src/Dijkstra.cpp inc/Dijkstra.hh inc/BellFord.hh inc/Read_From_File.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/Dijkstra.o src/Dijkstra.cpp

obj/BellFord.o: src/BellFord.cpp inc/BellFord.hh inc/Read_From_File.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/BellFord.o src/BellFord.cpp

obj/Read_From_File.o: src/Read_From_File.cpp inc/Read_From_File.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/Read_From_File.o src/Read_From_File.cpp

obj/Test.o: src/Test.cpp inc/Test.hh inc/Dijkstra.hh inc/BellFord.hh inc/N_List.hh inc/N_Matrix.hh
	g++ ${CPPFLAGS} -o obj/Test.o src/Test.cpp

obj/functions.o: src/functions.cpp inc/functions.hh
	g++ ${CPPFLAGS} -o obj/functions.o src/functions.cpp

obj/N_Matrix.o: src/N_Matrix.cpp inc/N_Matrix.hh
	g++ ${CPPFLAGS} -o obj/N_Matrix.o src/N_Matrix.cpp

obj/N_List.o: src/N_List.cpp inc/N_List.hh
	g++ ${CPPFLAGS} -o obj/N_List.o src/N_List.cpp

obj/BellFord_List.o: src/BellFord_List.cpp inc/BellFord_List.hh
	g++ ${CPPFLAGS} -o obj/BellFord_List.o src/BellFord_List.cpp



clean:
	rm -f obj/*.o graf