build:
	gcc main.c task1.c task2.c task3.c task4.c task5.c -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty