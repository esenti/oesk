NUM=4
CFLAGS=

compile:
	g++ -std=c++11 -O0 $(CFLAGS) main.cpp

rep:
	cd report && pdflatex report.tex

run: compile
	./run.sh $(NUM)
