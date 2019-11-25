#include "task.h"
#include<bits/stdc++.h>
#include "omp.h"
using namespace std;

void performQueries(int32_t nRows, int32_t nCols, int32_t nQueries, int32_t nRes, double* data, int32_t* queries, double* result)
{
    // Reference unoptimized code, replace it with your solution
    std::vector<bool> used(nQueries, 0);
    auto check = [&](int queryId, vector<double> &current_result){
        if(used[queryId]) return;
        used[queryId] = 1;
        int32_t diff = queryId << 2;
        short rowA = queries[diff];
        short colA = queries[diff + 1];
        short rowB = queries[diff + 2];
        short colB = queries[diff + 3];
        for(short col = 0; col < nRes; ++col)
        {
            for (short row = 0; row < nRes; ++row)
            {
                short cRowA = rowA + row;
                short cColA = colA + col;
                short cRowB = rowB + row;
                short cColB = colB + col;
                current_result[row * nRes + col] += data[cRowA * nCols + cColA] * data[cRowB * nCols + cColB];
            }
        }
        return;
    };
    int query = 0;
    omp_set_num_threads(omp_get_max_threads());
    
    #pragma omp parallel 
    {
        vector<double> current_result(nRes * nRes, 0);
        #pragma for private(query) schedule(static)
        for(query = 0; query < nQueries; ++query)
            check(query, current_result);
            
        for (short i = 0; i < nRes; i++){
            for(short j = 0; j < nRes; j++){
                short ind = i * nRes + j;
                #pragma omp atomic
                result[ind] += current_result[ind];
            }
        }
    }

    #pragma omp barrier
    // Reference unoptimized code, replace it with your solution
}