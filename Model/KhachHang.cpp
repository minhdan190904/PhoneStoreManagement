#ifndef KHACHHANG_CPP
#define KHACHHANG_CPP
#include "NGUOI.CPP"
#include "VALIDATE.CPP"
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

class KhachHang : public Nguoi {
protected:
    string maKhachHang;
    string ngayDangKy;
    int loaiKhachHang; 
    static int soMaKhachHang;

public:
    KhachHang();
    KhachHang(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, 
              string soDienThoai, string email, string ngayDangKy, int loaiKhachHang);
    void nhap();
    void xuat();
    string getMaKhachHang();
    ~KhachHang();
};

int KhachHang::soMaKhachHang = 0;

KhachHang::KhachHang() : Nguoi() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaKhachHang++;
    this->maKhachHang = "KH" + ss.str();
    this->ngayDangKy = "";
    this->loaiKhachHang = 0; 
}

KhachHang::KhachHang(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, 
                     string soDienThoai, string email, string ngayDangKy, int loaiKhachHang) : 
                     Nguoi(hoTen, ngaySinh, soCMND, diaChi, gioiTinh, soDienThoai, email) {
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaKhachHang++;
    this->maKhachHang = "KH" + ss.str();
    this->ngayDangKy = ngayDangKy;
    this->loaiKhachHang = loaiKhachHang;
}

void KhachHang::nhap() {
    Nguoi::nhap();

    do {
        cout << "Nhap ngay dang ky (dd/mm/yyyy): ";
        cin >> this->ngayDangKy;
    } while (!Validate::validateNgay(this->ngayDangKy));

    do {
        cout << "Nhap loai khach hang (0 hoặc 1): ";
        cin >> this->loaiKhachHang;
    } while (this->loaiKhachHang < 0 || this->loaiKhachHang > 1);
}

void KhachHang::xuat() {
    Nguoi::xuat();
    cout << "Ma khach hang: " << this->maKhachHang << endl;
    cout << "Ngay dang ky: " << this->ngayDangKy << endl;
    cout << "Loai khach hang: " << (this->loaiKhachHang == 0 ? "Thuong" : "VIP") << endl;
}

string KhachHang::getMaKhachHang() {
    return this->maKhachHang;
}

KhachHang::~KhachHang() {
}

#endif
