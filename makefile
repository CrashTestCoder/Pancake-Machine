CC = gcc
CPP = g++
IDIR =include
ODIR =obj
lDIR =lib
SDIR =src
LIBS =-lm
CFLAGS = -std=c++2a -lwiringPi -I$(IDIR) -I. -pthread -lpthread -L./lib -fconcepts
_OBJ = pca9685.o Servo.o flipper.o main.o Serial_Device.o Mixer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
_DEPS =  Serial_Device.hpp Mixer.hpp Flipper.hpp Constants.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

Pancake-Machine: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f  ${(ODIR)/%.o}

.PHONY: pancake

pancake:
	sudo ./Pancake-Machine
