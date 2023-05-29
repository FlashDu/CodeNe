#include <iostream>
#include <string>
#include "ctdl.h"
//--------------Thanh vien---------------------
void add_thanh_vien(ds_thanh_vien &ds, int matv, string hoten, string sdt, int ngaykhoitao) {
    // create a new node
    thanh_vien *new_node = new thanh_vien;
    new_node->matv = matv;
    new_node->hoten = hoten;
    new_node->sdt = sdt;
    new_node->ngaykhoitao = ngaykhoitao;
    new_node->pleft = nullptr;
    new_node->pright = nullptr;
    
    // insert the new node into the tree
    if (ds.phead == nullptr) {
        ds.phead = new_node;
    } else {
        thanh_vien *current_node = ds.phead;
        while (true) {
            if (matv < current_node->matv) {
                if (current_node->pleft == nullptr) {
                    current_node->pleft = new_node;
                    break;
                } else {
                    current_node = current_node->pleft;
                }
            } else {
                if (current_node->pright == nullptr) {
                    current_node->pright = new_node;
                    break;
                } else {
                    current_node = current_node->pright;
                }
            }
        }
    }
}

void inorder_traversal(thanh_vien *node) {
    if (node == nullptr) {
        return;
    }
    inorder_traversal(node->pleft);
    cout << "Ma thanh vien: " << node->matv << endl;
    cout << "Ho ten: " << node->hoten << endl;
    cout << "So dien thoai: " << node->sdt << endl;
    cout << "Ngay khoi tao: " << node->ngaykhoitao << endl;
    // display the member's hoa don
    // display_ds_hoa_don(node->ds_hoa_don);
    inorder_traversal(node->pright);
}
void display_thanh_vien(ds_thanh_vien ds) {
    inorder_traversal(ds.phead);
}

thanh_vien *find_min(thanh_vien *node) {
    while (node->pleft != nullptr) {
        node = node->pleft;
    }
    return node;
}
thanh_vien *delete_node(thanh_vien *node, int matv) {
    if (node == nullptr) {
        return nullptr;
    } else if (matv < node->matv) {
        node->pleft = delete_node(node->pleft, matv);
    } else if (matv > node->matv) {
        node->pright = delete_node(node->pright, matv);
    } else {
        // case 1: node has no children
        if (node->pleft == nullptr && node->pright == nullptr) {
            delete node;
            node = nullptr;
        }
        // case 2: node has one child
        else if (node->pleft == nullptr) {
            thanh_vien *temp = node;
            node = node->pright;
            delete temp;
        } else if (node->pright == nullptr) {
            thanh_vien *temp = node;
            node = node->pleft;
            delete temp;
        }
        // case 3: node has two children
        else {
            thanh_vien *temp = find_min(node->pright);
            node->matv = temp->matv;
            node->hoten = temp->hoten;
            node->sdt = temp->sdt;
            node->ngaykhoitao = temp->ngaykhoitao;
            node->ds_hoa_don = temp->ds_hoa_don;
            node->pright = delete_node(node->pright, temp->matv);
        }
    }
    return node;
}

void delete_thanh_vien(ds_thanh_vien &ds, int matv) {
    ds.phead = delete_node(ds.phead, matv);
}
void update_thanh_vien(ds_thanh_vien& ds, int matv) {
    thanh_vien* current_node = ds.phead;
    while (current_node != nullptr) {
        if (matv == current_node->matv) {
            // Nhân viên được tìm thấy, cho phép sửa thông tin
            cout << "Thong tin hien tai cua thanh vien:" << endl;
            cout << "Ma thanh vien: " << current_node->matv << endl;
            cout << "Ho ten: " << current_node->hoten << endl;
            cout << "So dien thoai: " << current_node->sdt << endl;
            cout << "Ngay khoi tao: " << current_node->ngaykhoitao << endl;
            // Nhập thông tin mới
            int matv;
            string hoten;
            string sdt;
            int ngaykhoitao;
            cout << "Nhap MATV cua thanh vien can sua: ";
            cin >> matv;
            cout << "Nhap HOTEN moi: ";
            cin.ignore();
            getline(cin, hoten);
            cout << "Nhap so dien thoai moi: ";
            getline(cin, sdt);

            // Cập nhật thông tin mới
            current_node->hoten = hoten;
            current_node->sdt = sdt;

            cout << "Thong tin thanh vien da duoc cap nhat." << endl;
            return;
        } else if (matv < current_node->matv) {
            current_node = current_node->pleft;
        } else {
            current_node = current_node->pright;
        }
    }

    // Không tìm thấy nhân viên để sửa
    cout << "Khong tim thay thanh vien co ma so " << matv << " de sua." << endl;
}

//----------------------------------nhan vien ---------------------------------------
void add_nhan_vien(ds_nhan_vien &ds, int manv, string hoten, string chucvu) {
    // create a new node
    nhan_vien *new_node = new nhan_vien;
    new_node->manv = manv;
    new_node->hoten = hoten;
    new_node->chucvu = chucvu;
    new_node->pleft = nullptr;
    new_node->pright = nullptr;
    
    // insert the new node into the tree
    if (ds.phead == nullptr) {
        ds.phead = new_node;
    } else {
        nhan_vien *current_node = ds.phead;
        while (true) {
            if (manv < current_node->manv) {
                if (current_node->pleft == nullptr) {
                    current_node->pleft = new_node;
                    break;
                } else {
                    current_node = current_node->pleft;
                }
            } else {
                if (current_node->pright == nullptr) {
                    current_node->pright = new_node;
                    break;
                } else {
                    current_node = current_node->pright;
                }
            }
        }
    }
}

void inorder_traversal(nhan_vien *node) {
    if (node == nullptr) {
        return;
    }
    inorder_traversal(node->pleft);
    cout << "Ma thanh vien: " << node->manv << endl;
    cout << "Ho ten: " << node->hoten << endl;
    cout << "Chuc vu: " << node->chucvu << endl;
    // display the member's hoa don
    // display_ds_hoa_don(node->ds_hoa_don);
    inorder_traversal(node->pright);
}


void display_nhan_vien(ds_nhan_vien ds) {
    inorder_traversal(ds.phead);
}

nhan_vien *find_min(nhan_vien *node) {
    while (node->pleft != nullptr) {
        node = node->pleft;
    }
    return node;
}
nhan_vien *delete_node(nhan_vien *node, int manv) {
    if (node == nullptr) {
        return nullptr;
    } else if (manv < node->manv) {
        node->pleft = delete_node(node->pleft, manv);
    } else if (manv > node->manv) {
        node->pright = delete_node(node->pright, manv);
    } else {
        // case 1: node has no children
        if (node->pleft == nullptr && node->pright == nullptr) {
            delete node;
            node = nullptr;
        }
        // case 2: node has one child
        else if (node->pleft == nullptr) {
            nhan_vien *temp = node;
            node = node->pright;
            delete temp;
        } else if (node->pright == nullptr) {
            nhan_vien *temp = node;
            node = node->pleft;
            delete temp;
        }
        // case 3: node has two children
        else {
            nhan_vien *temp = find_min(node->pright);
            node->manv = temp->manv;
            node->hoten = temp->hoten;
            node->chucvu = temp->chucvu;
            node->pds_hoa_don = temp->pds_hoa_don;
            node->pright = delete_node(node->pright, temp->manv);
        }
    }
    return node;
}

void delete_nhan_vien(ds_nhan_vien &ds, int manv) {
    ds.phead = delete_node(ds.phead, manv);
}
void update_nhan_vien(ds_nhan_vien& ds, int manv) {
    nhan_vien* current_node = ds.phead;
    while (current_node != nullptr) {
        if (manv == current_node->manv) {
            // Nhân viên được tìm thấy, cho phép sửa thông tin
            cout << "Thong tin hien tai cua nhan vien:" << endl;
            cout << "Ma nhan vien: " << current_node->manv << endl;
            cout << "Ho ten: " << current_node->hoten << endl;
            cout << "Chuc vu: " << current_node->chucvu << endl;

            // Nhập thông tin mới
            int manv;
            string hoten;
            string chucvu;
            cout << "Nhap MANV cua nhan vien can sua: ";
            cin >> manv;
            cout << "Nhap HOTEN moi: ";
            cin.ignore();
            getline(cin, hoten);
            cout << "Nhap CHUCVU moi: ";
            getline(cin, chucvu);

            // Cập nhật thông tin mới
            current_node->hoten = hoten;
            current_node->chucvu = chucvu;

            cout << "Thong tin nhan vien da duoc cap nhat." << endl;
            return;
        } else if (manv < current_node->manv) {
            current_node = current_node->pleft;
        } else {
            current_node = current_node->pright;
        }
    }

    // Không tìm thấy nhân viên để sửa
    cout << "Khong tim thay nhan vien co ma so " << manv << " de sua." << endl;
}
//---------------------------------tinh hinh ban chơi -------------------------------------
// Function to add a "ban_choi" structure to the "ds_ban_choi" list
void add_ban_choi(ds_ban_choi &ds, int maban) {
    ban_choi* new_ban_choi = new ban_choi; // create a new "ban_choi" object dynamically
    new_ban_choi->maban = maban;
    new_ban_choi->trangthai = 'O';
    new_ban_choi->thoigiannhan = time(nullptr);
    new_ban_choi->thoigianchoi = 0;
    new_ban_choi->tienban = 0.0;
    new_ban_choi->start_time = time(nullptr);
    ds.ds[maban] = new_ban_choi;
}

// Function to delete a "ban_choi" structure from the "ds_ban_choi" list
void delete_ban_choi(ds_ban_choi &ds, int maban) {
    ban_choi* deleted_ban_choi = ds.ds[maban];
    if (deleted_ban_choi == nullptr) { // if the "ban_choi" object doesn't exist in the list
        cout << "Ban choi khong ton tai!\n";
        return;
    }
    deleted_ban_choi->trangthai = 'E';
    deleted_ban_choi->thoigianchoi = time(nullptr) - deleted_ban_choi->thoigiannhan; // calculate the "thoigianchoi" variable
    deleted_ban_choi->tienban = DONVITINHTIEN * deleted_ban_choi->thoigianchoi; // calculate the "tienban" variable
    time_t current_time = time(nullptr);
    cout << "Ban choi " << maban << " da choi trong " << deleted_ban_choi->thoigianchoi << " giay.\n";
    cout << "Tien ban choi: " << deleted_ban_choi->tienban << " dong.\n";
    delete deleted_ban_choi; // free the memory allocated for the "ban_choi" object
    ds.ds[maban] = nullptr; // set the pointer to nullptr in the list
}

void display_all_ban_choi(ds_ban_choi ds) {
    for (int i = 0; i < 50; i++) {
        ban_choi* current_ban_choi = ds.ds[i];
        if (current_ban_choi == nullptr) { // if the "ban_choi" object doesn't exist in the list
            continue;
        }
        cout << "Ma ban: " << current_ban_choi->maban << endl;
        cout << "Trang thai: " << current_ban_choi->trangthai << endl;
        cout << "Thoi gian nhan: " << current_ban_choi->thoigiannhan << endl;
        cout << "Thoi gian choi: " << current_ban_choi->thoigianchoi << endl;
        cout << "Tien ban: " << current_ban_choi->tienban << endl;
        cout << "---------------------------------------" << endl;
    }
}




