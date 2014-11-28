CFLAGS += -Wall -g -O0 -std=c99
LDFLAGS += -lm

GENCPU = gencpu.o
BUILD68K = build68k.o
TABLE68K = table68k.o
CPUEMU = cpuemu_31.o \
	cpuemu_32.o \
	cpustbl.o

OBJ = cpuemu_common.o \
	cpummu030.o \
	cpummu.o \
	fpp.o \
	newcpu.o \
	hatari-glue.o \
	readcpu.o \
	custom.o \
	m68000.o
#	memory.o \
.PHONY: all clean generated deps

all: generated deps
	@echo " [ AR ] cpu.a"
	@$(AR) -cr cpu.a $(OBJ) $(TABLE68K) $(CPUEMU) 

clean:
	rm -f $(OBJ) $(BUILD68K) $(GENCPU) $(TABLE68K) $(CPUEMU) table68k.c build68k gencpu cpuemu_31.c cpuemu_32.c cpustbl.c cpustbl.h cpu.a

deps: $(CPUEMU) $(TABLE68K) $(OBJ)

build68k: $(BUILD68K)
	@echo " [ LD ]	$@"
	@$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

gencpu: $(GENCPU) $(TABLE68K) readcpu.o
	@echo " [ LD ]	$@"
	@$(CC) $(CFLAGS) -o $@ $< readcpu.o $(TABLE68K) $(LDFLAGS)

generated: gencpu
	@echo " [GEN ]	cpu specifics"
	@./gencpu

table68k.c: build68k
	@echo " [GEN ]	$@"
	@./build68k < table68k > table68k.c

cpuemu_31.o: generated
	@echo " [ CC ]	$*.c"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

cpuemu_32.o: generated
	@echo " [ CC ]	$*.c"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

cpustbl.o:  generated
	@echo " [ CC ]	$*.c"
	@$(CC) $(CFLAGS) -c -o $@ $*.c
	
%.o: %.c
	@echo " [ CC ]	$<"
	@$(CC) $(CFLAGS) -c -o $@ $< 
