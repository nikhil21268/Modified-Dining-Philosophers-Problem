#TARGETS=a q2 compile_ta
TARGETS=APart1 APart2 BPart1 BPart2 BFirstAttempt
CC_C=$(CROSS_TOOL)gcc
#CFLAGS=-Wall -g -std=c99 
CFLAGS=-g -pthread
all: clean $(TARGETS)
$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@
# do1: scrip1.sh
#     chmod 755 scrip1.sh
# do2: scrip2.sh
#     chmod 755 scrip2.sh
# do3: scrip3.sh
#     chmod 755 scrip3.sh
# chmod u+x scrip1.sh
# chmod u+x scrip2.sh
# chmod u+x scrip3.sh
# TARGETS2=scrip1 scrip2 scrip3
# CC_C2=$(CROSS_TOOL)chmod
# CFLAGS2=u+x
# $(TARGETS2):
# 	$(CC_C2) $(CFLAGS2) $@.sh 

clean:
	rm -f $(TARGETS)
#chmod u+x deploy.sh