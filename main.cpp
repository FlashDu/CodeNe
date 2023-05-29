#include <iostream> 
#include "function.h"
using namespace std;

void quanLyNhanVien() {
    ds_nhan_vien ds1;
    ds1.phead = nullptr;

    int choice;
    int manv;
    string hoten;
    string chucvu;

    do {
        cout << "=====================" << endl;
        cout << "1. Them nhan vien" << endl;
        cout << "2. Xoa nhan vien" << endl;
        cout << "3. Sua thong tin nhan vien" << endl;
        cout << "4. Xuat danh sach nhan vien" << endl;
        cout << "0. Quay lai" << endl;
        cout << "=====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap MANV: ";
                cin >> manv;
                cout << "Nhap HOTEN: ";
                cin.ignore();
                getline(cin, hoten);
                cout << "Nhap CHUCVU: ";
                getline(cin, chucvu);
                add_nhan_vien(ds1, manv, hoten, chucvu);
                break;
            case 2:
                cout << "Nhap MANV cua nhan vien can xoa: ";
                cin >> manv;
                delete_nhan_vien(ds1, manv);
                break;
            case 3:
                update_nhan_vien(ds1, manv);
                break;
            case 4:
                display_nhan_vien(ds1);
                break;
            case 0:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    } while (choice != 0);
}

void quanLyThanhVien() {
    ds_thanh_vien ds2;
    ds2.phead = nullptr;

    int choice;
    int matv;
    string hoten;
    string sdt;
    int ngaykhoitao;

    do {
        cout << "=====================" << endl;
        cout << "1. Them thanh vien" << endl;
        cout << "2. Xoa thanh vien" << endl;
        cout << "3. Sua thong tin nhan vien" << endl;
        cout << "4. Xuat danh sach thanh vien" << endl;
        cout << "0. Quay lai" << endl;
        cout << "=====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap MATV: ";
                cin >> matv;
                cout << "Nhap HOTEN: ";
                cin.ignore();
                getline(cin, hoten);
                cout << "Nhap SDT: ";
                getline(cin, sdt);
                cout << "Nhap NGAYKHOITAO: ";
                cin >> ngaykhoitao;
                add_thanh_vien(ds2, matv, hoten, sdt, ngaykhoitao);
                break;
            case 2:
                cout << "Nhap MATV cua thanh vien can xoa: ";
                cin >> matv;
                delete_thanh_vien(ds2, matv);
                break;
            case 3:
                update_thanh_vien(ds2, matv);
                break;
            case 4:
                display_thanh_vien(ds2);
                break;
            case 0:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    } while (choice != 0);
}
void quanLybanchoi() {
    ds_ban_choi ds3;
    int choice;
    int maban;

    do {
        cout << "=====================" << endl;
        cout << "1. Them ban choi" << endl;
        cout << "2. Xoa ban choi" << endl;
        cout << "3. Xuat tinh trang ban choi" << endl;
        cout << "0. Quay lai" << endl;
        cout << "=====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            
            case 1:
                cout << "Nhap MABAN can them: ";
                cin >> maban;
                add_ban_choi(ds3, maban);
                break;
            case 2:
                cout << "Nhap MABAN can xoa: ";
                cin >> maban;
                delete_ban_choi(ds3, maban);
                break;
            case 3:
                display_all_ban_choi(ds3);
                break;
            case 0:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    } while (choice != 0);
}

//---------------------------------------------------------------------------------------------------
int main() {
    int choice;

    do {
        cout << "=====================" << endl;
        cout << "1. Quan ly nhan vien" << endl;
        cout << "2. Quan ly thanh vien" << endl;
        cout << "3. Quan ly ban choi" << endl;
        cout << "4. thanh toan hoa don " << endl;
        cout << "0. Thoat" << endl;
        cout << "=====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quanLyNhanVien();
                break;
            case 2:
                quanLyThanhVien();
                break;
            case 3:
                quanLybanchoi();
                break;
            case 4:
                quanLyThanhVien();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
