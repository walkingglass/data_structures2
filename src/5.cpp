#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    const double seek = 0.08;        // seconds
    const double latency = 0.02;     // seconds
    const double transmission = 0.001; // seconds per record
    const int n = 200000;
    const int m = 64;

    ofstream fout("t_input_vs_k.csv");
    fout << "k,t_input\n";

    for (int k = 2; k <= 64; ++k) {
        int passes = ceil(log(m) / log(k));
        double t_input = passes * (m * (seek + latency) + n * transmission);
        fout << k << "," << t_input << "\n";
    }

    fout.close();
    cout << "輸出完成：t_input_vs_k.csv" << endl;
    return 0;
}
