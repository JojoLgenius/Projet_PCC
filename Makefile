
# Makefile #

# Option

CC = gcc                                                           
CFLAGS= -Wall -W -pedantic -O3 `pkg-config --cflags MLV`           
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`          
LDLIBS= `pkg-config --libs-only-l MLV`

LISTE_OBJ = main.o fourmi.o TSP_naive.o TSP_elag_naive.o affichage.o    


# Compilation

#all : $(LISTE_OBJ)
#	$(CC) $(CFLAGS) -o PCC $(LISTE_OBJ) $(LDFLAGS) $(LDLIBS) -g

#main.o : main.c
#	$(CC) $(CFLAGS) -c main.c 

#TSP_naive.o: TSP_naive.c TSP_naive.h
#	$(CC) $(CFLAGS) -c TSP_naive.c 

#TSP_elag_naive.o: TSP_elag_naive.c TSP_elag_naive.h
#	$(CC) $(CFLAGS) -c TSP_elag_naive.c 

#fourmi.o: fourmi.c fourmi.h
#	$(CC) $(CFLAGS) -c fourmi.c

#affichage.o: affichage.c affichage.h
#	$(CC) $(CFLAGS) -c affichage.c 



# Nettoyage

clean:
	rm -f *.o PCC