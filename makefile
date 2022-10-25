.SILENT:

CLASS =./class
OBJECT =./object

Test3:	Test3.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test3
	g++ Test3.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test3 #-D DEBUG

$(OBJECT)/Modele.o:	$(CLASS)/Modele.cpp $(CLASS)/Modele.h
	echo Creation Modele.o
	g++ $(CLASS)/Modele.cpp -I $(CLASS) -c -o $(OBJECT)/Modele.o #-D DEBUG

$(OBJECT)/Voiture.o:	$(CLASS)/Voiture.cpp $(CLASS)/Voiture.h
	echo Creation Voiture.o
	g++ $(CLASS)/Voiture.cpp -I $(CLASS) -c -o $(OBJECT)/Voiture.o #-D DEBUG

$(OBJECT)/Option.o:	$(CLASS)/Option.cpp $(CLASS)/Option.h
	echo Creation Option.o
	g++ $(CLASS)/Option.cpp -I $(CLASS) -c -o $(OBJECT)/Option.o #-D DEBUG

Test1:	Test1.cpp $(OBJECT)/Modele.o
	echo Creation de Test1
	g++ Test1.cpp -I $(CLASS) $(OBJECT)/Modele.o -o Test1
Test2b:	Test2b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2b
	g++ Test2b.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2b #-D DEBUG
Test2a:	Test2b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2a
	g++ Test2a.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2a #-D DEBUG
Test2c:	Test2c.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test2c
	g++ Test2c.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test2c #-D DEBUG

clean:
	echo Suppression des .o
	rm -f $(OBJECT)/*.o
	
clobber:
	echo Suppression des executables
	rm -f Test1
	rm -f Test2a
	rm -f Test2b
	rm -f Test2c
	rm -f Test3

