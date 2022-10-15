.SILENT:

CLASS =./class
OBJECT =./object

Test2c:	Test2c.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2c
	g++ Test2c.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2c #-D DEBUG

$(OBJECT)/Modele.o:	$(CLASS)/Modele.cpp $(CLASS)/Modele.h
	echo Creation Modele.o
	g++ $(CLASS)/Modele.cpp -I $(CLASS) -c -o $(OBJECT)/Modele.o #-D DEBUG

$(OBJECT)/Voiture.o:	$(CLASS)/Voiture.cpp $(CLASS)/Voiture.h
	echo Creation Voiture.o
	g++ $(CLASS)/Voiture.cpp -I $(CLASS) -c -o $(OBJECT)/Voiture.o #-D DEBUG

$(OBJECT)/Option.o:	$(CLASS)/Option.cpp $(CLASS)/Option.h
	echo Creation Option.o
	g++ $(CLASS)/Option.cpp -I $(CLASS) -c -o $(OBJECT)/Option.o #-D DEBUG
Test2b:	Test2b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2b
	g++ Test2b.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2b #-D DEBUG
Test2a:	Test2b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2a
	g++ Test2a.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2a #-D DEBUG

clean:
	echo Suppression des .o
	rm -f $(OBJECT)/*.o
	
clobber:
	echo Suppression de Test2a, Test2b et Test2c
	rm -f Test2a
	rm -f Test2b
	rm -f Test2c

