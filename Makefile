static: mainSt.c libVector.a
	gcc -c mainSt.c
	gcc -o static mainSt.o -L. -lVector

libVector.a: MyVector.c
	gcc -c MyVector.c
	ar cr libVector.a MyVector.o



dynamic: mainDy.c MyVector.c
	gcc -fPIC -c MyVector.c
	gcc -shared MyVector.o -o libVector.so
	gcc mainDy.c -ldl -o dynamic

clean:
	rm -rf static libVector.so dynamic libVector.a *.o