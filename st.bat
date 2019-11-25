g++ -c -O3 -std=c++17 -fopenmp task.cpp
g++ -O3 -std=c++17 -fopenmp executor.cpp task.o -o executor.out
executor.out 10000 10000 100000 128 1 output_10k_10k_100k_128_1
executor.out 10000 10000 1000000 128 1 output_10k_10k_1M_128_1