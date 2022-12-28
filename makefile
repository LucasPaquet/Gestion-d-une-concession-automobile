.SILENT:

CLASS =./class
OBJECT =./object
CO=g++
OBJS_QT = $(OBJECT)/main.o $(OBJECT)/applicgaragewindow.o $(OBJECT)/moc_applicgaragewindow.o $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o $(OBJECT)/Garage.o
PROGRAMS = ApplicGarage
QT = InterfaceQt

all:	$(QT)/$(PROGRAMS) $(OBJECT)/applicgaragewindow.o

$(QT)/ApplicGarage:	$(OBJS_QT)
		echo Creation de ApplicGarage...
		$(CO) -Wl,-O1 -o ApplicGarage $(OBJS_QT) /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 					
		#rm main.o

$(OBJECT)/main.o:	$(QT)/main.cpp
		echo Creation de main.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(OBJECT)/main.o $(QT)/main.cpp

$(OBJECT)/applicgaragewindow.o:	$(QT)/applicgaragewindow.cpp $(QT)/applicgaragewindow.h $(QT)/ui_applicgaragewindow.h $(OBJECT)/Garage.o
		echo Creation de applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -I $(CLASS) -o $(OBJECT)/applicgaragewindow.o $(QT)/applicgaragewindow.cpp

$(OBJECT)/moc_applicgaragewindow.o:	$(QT)/moc_applicgaragewindow.cpp $(QT)/applicgaragewindow.h
		echo Creation de moc_applicgaragewindow.o
		$(CO) -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(OBJECT)/moc_applicgaragewindow.o $(QT)/moc_applicgaragewindow.cpp


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

$(OBJECT)/Intervenant.o:	$(CLASS)/Intervenant.cpp $(CLASS)/Intervenant.h $(OBJECT)/Personne.o
	echo Creation Intervenant.o
	g++ $(CLASS)/Intervenant.cpp -I $(CLASS) -c -o $(OBJECT)/Intervenant.o #-D DEBUG

$(OBJECT)/Client.o:	$(CLASS)/Client.cpp $(CLASS)/Client.h $(OBJECT)/Intervenant.o
	echo Creation Client.o
	g++ $(CLASS)/Client.cpp -I $(CLASS) -c -o $(OBJECT)/Client.o #-D DEBUG

$(OBJECT)/Employe.o:	$(CLASS)/Employe.cpp $(CLASS)/Employe.h $(OBJECT)/Intervenant.o
	echo Creation Employe.o
	g++ $(CLASS)/Employe.cpp -I $(CLASS) -c -o $(OBJECT)/Employe.o #-D DEBUG

$(OBJECT)/OptionException.o:	$(CLASS)/OptionException.cpp $(CLASS)/OptionException.h $(OBJECT)/Exception.o
	echo Creation OptionException.o
	g++ $(CLASS)/OptionException.cpp -I $(CLASS) -c -o $(OBJECT)/OptionException.o #-D DEBUG

$(OBJECT)/Exception.o:	$(CLASS)/Exception.cpp $(CLASS)/Exception.h
	echo Creation Exception.o
	g++ $(CLASS)/Exception.cpp -I $(CLASS) -c -o $(OBJECT)/Exception.o #-D DEBUG

$(OBJECT)/PasswordException.o:	$(CLASS)/PasswordException.cpp $(CLASS)/PasswordException.h $(OBJECT)/Exception.o
	echo Creation PasswordException.o
	g++ $(CLASS)/PasswordException.cpp -I $(CLASS) -c -o $(OBJECT)/PasswordException.o #-D DEBUG

$(OBJECT)/Vecteur.o:	$(CLASS)/Vecteur.cpp $(CLASS)/Vecteur.h
	echo Creation Vecteur.o
	g++ $(CLASS)/Vecteur.cpp -I $(CLASS) -c -o $(OBJECT)/Vecteur.o #-D DEBUG
	
$(OBJECT)/Iterateur.o:	$(CLASS)/Iterateur.cpp $(CLASS)/Iterateur.h
	echo Creation Iterateur.o
	g++ $(CLASS)/Iterateur.cpp -I $(CLASS) -c -o $(OBJECT)/Iterateur.o #-D DEBUG

$(OBJECT)/Garage.o:	$(CLASS)/Garage.cpp $(CLASS)/Garage.h
	echo Creation Garage.o
	g++ $(CLASS)/Garage.cpp -I $(CLASS) -c -o $(OBJECT)/Garage.o #-D DEBUG

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
	g++ Test3.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o -o Test3 #-D DEBUG
Test4:	Test4.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/Intervenant.o
	echo Creation de Test4
	g++ Test4.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o -o Test4 #-D DEBUG
Test5:	Test5.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o
	echo Creation de Test5
	g++ Test5.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o -o Test5 #-D DEBUG
Test6:	Test6.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o
	echo Creation de Test6
	g++ Test6.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o -o Test6 #-D DEBUG
Test7:	Test7.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o
	echo Creation de Test7
	g++ Test7.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o -o Test7 #-D DEBUG
Test8a:	Test8a.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o $(OBJECT)/Garage.o
	echo Creation de Test8a
	g++ Test8a.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o $(OBJECT)/Garage.o -o Test8a #-D DEBUG
Test8b:	Test8b.cpp $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o $(OBJECT)/Garage.o
	echo Creation de Test8b
	g++ Test8b.cpp -I $(CLASS) $(OBJECT)/Modele.o $(OBJECT)/Voiture.o $(OBJECT)/Option.o $(OBJECT)/Personne.o $(OBJECT)/Intervenant.o $(OBJECT)/Client.o $(OBJECT)/Employe.o $(OBJECT)/OptionException.o $(OBJECT)/Exception.o $(OBJECT)/PasswordException.o $(OBJECT)/Vecteur.o $(OBJECT)/Iterateur.o $(OBJECT)/Garage.o -o Test8b #-D DEBUG

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
	rm -f Test4
	rm -f Test5
	rm -f Test6
	rm -f Test7
	rm -f Test8a
	rm -f Test8b
	@rm -f tags $(PROGRAMS) *~ *.log
reset:
	rm -f Projet_208_MrLagalere.car
	rm -f Peugeot2008.mod
	rm -f JantesAlliage.opt

