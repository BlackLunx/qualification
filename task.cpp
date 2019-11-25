#include "task.h"
#include<bits/stdc++.h>

using namespace std;

void performQueries(int32_t nRows, int32_t nCols, int32_t nQueries, int32_t nRes, double* data, int32_t* queries, double* result)
{
    // Reference unoptimized code, replace it with your solution
    std::vector<bool> used(nQueries, 0);
    auto check = [&](int queryId){
        if(used[queryId]) return;
        used[queryId] = 1;
        int32_t diff = queryId << 2;
        int32_t rowA = queries[diff];
        int32_t colA = queries[diff + 1];
        int32_t rowB = queries[diff + 2];
        int32_t colB = queries[diff + 3];
        for(int32_t col = 0; col < nRes; ++col)
        {
            for (int32_t row = 0; row < nRes; ++row)
            {
                int32_t cRowA = rowA + row;
                int32_t cColA = colA + col;
                int32_t cRowB = rowB + row;
                int32_t cColB = colB + col;
                result[row * nRes + col] += data[cRowA * nCols + cColA] * data[cRowB * nCols + cColB];
            }
        }
        return;
    };
    int query = 0;
    #pragma omp parallel
    {
        #pragma for shared(result) private(queries, data, query)  reduction(+:result) schedule(guided)
        for(query = 0; query < nQueries; query++)
            check(query);
    }

    #pragma omp barrier
   
    // Reference unoptimized code, replace it with your solution
}