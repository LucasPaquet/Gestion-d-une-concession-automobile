.SILENT:

LIB =./lib
HEADERS =./headers
OBJECT =./object

Test1:	Test1.cpp $(OBJECT)/Modele.o
	echo Creation de Test1
	g++ Test1.cpp -I $(HEADERS) $(OBJECT)/Modele.o -o Test1
$(OBJECT)/Modele.o:	$(LIB)/Modele.cpp $(HEADERS)/Modele.h
	echo Creation Modele.o
	g++ $(LIB)/Modele.cpp -I $(HEADERS) -c -o $(OBJECT)/Modele.o

clean:
	rm -f $(OBJECT)/*.o
clobber:
	rm -f Test1