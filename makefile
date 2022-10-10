.SILENT:

LIB =./lib
HEADERS =./headers
OBJECT =./object

Test2b:	Test2b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2
	g++ Test2b.cpp -I $(HEADERS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2b #-D DEBUG

$(OBJECT)/Modele.o:	$(LIB)/Modele.cpp $(HEADERS)/Modele.h
	echo Creation Modele.o
	g++ $(LIB)/Modele.cpp -I $(HEADERS) -c -o $(OBJECT)/Modele.o #-D DEBUG

$(OBJECT)/Voiture.o:	$(LIB)/Voiture.cpp $(HEADERS)/Voiture.h
	echo Creation Voiture.o
	g++ $(LIB)/Voiture.cpp -I $(HEADERS) -c -o $(OBJECT)/Voiture.o #-D DEBUG

$(OBJECT)/Option.o:	$(LIB)/Option.cpp $(HEADERS)/Option.h
	echo Creation Option.o
	g++ $(LIB)/Option.cpp -I $(HEADERS) -c -o $(OBJECT)/Option.o #-D DEBUG
clean:
	echo Suppression des .o
	rm -f $(OBJECT)/*.o
	
clobber:
	echo Suppression de Test2 et Test2b
	rm -f Test2
	rm -f Test2b

