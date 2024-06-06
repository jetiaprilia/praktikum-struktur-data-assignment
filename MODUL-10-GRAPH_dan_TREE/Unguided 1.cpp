#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int NIM_2311110059

// Fungsi untuk menemukan node dengan jarak terpendek yang belum dikunjungi
int minDistance(const vector<int>& dist, const vector<bool>& visited, int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Fungsi untuk mencetak jarak dari kota asal ke semua kota lainnya
void printSolution(const vector<int>& dist, int n) {
    cout << "Jarak dari kota asal ke kota lainnya:\n";
    for (int i = 0; i < n; i++)
        cout << "Kota " << i << ": " << dist[i] << endl;
}

// Fungsi untuk menghitung jarak terpendek menggunakan algoritma Dijkstra
void dijkstra(const vector<vector<int>>& graph, int src, int n) {
    vector<int> dist(n, INT_MAX);     // Jarak dari sumber ke node lainnya
    vector<bool> visited(n, false);   // visited[i] akan menjadi true jika node i termasuk dalam solusi terpendek

    // Jarak ke node sumber adalah 0
    dist[src] = 0;

    // Temukan jalur terpendek untuk semua node
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);

        // Tandai node yang dipilih sebagai telah dikunjungi
        visited[u] = true;

        // Update nilai dist dari node tetangga dari node yang dipilih
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Cetak jarak terpendek dari sumber
    printSolution(dist, n);
}

int main() {
    NIM_12345678 = 22102003; // Ganti dengan NIM Anda
    int n, src;
    cout << "Masukkan jumlah kota: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Masukkan matriks jarak antar kota (masukkan 0 jika tidak ada jalur langsung):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Masukkan kota asal (dalam bentuk indeks mulai dari 0): ";
    cin >> src;

    dijkstra(graph, src, n);

    return 0;
}
