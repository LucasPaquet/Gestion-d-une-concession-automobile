.SILENT:

CLASS =./class
OBJECT =./object

Test4:	Test4.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Client.o $(OBJECT)/Employe.o
	echo Creation de Test4
	g++ Test4.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Client.o $(OBJECT)/Employe.o -o Test4 #-D DEBUG

$(OBJECT)/Modele.o:	$(CLASS)/Modele.cpp $(CLASS)/Modele.h
	echo Creation Modele.o
	g++ $(CLASS)/Modele.cpp -I $(CLASS) -c -o $(OBJECT)/Modele.o #-D DEBUG

$(OBJECT)/Voiture.o:	$(CLASS)/Voiture.cpp $(CLASS)/Voiture.h
	echo Creation Voiture.o
	g++ $(CLASS)/Voiture.cpp -I $(CLASS) -c -o $(OBJECT)/Voiture.o #-D DEBUG

$(OBJECT)/Option.o:	$(CLASS)/Option.cpp $(CLASS)/Option.h
	echo Creation Option.o
	g++ $(CLASS)/Option.cpp -I $(CLASS) -c -o $(OBJECT)/Option.o #-D DEBUG

$(OBJECT)/Personne.o:	$(CLASS)/Personne.cpp $(CLASS)/Personne.h
	echo Creation Personne.o
	g++ $(CLASS)/Personne.cpp -I $(CLASS) -c -o $(OBJECT)/Personne.o #-D DEBUG

$(OBJECT)/Client.o:	$(CLASS)/Client.cpp $(CLASS)/Client.h
	echo Creation Client.o
	g++ $(CLASS)/Client.cpp -I $(CLASS) -c -o $(OBJECT)/Client.o #-D DEBUG

$(OBJECT)/Employe.o:	$(CLASS)/Employe.cpp $(CLASS)/Employe.h
	echo Creation Employe.o
	g++ $(CLASS)/Employe.cpp -I $(CLASS) -c -o $(OBJECT)/Employe.o #-D DEBUG

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
Test3:	Test3.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o
	echo Creation de Test3
	g++ Test3.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o -o Test3 #-D DEBUG

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

