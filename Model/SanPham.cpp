#ifndef SANPHAM_CPP
#define SANPHAM_CPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SanPham {
private:
    string maSanPham;
    string tenSanPham;
    string moTa;
    string danhMuc;
    int soLuong;

    static int soSanPham;
    static vector<string> listDanhMuc;

public:
    SanPham();
    SanPham(const string& tenSanPham, const string& moTa, int danhMucIndex);
    
    void nhap();
    void xuat();

    string getMaSanPham(); 
    string getTenSanPham();
    string getMoTa();
    string getDanhMuc();
    int getSoLuong();

    void setTenSanPham(const string& tenSanPham);
    void setMoTa(const string& moTa);
    void setDanhMuc(int danhMucIndex);
    void setSoLuong(int soLuong);  

    static void initListDanhMuc(); 

    ~SanPham();
};

int SanPham::soSanPham = 0;
vector<string> SanPham::listDanhMuc;

SanPham::SanPham() : soLuong(0) {
    stringstream ss;
    ss << setw(5) << setfill('0') << soSanPham++;
    this->maSanPham = "SP" + ss.str();
    this->tenSanPham = "";
    this->moTa = "";
    this->danhMuc = "";
}

SanPham::SanPham(const string& tenSanPham, const string& moTa, int danhMucIndex) 
    : soLuong(0) {
    initListDanhMuc();
    stringstream ss;
    ss << setw(5) << setfill('0') << soSanPham++;
    this->maSanPham = "SP" + ss.str();
    this->tenSanPham = tenSanPham;
    this->moTa = moTa;

    if (danhMucIndex >= 1 && danhMucIndex <= listDanhMuc.size()) {
        this->danhMuc = listDanhMuc[danhMucIndex - 1];
    } else {
        this->danhMuc = "";
    }
}

void SanPham::initListDanhMuc() {
    listDanhMuc.clear();
    listDanhMuc.push_back("Dien thoai");
    listDanhMuc.push_back("May tinh");
    listDanhMuc.push_back("Phu kien");
}

void SanPham::nhap() {
    initListDanhMuc();
    fflush(stdin);
    cout << "Nhap ten san pham: ";
    getline(cin, this->tenSanPham);
    cout << "Nhap mo ta: ";
    getline(cin, this->moTa);
    
    cout << "Chon danh muc (nhap so tu 1 den " << listDanhMuc.size() << "):" << endl;
    for (size_t i = 0; i < listDanhMuc.size(); ++i) {
        cout << i + 1 << ". " << listDanhMuc[i] << endl;
    }
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= listDanhMuc.size()) {
        this->danhMuc = listDanhMuc[choice - 1];
    } else {
        this->danhMuc = "";
    }
}

void SanPham::xuat() {
    cout << "Ma san pham: " << this->maSanPham << endl;
    cout << "Ten san pham: " << this->tenSanPham << endl;
    cout << "Mo ta: " << this->moTa << endl;
    cout << "Danh muc: " << this->danhMuc << endl;
    cout << "So luong: " << this->soLuong << endl;  
}

string SanPham::getMaSanPham() {
    return this->maSanPham;
}

string SanPham::getTenSanPham() {
    return this->tenSanPham;
}

string SanPham::getMoTa() {
    return this->moTa;
}

string SanPham::getDanhMuc() {
    return this->danhMuc;
}

int SanPham::getSoLuong() {
    return this->soLuong;
}

void SanPham::setTenSanPham(const string& tenSanPham) {
    this->tenSanPham = tenSanPham;
}

void SanPham::setMoTa(const string& moTa) {
    this->moTa = moTa;
}

void SanPham::setDanhMuc(int danhMucIndex) {
    if (danhMucIndex >= 1 && danhMucIndex <= listDanhMuc.size()) {
        this->danhMuc = listDanhMuc[danhMucIndex - 1];
    } else {
        this->danhMuc = "";
    }
}

void SanPham::setSoLuong(int soLuong) {
    this->soLuong = soLuong;
}

SanPham::~SanPham() {
}

#endif
