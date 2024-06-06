# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Jeti Aprilia</p>
<p align="center">2311110059</p>

## Dasar Teori
Dalam teori graf, terdapat konsep tree (pohon). Tree diartikan sebagai graf terhubung yang tidak memuat siklus. Konsep tree merupakan konsep yang penting karena konsep ini dapat digunakan untuk mendukung penerapan graf dalam berbagai bidang ilmu.


### 1. Graph
Berdasarkan orientasi arah pada sisi, graf dibedakan menjadi dua jenis orientasi arah yaitu graf berarah (directed graph) dan graf tak berarah (undirected graph). Graf yang sisinya tidak mempunyai orientasi arah dinamakan graf tak berarah.
Berdasarkan ada tidaknya gelang atau sisi ganda, graf dibedakan menjadi dua jenis, yaitu graf sederhana (simple graph) dan graf tak-sederhana 
(unsimple graph). Graf yang tidak mengandung gelang maupun sisi-ganda dinamakan graf sederhana. Sedangkan graf yang mengandung sisi ganda atau gelang dinamakan graf tak-sederhana.

### 2. Tree
Graf terhubung yang tidak memuat sebuah siklus dinamakan Tree (pohon).
Teorema 1
Misalkan adalah suatu graf dengan buah titik dan tepat sisi. Bila tidak memuat siklus, maka adalah pohon.

## Guided

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>
using namespace std;

    string simpul[7] ={"Ciamis",
                        "Bandung",
                        "Bekasi",
                        "Tasikmalaya",
                        "Cianjur",
                        "Purwokerto",
                        "Yogjakarta"};
int busur[7][7] =
{
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}};
void tampilGraph()
{
    for(int baris = 0; baris <7; baris ++){
        cout << " " << setiosflags(ios::left)<<setw(15)
        <<simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom ++){
            if (busur[ baris][kolom] !=0){
                cout << " " << simpul [kolom] << "("
                << busur[baris][kolom] << ")";
            }
        }cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
```

### 2. Program Tree
```C++
#include <iostream>
using namespace std;
// Definisi struktur pohon
struct pohon {
pohon* kanan;
char data;
pohon* kiri;
};
// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];
// Fungsi untuk inisialisasi root
void inisialisasi() {
root = NULL;
}
// Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
simpul = new pohon;
simpul->data = dataMasukkan;
simpul->kanan = NULL;
simpul->kiri = NULL;
}
// Fungsi untuk membuat simpul akar
void simpulAkar() {
if (root == NULL) {
char dataAnda;
cout << "Silahkan masukkan data: ";
cin >> dataAnda;
simpulBaru(dataAnda);
root = simpul;
cout << "Root terbentuk..." << endl;
} else {
cout << "Root sudah ada..." << endl;
}
}
// Fungsi untuk menambah simpul
void tambahSimpul() {
if (root != NULL) {
int i = 1, j = 1, penanda = 0;
char dataUser;
alamat[i] = root;
while (penanda == 0 && j < 256) {
cout << "Masukkan data kiri: ";
cin >> dataUser;
if (dataUser != '0') {
simpulBaru(dataUser);
saatIni = alamat[i];
saatIni->kiri = simpul;
j++;
alamat[j] = simpul;
} else {
penanda = 1;
j++;
alamat[j] = NULL;
}
if (penanda == 0) {
cout << "Masukkan data kanan: ";
cin >> dataUser;
if (dataUser != '0') {
simpulBaru(dataUser);
saatIni = alamat[i];
saatIni->kanan = simpul;
j++;
alamat[j] = simpul;
} else {
penanda = 1;
j++;
alamat[j] = NULL;
}
}
i++;
}
}
}
// Fungsi untuk membaca pohon
void bacaPohon() {
if (root != NULL) {
int i = 1, n = 1, pencacah = 0;
cout << endl;
while (alamat[i] != NULL) {
saatIni = alamat[i];
cout << saatIni->data << " ";
pencacah++;
if (pencacah == n) {
cout << endl;
pencacah = 0;
n = n * 2;
}
i++;
}
}
}
// Fungsi utama
int main() {
inisialisasi();
simpulAkar();
tambahSimpul();
bacaPohon();
return 0;
}
```

## Unguided 
*Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung
jarak dari sebuah kota ke kota lainnya.

```C++
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
```
#### Output:


### Penjelasan
Fungsi `minDistance` digunakan untuk menemukan node dan jarak mana yang paling pendek dan belum dikunjungi. Fungsi `printSolution` untuk mencetak jarak terpendek dengan mencantumkan kota asal ke setiap kota lain.
Fungsi `dijstra` untuk menghitung antara jarak kota asal ke kota lainnya. Fungsi `main` untuk menerima, untuk meminta input dari user, dan menghitung jarak terpendek.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree
dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

// Struktur data untuk node tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Fungsi untuk memasukkan data ke dalam tree secara level-order
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return new TreeNode(data);
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TreeNode(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TreeNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Fungsi untuk traversal preorder
void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Fungsi untuk traversal inorder
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Fungsi untuk traversal postorder
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Fungsi untuk menampilkan menu
void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Masukkan data ke dalam tree\n";
    cout << "2. Tampilkan tree dalam Preorder\n";
    cout << "3. Tampilkan tree dalam Inorder\n";
    cout << "4. Tampilkan tree dalam Postorder\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    TreeNode* root = NULL;
    int choice, data;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data (angka): ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
```
#### Output:


### Penjelasan
Untuk fungsinya dan kegunaan fungsi tidak beda jauh dengan Unguided 1, yang membedakan adalah jika Unguided 1 menghitung jarak terpendek namun di Unguided 2 menghitung jarak minimum.

## Kesimpulan
#### Hasil praktikum: 
Tree adalah suatu konsep yag terdapat dalam Graf. Graph dan Tree merupakan solusi yang efektif untuk menyelesaikan persoalan tentang jarak terpendek, jarak minimum, dll.

## Referensi
[1] Tito Nurdiyanto, Ely Susanti., “EFISIENSI PENGGUNAAN MATRIKS IN-DEGREE UNTUK MENGKONTRUKSI SPANNING-TREE PADA GRAF BERARAH”, 2019.

