#include <iostream>
#include "Model/QuanLyCuaHangDienThoai.cpp"

using namespace std;

int main() {
    QuanLyCuaHangDienThoai quanLyCuaHangDienThoai;

    cout << "Them thong tin nha cung cap" << endl;
    NhaCungCap nhaCungCap = NhaCungCap();
    nhaCungCap.nhap();
    quanLyCuaHangDienThoai.themNhaCungCap(nhaCungCap);
    nhaCungCap.xuat();

    cout << "Them thong tin san pham" << endl;
    SanPham sanPham = SanPham();
    sanPham.nhap();
    quanLyCuaHangDienThoai.themSanPham(sanPham);
    sanPham.xuat();


    HoaDonNhapHang hoaDonNhapHang = HoaDonNhapHang();
    cout << "Them thong tin hoa don ban hang" << endl;
    hoaDonNhapHang.nhap();
    cout << "Nhap ma nha cung cap: ";
    string maNhaCungCap;
    cin >> maNhaCungCap;
    nhaCungCap = quanLyCuaHangDienThoai.timNhaCungCap(maNhaCungCap);
    hoaDonNhapHang.setNhaCungCap(nhaCungCap);
    quanLyCuaHangDienThoai.themHoaDonNhap(hoaDonNhapHang);
    int soLuongSanPham;
    cout << "Nhap so luong san pham: ";
    cin >> soLuongSanPham;
    vector<ChiTietHoaDonNhapHang> list;
    for (int i = 0; i < soLuongSanPham; i++) {
        ChiTietHoaDonNhapHang chiTietHoaDonNhapHang;
        string maSanPham;
        cout<<"Nhap ma san pham can tim" <<endl;
        cin>>maSanPham;
        SanPham sp = quanLyCuaHangDienThoai.timSanPham(maSanPham);
        chiTietHoaDonNhapHang.setSanPham(sp);
        chiTietHoaDonNhapHang.nhap();
        list.push_back(chiTietHoaDonNhapHang);
    }
    hoaDonNhapHang.setDanhSachChiTiet(list);
    quanLyCuaHangDienThoai.themHoaDonNhap(hoaDonNhapHang);
    quanLyCuaHangDienThoai.xuatDanhSachSanPham();

    // KhachHang khachHang;
    // khachHang.nhap();
    // quanLyCuaHangDienThoai.themKhachHang(khachHang);
    // quanLyCuaHangDienThoai.xuatDanhSachKhachHang();
    // SanPham sanPham;
    // sanPham.nhap();
    // quanLyCuaHangDienThoai.themSanPham(sanPham);
    // quanLyCuaHangDienThoai.xuatDanhSachSanPham();
    // vector<ChiTietHoaDonNhapHang> danhSachChiTiet(2);
    // for (int i = 0; i < 2; i++) {
    //     danhSachChiTiet[i].nhap();
    // }
    // HoaDonNhapHang hoaDonNhapHang;
    // hoaDonNhapHang.nhap();
    // quanLyCuaHangDienThoai.xuatDanhSachSanPham();
    return 0;
}
