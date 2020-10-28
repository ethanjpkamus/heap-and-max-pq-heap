rm *.o

echo "clang++ -std=c++17 -Wall sorts.cpp -o sorts.o"
clang++ -std=c++17 -Wall sorts.cpp -o sorts.o

echo "./sorts.o"
./sorts.o
