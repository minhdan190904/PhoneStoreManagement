#ifndef NHACUNGCAP_CPP
#define NHACUNGCAP_CPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "VALIDATE.CPP"

using namespace std;

class NhaCungCap {
private:
    string maNhaCungCap;
    string tenNhaCungCap;
    string diaChi;
    string soDienThoai;
    string email;

    static int soNhaCungCap;

public:
    NhaCungCap();
    NhaCungCap(string tenNhaCungCap, string diaChi, string soDienThoai, string email);

    void nhap();
    void xuat();

    string getMaNhaCungCap();
    string getTenNhaCungCap();
    string getDiaChi();
    string getSoDienThoai();
    string getEmail();

    void setTenNhaCungCap(const string& tenNhaCungCap);
    void setDiaChi(const string& diaChi);
    void setSoDienThoai(const string& soDienThoai);
    void setEmail(const string& email);

    ~NhaCungCap();
};

int NhaCungCap::soNhaCungCap = 0;

NhaCungCap::NhaCungCap() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soNhaCungCap++;
    this->maNhaCungCap = "NCC" + ss.str();
    this->tenNhaCungCap = "";
    this->diaChi = "";
    this->soDienThoai = "";
    this->email = "";
}

NhaCungCap::NhaCungCap(string tenNhaCungCap, string diaChi, string soDienThoai, string email) {
    stringstream ss;
    ss << setw(5) << setfill('0') << soNhaCungCap++;
    this->maNhaCungCap = "NCC" + ss.str();
    this->tenNhaCungCap = tenNhaCungCap;
    this->diaChi = diaChi;
    this->soDienThoai = soDienThoai;
    this->email = email;
}

void NhaCungCap::nhap() {
    cout << "Nhap ten nha cung cap: ";
    getline(cin, this->tenNhaCungCap);

    cout << "Nhap dia chi: ";
    getline(cin, this->diaChi);

    do {
        cout << "Nhap so dien thoai (10 so): ";
        getline(cin, this->soDienThoai);
        if (!Validate::validateSoDienThoai(this->soDienThoai)) {
            cout << "So dien thoai khong hop le. Vui long nhap lai." << endl;
        }
    } while (!Validate::validateSoDienThoai(this->soDienThoai));

    do {
        cout << "Nhap email: ";
        getline(cin, this->email);
        if (!Validate::validateEmail(this->email)) {
            cout << "Email khong hop le. Vui long nhap lai." << endl;
        }
    } while (!Validate::validateEmail(this->email));
}

void NhaCungCap::xuat() {
    cout << "Ma nha cung cap: " << this->maNhaCungCap << endl;
    cout << "Ten nha cung cap: " << this->tenNhaCungCap << endl;
    cout << "Dia chi: " << this->diaChi << endl;
    cout << "So dien thoai: " << this->soDienThoai << endl;
    cout << "Email: " << this->email << endl;
}

string NhaCungCap::getMaNhaCungCap() {
    return this->maNhaCungCap;
}

string NhaCungCap::getTenNhaCungCap() {
    return this->tenNhaCungCap;
}

string NhaCungCap::getDiaChi() {
    return this->diaChi;
}

string NhaCungCap::getSoDienThoai() {
    return this->soDienThoai;
}

string NhaCungCap::getEmail() {
    return this->email;
}

void NhaCungCap::setTenNhaCungCap(const string& tenNhaCungCap) {
    this->tenNhaCungCap = tenNhaCungCap;
}

void NhaCungCap::setDiaChi(const string& diaChi) {
    this->diaChi = diaChi;
}

void NhaCungCap::setSoDienThoai(const string& soDienThoai) {
    this->soDienThoai = soDienThoai;
}

void NhaCungCap::setEmail(const string& email) {
    this->email = email;
}

NhaCungCap::~NhaCungCap() {
}

#endif
