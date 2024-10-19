#ifndef HOADONNHAPHANG_CPP
#define HOADONNHAPHANG_CPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "NhaCungCap.CPP"
#include "ChiTietHoaDonNhapHang.CPP"

using namespace std;

class HoaDonNhapHang {
private:
    string maHoaDon;
    string ngayNhap;
    NhaCungCap nhaCungCap;
    vector<ChiTietHoaDonNhapHang> danhSachChiTiet;
    double tongTien;

    static int soHoaDon;

public:
    HoaDonNhapHang();
    HoaDonNhapHang(const string& ngayNhap, const NhaCungCap& nhaCungCap, const vector<ChiTietHoaDonNhapHang>& danhSachChiTiet);
    void nhap();
    void xuat();
    string getMaHoaDon();
    double getTongTien();
    ~HoaDonNhapHang();
};

int HoaDonNhapHang::soHoaDon = 0;

HoaDonNhapHang::HoaDonNhapHang() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soHoaDon++;
    this->maHoaDon = "HDNH" + ss.str();
    this->ngayNhap = "";
    this->tongTien = 0.0;
}

HoaDonNhapHang::HoaDonNhapHang(const string& ngayNhap, const NhaCungCap& nhaCungCap, const vector<ChiTietHoaDonNhapHang>& danhSachChiTiet) 
    : ngayNhap(ngayNhap), nhaCungCap(nhaCungCap), danhSachChiTiet(danhSachChiTiet), tongTien(0.0) {
    stringstream ss;
    ss << setw(5) << setfill('0') << soHoaDon++;
    this->maHoaDon = "HDNH" + ss.str();
    
    for (auto chiTiet : danhSachChiTiet) {
        tongTien += chiTiet.getThanhTien();
    }
}

void HoaDonNhapHang::nhap() {
    cout << "Nhap ngay nhap (dd/mm/yyyy): ";
    getline(cin, this->ngayNhap);
    nhaCungCap.nhap();
    int soSanPham;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cin.ignore();
    for (int i = 0; i < soSanPham; ++i) {
        ChiTietHoaDonNhapHang chiTiet;
        chiTiet.nhap();
        danhSachChiTiet.push_back(chiTiet);
        tongTien += chiTiet.getThanhTien();
    }
}

void HoaDonNhapHang::xuat() {
    cout << "Ma hoa don: " << maHoaDon << endl;
    cout << "Ngay nhap: " << ngayNhap << endl;
    cout << "Nha cung cap: "; 
    nhaCungCap.xuat();
    cout << "Chi tiet hoa don nhap:" << endl;
    for (auto chiTiet : danhSachChiTiet) {
        chiTiet.xuat();
    }
    cout << "Tong tien: " << tongTien << endl;
}

string HoaDonNhapHang::getMaHoaDon() {
    return this->maHoaDon;
}

double HoaDonNhapHang::getTongTien() {
    return this->tongTien;
}

HoaDonNhapHang::~HoaDonNhapHang() {
}

#endif
