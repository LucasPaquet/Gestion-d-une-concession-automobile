.SILENT:

LIB =./lib
HEADERS =./headers
OBJECT =./object

Test2:	Test2a.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o
	echo Creation de Test2
	g++ Test2a.cpp -I $(HEADERS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o -o Test2

$(OBJECT)/Modele.o:	$(LIB)/Modele.cpp $(HEADERS)/Modele.h
	echo Creation Modele.o
	g++ $(LIB)/Modele.cpp -I $(HEADERS) -c -o $(OBJECT)/Modele.o

$(OBJECT)/Voiture.o:	$(LIB)/Voiture.cpp $(HEADERS)/Voiture.h
	echo Creation Voiture.o
	g++ $(LIB)/Voiture.cpp -I $(HEADERS) -c -o $(OBJECT)/Voiture.o
clean:
	echo Suppression des .o
	rm -f $(OBJECT)/*.o
	
clobber:
	echo Suppression de Test1
	rm -f Test1

