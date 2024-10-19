#ifndef QUANLYCUAHANGDIENTHOAI_CPP
#define QUANLYCUAHANGDIENTHOAI_CPP

#include "SANPHAM.cpp"
#include "KHACHHANG.cpp"
#include "HOADONBANHANG.cpp"
#include "HOADONNHAPHANG.cpp"
#include "NHACUNGCAP.cpp"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class QuanLyCuaHangDienThoai {
private:
    vector<SanPham> danhSachSanPham;
    vector<KhachHang> danhSachKhachHang;
    vector<HoaDonBanHang> danhSachHoaDonBan;
    vector<HoaDonNhapHang> danhSachHoaDonNhap;
    vector<NhaCungCap> danhSachNhaCungCap;

public:
    QuanLyCuaHangDienThoai();
    
    void xuat();
    void xuatDanhSachSanPham();
    void xuatDanhSachKhachHang();
    void xuatDanhSachHoaDonBan();
    void xuatDanhSachHoaDonNhap();
    void xuatDanhSachNhaCungCap();

    vector<SanPham> getDanhSachSanPham();
    vector<KhachHang> getDanhSachKhachHang();
    vector<HoaDonBanHang> getDanhSachHoaDonBan();
    vector<HoaDonNhapHang> getDanhSachHoaDonNhap();
    vector<NhaCungCap> getDanhSachNhaCungCap();

    SanPham& timSanPham(string maSanPham);
    KhachHang& timKhachHang(string maKhachHang);
    NhaCungCap& timNhaCungCap(string maNhaCungCap);

    void themSanPhamTuFile(string tenFile);
    void themKhachHangTuFile(string tenFile);
    void themHoaDonBan(HoaDonBanHang hoaDon);
    void themHoaDonNhap(HoaDonNhapHang hoaDon);
    void themNhaCungCap(NhaCungCap nhaCungCap);
    
    void xoaSanPham(string maSanPham);
    void xoaKhachHang(string maKhachHang);

    void themSanPham(SanPham& sanPham);
    void themKhachHang(KhachHang& khachHang);
    
    ~QuanLyCuaHangDienThoai();
};

QuanLyCuaHangDienThoai::QuanLyCuaHangDienThoai() {
}

void QuanLyCuaHangDienThoai::xuat() {
    this->xuatDanhSachSanPham();
    cout << endl;
    this->xuatDanhSachKhachHang();
    cout << endl;
    this->xuatDanhSachHoaDonBan();
    cout << endl;
    this->xuatDanhSachHoaDonNhap();
    cout << endl;
    this->xuatDanhSachNhaCungCap();
}

void QuanLyCuaHangDienThoai::xuatDanhSachSanPham() {
    for (auto sanPham : this->danhSachSanPham) {
        sanPham.xuat();
        cout << endl;
    }
}

void QuanLyCuaHangDienThoai::xuatDanhSachKhachHang() {
    for (auto khachHang : this->danhSachKhachHang) {
        khachHang.xuat();
        cout << endl;
    }
}

void QuanLyCuaHangDienThoai::xuatDanhSachHoaDonBan() {
    for (auto hoaDon : this->danhSachHoaDonBan) {
        hoaDon.xuat();
        cout << endl;
    }
}

void QuanLyCuaHangDienThoai::xuatDanhSachHoaDonNhap() {
    for (auto hoaDon : this->danhSachHoaDonNhap) {
        hoaDon.xuat();
        cout << endl;
    }
}

void QuanLyCuaHangDienThoai::xuatDanhSachNhaCungCap() {
    for (auto nhaCungCap : this->danhSachNhaCungCap) {
        nhaCungCap.xuat();
        cout << endl;
    }
}

vector<SanPham> QuanLyCuaHangDienThoai::getDanhSachSanPham() {
    return this->danhSachSanPham;
}

vector<KhachHang> QuanLyCuaHangDienThoai::getDanhSachKhachHang() {
    return this->danhSachKhachHang;
}

vector<HoaDonBanHang> QuanLyCuaHangDienThoai::getDanhSachHoaDonBan() {
    return this->danhSachHoaDonBan;
}

vector<HoaDonNhapHang> QuanLyCuaHangDienThoai::getDanhSachHoaDonNhap() {
    return this->danhSachHoaDonNhap;
}

vector<NhaCungCap> QuanLyCuaHangDienThoai::getDanhSachNhaCungCap() {
    return this->danhSachNhaCungCap;
}

SanPham& QuanLyCuaHangDienThoai::timSanPham(string maSanPham) {
    for (auto& sanPham : this->danhSachSanPham) {
        if (sanPham.getMaSanPham() == maSanPham) {
            return sanPham;
        }
    }
    throw "Khong tim thay san pham";
}

KhachHang& QuanLyCuaHangDienThoai::timKhachHang(string maKhachHang) {
    for (auto& khachHang : this->danhSachKhachHang) {
        if (khachHang.getMaKhachHang() == maKhachHang) {
            return khachHang;
        }
    }
    throw "Khong tim thay khach hang";
}

NhaCungCap& QuanLyCuaHangDienThoai::timNhaCungCap(string maNhaCungCap) {
    for (auto& nhaCungCap : this->danhSachNhaCungCap) {
        if (nhaCungCap.getMaNhaCungCap() == maNhaCungCap) {
            return nhaCungCap;
        }
    }
    throw "Khong tim thay nha cung cap";
}

void QuanLyCuaHangDienThoai::themSanPhamTuFile(string tenFile) {
    fstream file;
    file.open(tenFile, ios::in);
    if (file.is_open()) {
        string tenSanPham;
        string moTa;
        string danhMuc;

        while (getline(file, tenSanPham) && getline(file, moTa) && getline(file, danhMuc)) {
            SanPham sanPham(tenSanPham, moTa, stoi(danhMuc));
            this->danhSachSanPham.push_back(sanPham);
        }
        file.close();
    } else {
        cerr << "Khong the mo file: " << tenFile << endl;
    }
}



void QuanLyCuaHangDienThoai::themKhachHangTuFile(string tenFile) {
    fstream file;
    file.open(tenFile, ios::in);
    if (file.is_open()) {
        string maKhachHang, hoTenKhachHang, ngaySinh, soCMND, diaChiKhachHang, soDienThoaiKhachHang, email, ngayDangKy, gioiTinh;
        string loaiKhachHang;

        while (getline(file, maKhachHang) &&
               getline(file, hoTenKhachHang) &&
               getline(file, ngaySinh) &&
               getline(file, soCMND) &&
               getline(file, diaChiKhachHang) &&
               getline(file, gioiTinh) &&
               getline(file, soDienThoaiKhachHang) &&
               getline(file, email) &&
               getline(file, ngayDangKy) &&
            getline(file, loaiKhachHang)) {
            
            file.ignore();
            KhachHang khachHang(hoTenKhachHang, ngaySinh, soCMND, diaChiKhachHang, stoi(gioiTinh), soDienThoaiKhachHang, email, ngayDangKy, stoi(loaiKhachHang));
            this->danhSachKhachHang.push_back(khachHang);
        }
        file.close();
    } else {
        cerr << "Khong the mo file: " << tenFile << endl;
    }
}



void QuanLyCuaHangDienThoai::themHoaDonBan(HoaDonBanHang hoaDon) {
    this->danhSachHoaDonBan.push_back(hoaDon);
    for(auto chiTiet : hoaDon.getDanhSachChiTiet()) {
        SanPham& sanPham = this->timSanPham(chiTiet.getSanPham().getMaSanPham());
        sanPham.setSoLuong(sanPham.getSoLuong() - chiTiet.getSoLuong());
    }
}

void QuanLyCuaHangDienThoai::themHoaDonNhap(HoaDonNhapHang hoaDon) {
    this->danhSachHoaDonNhap.push_back(hoaDon);
    for(auto chiTiet : hoaDon.getDanhSachChiTiet()) {
        SanPham& sanPham = this->timSanPham(chiTiet.getSanPham().getMaSanPham());
        sanPham.setSoLuong(sanPham.getSoLuong() + chiTiet.getSoLuong());
    }
}

void QuanLyCuaHangDienThoai::themNhaCungCap(NhaCungCap nhaCungCap) {
    this->danhSachNhaCungCap.push_back(nhaCungCap);
}

void QuanLyCuaHangDienThoai::xoaSanPham(string maSanPham) {
    for (auto it = danhSachSanPham.begin(); it != danhSachSanPham.end(); ++it) {
        if (it->getMaSanPham() == maSanPham) {
            danhSachSanPham.erase(it);
            return;
        }
    }
    throw "Khong tim thay san pham de xoa";
}

void QuanLyCuaHangDienThoai::xoaKhachHang(string maKhachHang) {
    for (auto it = danhSachKhachHang.begin(); it != danhSachKhachHang.end(); ++it) {
        if (it->getMaKhachHang() == maKhachHang) {
            danhSachKhachHang.erase(it);
            return;
        }
    }
    throw "Khong tim thay khach hang de xoa";
}

void QuanLyCuaHangDienThoai::themSanPham(SanPham& sanPham) {
    this->danhSachSanPham.push_back(sanPham);
}

void QuanLyCuaHangDienThoai::themKhachHang(KhachHang& khachHang) {
    this->danhSachKhachHang.push_back(khachHang);
}

QuanLyCuaHangDienThoai::~QuanLyCuaHangDienThoai() {
}

#endif
