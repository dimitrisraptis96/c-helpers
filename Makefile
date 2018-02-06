SHELL := /bin/bash


# ============================================
# COMMANDS

CC = gcc -O3 -lm
RM = rm -f

# ==========================================
# TARGETS


EXECUTABLES = binary2text compare pairwiseDistance

all: $(EXECUTABLES)


binary2text: binary2text.c
	$(CC) $< -o $@	

compare: compare.c
	$(CC) $< -o $@

pairwiseDistance: pairwiseDistance.c
	$(CC) $< -o $@ -lm

clean:
	$(RM) *.o *~ $(EXECUTABLES)
