#include <iostream>
#include <string> // dengan menggunakan std::string

// Mendefinisikan struct buku
struct buku {
    std::string judulBuku;
    std::string pengarang;
    std::string penerbit;
    int tebalHalaman;
    float hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    struct buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    std::cout << "\tBuku Favorit Saya" << std::endl;
    std::cout << "\tJudul Buku : " << favorit.judulBuku << std::endl;
    std::cout << "\tPengarang : " << favorit.pengarang << std::endl;
    std::cout << "\tPenerbit : " << favorit.penerbit << std::endl;
    std::cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << std::endl;
    std::cout << "\tHarga Buku : Rp " << favorit.hargaBuku << std::endl;

    return 0;
}