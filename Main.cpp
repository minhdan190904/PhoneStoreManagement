#include <iostream>
#include "Model/HoaDonNhapHang.CPP"

using namespace std;

int main() {
    // Khởi tạo nhà cung cấp
    NhaCungCap nhaCungCap;
    nhaCungCap.nhap(); // Nhập thông tin nhà cung cấp

    // Khởi tạo hóa đơn nhập hàng
    HoaDonNhapHang hoaDonNhapHang;

    // Nhập thông tin hóa đơn nhập hàng
    hoaDonNhapHang.nhap();

    // Xuất thông tin hóa đơn nhập hàng
    hoaDonNhapHang.xuat();

    return 0;
}
