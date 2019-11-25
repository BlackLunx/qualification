# qualification

Чтобы запустить на тестах писать:
1. g++ -c -O3 -std=c++17 -fopenmp task.cpp
2. g++ -O3 -std=c++17 -fopenmp executor.cpp task.o -o executor.out
3. ./executor.out nRows nCols nQueries nRes seed [путь_к_файлу_с_правильным_ответом] 


ВАРИАНТЫ ДЛЯ 3ГО 
1) output_10k_10k_100k_128_1 – правильный ответ для запуска с параметрами
./executor.out 10000 10000 100000 128 1
2) output_10k_10k_1m_128_1 – правильный ответ для запуска с параметрами
./executor.out 10000 10000 1000000 128 1
3) output_10k_10k_10m_128_1 – правильный ответ для запуска с параметрами
./executor.out 10000 10000 10000000 128 1
