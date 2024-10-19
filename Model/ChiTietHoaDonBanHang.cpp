#ifndef CHITIETHOADONBANHANG_CPP
#define CHITIETHOADONBANHANG_CPP

#include <iostream>
#include "SanPham.CPP"

using namespace std;

class ChiTietHoaDonBanHang {
private:
    SanPham sanPham;
    int soLuong;
    double giaBan;

public:
    ChiTietHoaDonBanHang();
    ChiTietHoaDonBanHang(SanPham sp, int sl, double gia);
    
    void nhap();
    void xuat();
    
    double getThanhTien();
    SanPham getSanPham();
    int getSoLuong();
    double getGiaBan();
};

ChiTietHoaDonBanHang::ChiTietHoaDonBanHang() 
    : sanPham(), soLuong(0), giaBan(0.0) {}

ChiTietHoaDonBanHang::ChiTietHoaDonBanHang(SanPham sp, int sl, double gia) 
    : sanPham(sp), soLuong(sl), giaBan(gia) {
    int tonKho = sanPham.getSoLuong();
    if (tonKho == 0) {
        cout << "San pham nay da het hang. Khong the khoi tao!" << endl;
        return;
    }

    if (soLuong <= 0) {
        cout << "So luong phai lon hon 0. Gan so luong ve mac dinh la 1." << endl;
        soLuong = 1;
    } else if (soLuong > tonKho) {
        cout << "So luong nhap khong duoc lon hon so luong ton kho (" << tonKho << "). Gan so luong ve mac dinh la ton kho." << endl;
        soLuong = tonKho;
    }

    if (giaBan <= 0) {
        cout << "Gia ban phai lon hon 0. Gan gia ban ve mac dinh la 1." << endl;
        giaBan = 1.0;
    }
}

void ChiTietHoaDonBanHang::nhap() {
    sanPham.nhap();

    int tonKho = sanPham.getSoLuong();
    
    if (tonKho == 0) {
        cout << "San pham nay da het hang. Khong the nhap!" << endl;
        return;
    }

    cout << "Nhap so luong (max: " << tonKho << "): ";
    cin >> soLuong;

    if (soLuong <= 0) {
        cout << "So luong phai lon hon 0. Gan so luong ve mac dinh la 1." << endl;
        soLuong = 1;
    } else if (soLuong > tonKho) {
        cout << "So luong nhap khong duoc lon hon so luong ton kho (" << tonKho << "). Gan so luong ve mac dinh la ton kho." << endl;
        soLuong = tonKho;
    }

    cout << "Nhap gia ban: ";
    cin >> giaBan;

    if (giaBan <= 0) {
        cout << "Gia ban phai lon hon 0. Gan gia ban ve mac dinh la 1." << endl;
        giaBan = 1.0;
    }
}

void ChiTietHoaDonBanHang::xuat() {
    sanPham.xuat(); 
    cout << "So luong: " << soLuong << endl;
    cout << "Gia ban: " << giaBan << endl;
    cout << "Thanh tien: " << getThanhTien() << endl;
}

double ChiTietHoaDonBanHang::getThanhTien() {
    return soLuong * giaBan;
}

SanPham ChiTietHoaDonBanHang::getSanPham() {
    return sanPham;
}

int ChiTietHoaDonBanHang::getSoLuong() {
    return soLuong;
}

double ChiTietHoaDonBanHang::getGiaBan() {
    return giaBan;
}

#endif
