#ifndef CHITIETDONBANHANG_CPP
#define CHITIETDONBANHANG_CPP

#include <iostream>
#include "SanPham.CPP"

using namespace std;

class ChiTietDonBanHang {
private:
    SanPham sanPham;
    int soLuong;
    double giaBan;

public:
    ChiTietDonBanHang(SanPham sp, int sl, double gia);
    
    void nhap();
    void xuat();
    
    double getThanhTien();
    SanPham getSanPham();
    int getSoLuong();
    double getGiaBan();
};

ChiTietDonBanHang::ChiTietDonBanHang(SanPham sp, int sl, double gia) 
    : sanPham(sp), soLuong(sl), giaBan(gia) {}

void ChiTietDonBanHang::nhap() {
    sanPham.nhap(); 
    cout << "Nhap so luong: ";
    cin >> soLuong;

    do {
        cout << "Nhap gia ban: ";
        cin >> giaBan;
        if (giaBan <= 0) {
            cout << "Gia ban phai lon hon 0. Vui long nhap lai!" << endl;
        }
    } while (giaBan <= 0);
}

void ChiTietDonBanHang::xuat() {
    sanPham.xuat(); 
    cout << "So luong: " << soLuong << endl;
    cout << "Gia ban: " << giaBan << endl;
    cout << "Thanh tien: " << getThanhTien() << endl;
}

double ChiTietDonBanHang::getThanhTien() {
    return soLuong * giaBan;
}

SanPham ChiTietDonBanHang::getSanPham() {
    return sanPham;
}

int ChiTietDonBanHang::getSoLuong() {
    return soLuong;
}

double ChiTietDonBanHang::getGiaBan() {
    return giaBan;
}

#endif
