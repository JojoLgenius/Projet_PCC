
# Makefile #

# Option

CC = gcc
CFLAGS= -Wall -W -pedantic -O3 `pkg-config --cflags MLV`
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS= `pkg-config --libs-only-l MLV`

LISTE_OBJ = main.o DAT_Matrice.o Fourmi.o TSP_Naive.o Affichage.o Evenement.o

# Compilation

all : $(LISTE_OBJ)
	$(CC) $(CFLAGS) -o PCC $(LISTE_OBJ) $(LDFLAGS) $(LDLIBS) -g

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

DAT_Matrice.o : DAT_Matrice.c DAT_Matrice.h
	$(CC) $(CFLAGS) -c DAT_Matrice.c

Affichage.o: Affichage.c Affichage.h
	$(CC) $(CFLAGS) -c Affichage.c

Evenement.o: Evenement.c Evenement.h
	$(CC) $(CFLAGS) -c Evenement.c

TSP_Naive.o: TSP_Naive.c TSP_Naive.h
	$(CC) $(CFLAGS) -c TSP_Naive.c 

Fourmi.o: Fourmi.c Fourmi.h
	$(CC) $(CFLAGS) -c Fourmi.c




# Nettoyage

clean:
	rm -f *.o PCC