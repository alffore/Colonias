# Makefile para construir el lector de poligonos y generar la relacion de 
# colonia, manzana, ageb para cada objeto del SIC, para reintegrarlo en la BD
# y generar un conjunto de subproductos.
#
# AAFR, 22 de junio de 2013
#
#

CC= g++ -c

CLINKER= g++ -lm -o 

CFLAGS= -O3 -Wall

LIBS= 


OBJ= main.o \
	ObjetoGeom.o \
	Punto.o \
	Poligono.o \
	LectorINT.o \
	RecursoC.o \
	LectorPSiC.o \
	ITRF2CCL.o \
	AIncPP.o
	
	

DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/

all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)lec_since_sic.exe $(OBJ) $(LIBS) $(CFLAGS)



%.o: $(DIR_SRC)%.cpp
	$(CC) $(CFLAGS)  $<
	
clean:
	@rm -rfv *.o
