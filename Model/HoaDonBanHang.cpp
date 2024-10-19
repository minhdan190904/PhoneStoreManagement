#ifndef HOADONBANHANG_CPP
#define HOADONBANHANG_CPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "KhachHang.CPP"
#include "ChiTietHoaDonBanHang.CPP"

using namespace std;

class HoaDonBanHang {
private:
    string maHoaDon;
    string ngayBan;
    KhachHang khachHang;
    vector<ChiTietHoaDonBanHang> danhSachChiTiet;
    double tongTien;

    static int soHoaDon;

public:
    HoaDonBanHang();
    HoaDonBanHang(const string& ngayBan, const KhachHang& khachHang, const vector<ChiTietHoaDonBanHang>& danhSachChiTiet);
    void nhap();
    void xuat();
    string getMaHoaDon();
    double getTongTien();
    vector<ChiTietHoaDonBanHang> getDanhSachChiTiet();
    ~HoaDonBanHang();
};

int HoaDonBanHang::soHoaDon = 0;

HoaDonBanHang::HoaDonBanHang() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soHoaDon++;
    this->maHoaDon = "HDBH" + ss.str();
    this->ngayBan = "";
    this->tongTien = 0.0;
}

HoaDonBanHang::HoaDonBanHang(const string& ngayBan, const KhachHang& khachHang, const vector<ChiTietHoaDonBanHang>& danhSachChiTiet) 
    : ngayBan(ngayBan), khachHang(khachHang), danhSachChiTiet(danhSachChiTiet), tongTien(0.0) {
    stringstream ss;
    ss << setw(5) << setfill('0') << soHoaDon++;
    this->maHoaDon = "HDBH" + ss.str();
    
    for (auto chiTiet : danhSachChiTiet) {
        tongTien += chiTiet.getThanhTien();
    }
}

void HoaDonBanHang::nhap() {
    cout << "Nhap ngay ban (dd/mm/yyyy): ";
    getline(cin, this->ngayBan);
    khachHang.nhap();
    int soSanPham;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cin.ignore();
    for (int i = 0; i < soSanPham; ++i) {
        ChiTietHoaDonBanHang chiTiet;
        chiTiet.nhap();
        danhSachChiTiet.push_back(chiTiet);
        tongTien += chiTiet.getThanhTien();
    }
}

void HoaDonBanHang::xuat() {
    cout << "Ma hoa don: " << maHoaDon << endl;
    cout << "Ngay ban: " << ngayBan << endl;
    cout << "Khach hang: "; 
    khachHang.xuat();
    cout << "Chi tiet hoa don ban:" << endl;
    for (auto chiTiet : danhSachChiTiet) {
        chiTiet.xuat();
    }
    cout << "Tong tien: " << tongTien << endl;
}

string HoaDonBanHang::getMaHoaDon() {
    return this->maHoaDon;
}

double HoaDonBanHang::getTongTien() {
    return this->tongTien;
}

vector<ChiTietHoaDonBanHang> HoaDonBanHang::getDanhSachChiTiet() {
    return this->danhSachChiTiet;
}

HoaDonBanHang::~HoaDonBanHang() {
}

#endif
