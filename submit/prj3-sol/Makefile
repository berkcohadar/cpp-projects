output: main.o job.o command.o command-stream.o
	g++ main.o job.o command.o command-stream.o -o nums

main.o: main.cc
	g++ -c main.cc

command.o: command.cc command.hh
	g++ -c command.cc

command-stream.o: command-stream.cc command-stream.hh
	g++ -c command-stream.cc

job.o: job.cc job.hh
	g++ -c job.cc

clean:
	rm *.o output
