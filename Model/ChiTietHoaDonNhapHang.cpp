#ifndef CHITIETHOADONNHAPHANG_CPP
#define CHITIETHOADONNHAPHANG_CPP

#include "SanPham.CPP"
#include <iostream>

using namespace std;

class ChiTietHoaDonNhapHang {
private:
    SanPham sanPham;
    int soLuong;
    double giaNhap;

public:
    ChiTietHoaDonNhapHang(); 
    ChiTietHoaDonNhapHang(SanPham sp, int sl, double gia);
    
    void nhap();
    void xuat();
    
    double getThanhTien();
    SanPham getSanPham();
    int getSoLuong();
    double getGiaNhap();
    void setSanPham(SanPham sanpham);
};

ChiTietHoaDonNhapHang::ChiTietHoaDonNhapHang() : soLuong(0), giaNhap(0.0) {}

ChiTietHoaDonNhapHang::ChiTietHoaDonNhapHang(SanPham sp, int sl, double gia) 
    : sanPham(sp), soLuong(sl), giaNhap(gia) {}

void ChiTietHoaDonNhapHang::nhap() {
    cout << "Nhap so luong: ";
    cin >> soLuong;

    do {
        cout << "Nhap gia nhap: ";
        cin >> giaNhap;
        if (giaNhap <= 0) {
            cout << "Gia nhap phai lon hon 0. Vui long nhap lai!" << endl;
        }
    } while (giaNhap <= 0);
}

void ChiTietHoaDonNhapHang::xuat() {
    sanPham.xuat(); 
    cout << "So luong: " << soLuong << endl;
    cout << "Gia nhap: " << giaNhap << endl;
    cout << "Thanh tien: " << getThanhTien() << endl;
}

double ChiTietHoaDonNhapHang::getThanhTien() {
    return soLuong * giaNhap;
}

SanPham ChiTietHoaDonNhapHang::getSanPham() {
    return sanPham;
}

int ChiTietHoaDonNhapHang::getSoLuong() {
    return soLuong;
}

double ChiTietHoaDonNhapHang::getGiaNhap() {
    return giaNhap;
}

void ChiTietHoaDonNhapHang::setSanPham(SanPham sanpham) {
    sanPham = sanpham;
}

#endif
