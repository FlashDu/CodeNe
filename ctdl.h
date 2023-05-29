#include <iostream> 
#include <string>
#include <chrono>
#include <ctime>
using namespace std;

#define DONVITINHTIEN 50


struct ban_choi {
    int maban; 
    char trangthai; // E: empty, O: occupied, R: reserved
    int thoigiannhan; 
    int thoigianchoi;
    float tienban; 
    time_t start_time; // time when thoigianchoi counter started
};

struct ds_ban_choi {
    ban_choi* ds[50]; // danh sach cac ban choi [0..49
};



struct hoa_don {
    int mahd;
    int maban;
    int tienban;
    int ngaylaphoadon;
    float giamtru;
    //pointer to the next bill
    hoa_don* pnext;
};


struct ds_hoa_don {
    hoa_don* phead = NULL;
    int sl = 0;
};

struct thanh_vien {
    int matv;
    string hoten;
    string sdt;
    int ngaykhoitao;
    // pointer to the next member
    thanh_vien* pleft;
    thanh_vien* pright;

    //ds_hoa_don of the member
    ds_hoa_don ds_hoa_don;
};

struct ds_thanh_vien {
    thanh_vien* phead;
};


struct nhan_vien {
    int manv;
    string hoten;
    string chucvu; // S: staff, M: manager, A: admin
    // pointer to the next employee
    nhan_vien* pleft;
    nhan_vien* pright;

    //pointer to ds_hoa_don of the employee
    ds_hoa_don* pds_hoa_don;
};

//ds_nhan_vien is a binary search tree
struct ds_nhan_vien {
    nhan_vien* phead;
};


struct hang_cho {
    // A queue of customer who are waiting for a table
};