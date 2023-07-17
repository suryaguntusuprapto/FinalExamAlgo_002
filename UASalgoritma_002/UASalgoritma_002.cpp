#include <iostream>
#include <string>
using namespace std;
struct node {
	int noMhs;
	node* next;
	node* prev;
	string name;
	string jurusan;
	int tahunmasuk;
};
node* start = NULL;
	const int MAX_MAHASISWA = 100;
	int NIM[MAX_MAHASISWA];
	string nama[MAX_MAHASISWA];
	int tahunMasuk[MAX_MAHASISWA];
	int jumlahMahasiswa = 0;
	//isi disini
	void tambahMahasiswa() {
		int nim;
		string nama;
		string jrsn;
		int tm;
		node* nodeBaru = new node();
		cout << "Masukkan NIM: ";
		cin >> nim;
		cout << "Masukkan Nama: ";
		cin >> nama;
		cout << "Masukkan Jurusan: ";
		cin >> jrsn;
		cout << "Masukkan Tahun Masuk: ";
		cin >> tm;
		nodeBaru->noMhs = nim;
		nodeBaru->name = nama;
		nodeBaru->jurusan = jrsn;
		nodeBaru->tahunmasuk = tm;

		if (start == NULL || nim <= start->noMhs) {
			if (start != NULL && nim == start->noMhs) {
				cout << "NIM ditambahkan" << endl;
				return;
			}
			nodeBaru->next = start;
			start = nodeBaru;
		}
		node* previous = start;
		node* current = start;

		while ((current != NULL) && (nim >= current->noMhs)) {
			if (nim == current->noMhs) {
				cout << "NIM ditambahkan" << endl;
				return;
			}
			previous = current;
			current = current->next;
		}
		nodeBaru->next = current;
		previous->next = nodeBaru;

	}
	void tampilkanSemuaMahasiswa();
		//isi disini

	bool listempty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	
	void algorithmacariMahasiswaByNIM() {
		cout << "========Menu Cari Mahasiswa berdasarkan NIM========" << endl;
		if (listempty()) {
			cout << "List Kosong" << endl;
			return;
		}
		else {
			int nim;
			cout << "Masukkan NIM: ";
			cin >> nim;
			node* currentNode = start;
			while (currentNode->noMhs == nim) {
				if (currentNode->noMhs == nim) {
					cout << "NIM: " << currentNode->noMhs << endl << "NAMA: " << currentNode->name << endl << 
						"Jurusan: " << currentNode->jurusan << endl << "Tahun Masuk: " << currentNode->tahunmasuk << endl;
					return;
				}
				currentNode = currentNode->next;
			}
			cout << "Data Tidak Ditemukan" << endl;
		}
	}
	
	void algorithmaSortByTahunMasuk();

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			//isi disini
			tambahMahasiswa();
			break;
		case 2:
			//isi disini
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			//isi disini
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

//2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? (10 Poin)
//  jawaban: single linked list, 
//3. Jelaskan perbedaan mendasar antara algorithma stack dan queue!(15 Poin)
// jawaban:kalau prinsip kerja dari stack adalah LIFO (Last in-First Out) dimana elemen yang terakhir masuk adalah elemen yang pertama kali keluar
//         sedangkan kalau prinsip kerja queue yaitu FIFO (First In-First Out) dimana elemen yang pertama masuk adalah elemen yang pertama kali keluar 
//4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack ? (15 poin)
//      jawaban: ketika ingin memanfaatkan array sebagai basis penyimpanan dan ketika hanya ingin menambahkan elemen-elemennya dan yang dihapus hanya di satu ujung.
//5. Perhatikan gambar berikut: ( 20 Poin )
//  a.Seberapa banyak kedalaman yang dimiliki struktur tersebut ? 
//     jawaban: 10 parent dan 8 leaf node
//  b.Bagaimana cara membaca struktur pohon di atas ? (Pilih salah satu metode yaitu Inorder, Preorder atau Postorder Traversal)
//     jawawab: kalau menggunakan metode inorder cara membacanya dari cabang kiri lalu sudah tidak memiliki anak pindah ke root dan cabang sebelah kanan
//              struktur bacaan pada pohon tersebut adalah: 1,5,8,10,12,15,20,22,25,28,30,36,38,40,45,48,50