###################################################
# Created by: Anadi Mishra
# Created on: 26 October 2022
###################################################

SRCDIR = ../SRC
BINDIR = ../bin
OBJDIR = ../obj
REPORTDIR = ../reports

all:
	gcc -c ${SRCDIR}/project.c -o ${OBJDIR}/project.o
	gcc ${OBJDIR}/project.o -o ${BINDIR}/project.bin
	
	# Aditya's comment
	#splint -quiet ../SRC/project.c >> ../reports/splint_report.txt
	# parser error in splint
	#dynamic valgrind issue ?

#memcheck:
	#valgrind ../bin/project.bin  > ../reports/valgrind_report.txt 2>&1
clean: 
	rm ${OBJDIR}/*.o ${BINDIR}/project.bin




###################### End of MakeFile ###############
