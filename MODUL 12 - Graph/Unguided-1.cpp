#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Graph {
    vector<string> simpul_graph;
    vector<vector<int>> bobot_graph;
};

int main() {
    int jumlah_simpul;
    int nama_2311110018;
    
    cout << "Masukkan Jumlah Simpul: ";
    cin >> jumlah_simpul;
    
    Graph graf;
    graf.simpul_graph.resize(jumlah_simpul);
    graf.bobot_graph.resize(jumlah_simpul, vector<int>(jumlah_simpul));
    
    cout << "Masukkan Nama Simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> graf.simpul_graph[i];
    }
    
    cout << "Masukkan Bobot Antar Simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << graf.simpul_graph[i] << "-->" << graf.simpul_graph[j] << " = ";
            cin >> graf.bobot_graph[i][j];
        }
    }
    
    
    cout << "\t";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << graf.simpul_graph[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << graf.simpul_graph[i] << "\t";
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << graf.bobot_graph[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
