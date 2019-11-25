#include "task.h"
#include<bits/stdc++.h>
#include "omp.h"
using namespace std;

void performQueries(int32_t nRows, int32_t nCols, int32_t nQueries, int32_t nRes, double* data, int32_t* queries, double* result)
{
    // Reference unoptimized code, replace it with your solution
//    bool* used = new bool[nQueries];
//    memset(used, 0, nQueries);
      vector<bool> used(nQueries, 0);
//    const int sz = 20000000;
//    bitset<sz> used(0);
    auto check = [&](int queryId, double* current_result){
        if(used[queryId]) return;
        used[queryId] = true;
        int32_t diff = queryId << 2;
        short rowA = queries[diff];
        short colA = queries[diff + 1];
        short rowB = queries[diff + 2];
        short colB = queries[diff + 3];
        for(short col = 0; col < nRes; ++col){
            for (short row = 0; row < nRes; ++row){
                int32_t cRowA = rowA + row;
                int32_t cColA = colA + col;
                int32_t cRowB = rowB + row;
                int32_t cColB = colB + col;
                current_result[row * nRes + col] += data[cRowA * nCols + cColA] * data[cRowB * nCols + cColB];
            }
        }
        return;
    };
    omp_set_num_threads(omp_get_max_threads());
    short len = nRes * nRes;
    #pragma omp parallel
    {
        double* current_result = new double[len];
        memset(current_result, 0, len);
//        vector<double> current_result(len, 0);
        #pragma omp for schedule(static)
        for(int query = 0; query < nQueries; ++query)
            check(query, current_result);

        for (short ind = 0; ind < len; ++ind){
            #pragma omp atomic
            result[ind] += current_result[ind];
        }
        delete[] current_result;
    }

    #pragma omp barrier
    // Reference unoptimized code, replace it with your solution
}
