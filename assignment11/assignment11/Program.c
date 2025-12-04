// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.
#include <stdio.h>
#include <math.h>

// ======================= CHỨC NĂNG 1 =======================
void kiemTraSoNguyen() {
    int n;
    printf("Nhap mot so: ");
    scanf("%d", &n);

    if (n % 1 == 0) {
        printf("%d la so nguyen.\n", n);
    }
    else {
        printf("Khong phai so nguyen.\n");//mọi số nhập vào đều là số nguyên 
    }
}

// ======================= CHỨC NĂNG 2 =======================
void timUocBoiChung() {
    int a, b;
    int ucln = 1; // giả sử UCLN ban đầu là 1
    int i;

    // Nhập số a
    printf("Nhap so a: ");
    scanf("%d", &a);

    // Nhập số b
    printf("Nhap so b: ");
    scanf("%d", &b);

    // Tìm UCLN bằng cách duyệt từ 1 đến số nhỏ hơn giữa a và b
    for (i = 1; i <= a && i <= b; i++) {

        // Nếu i chia hết cả hai số
        if (a % i == 0 && b % i == 0) {
            ucln = i;  // i là ước chung lớn nhất hiện tại
        }
    }

    // Tính BCNN theo công thức: a*b / UCLN
    int bcnn = (a * b) / ucln;

    // Xuất kết quả
    printf("UCLN của %d và %d = %d\n", a, b, ucln);
    printf("BCNN của %d và %d = %d\n", a, b, bcnn);
}

// ======================= CHỨC NĂNG 3 =======================
void tinhTienKaraoke() {
    int gioBD, gioKT;
    int soGio;
    float tienCoBan = 0;
    float tongTien = 0;

    // ===== NHAP DU LIEU =====
    printf("Nhap gio bat dau (12 - 23): ");
    scanf("%d", &gioBD);

    printf("Nhap gio ket thuc (12 - 23): ");
    scanf("%d", &gioKT);

    // ===== KIEM TRA HOP LE =====
    if (gioBD < 12 || gioBD > 23) {
        printf("Gio bat dau khong hop le!\n");
        return 0;
    }

    if (gioKT < 12 || gioKT > 23) {
        printf("Gio ket thuc khong hop le!\n");
        return 0;
    }

    if (gioKT <= gioBD) {
        printf("Gio ket thuc phai lon hon gio bat dau!\n");
        return 0;
    }

    // ===== TINH SO GIO =====
    soGio = gioKT - gioBD;

    // ===== TINH TIEN CO BAN =====
    if (soGio <= 3) {
        // 3 giờ đầu giá 150.000/giờ
        tienCoBan = soGio * 150000;
    }
    else {
        // 3 giờ đầu
        tienCoBan = 3 * 150000;
        // Các giờ sau giảm 30% → còn 105.000/giờ
        tienCoBan += (soGio - 3) * (150000 * 0.7);
    }

    // ===== GIAM THEM 10% NEU BAT DAU 14–17 =====
    if (gioBD >= 14 && gioBD <= 17) {
        tongTien = tienCoBan * 0.9; // giảm 10%
    }
    else {
        tongTien = tienCoBan;
    }

    // ===== HIEN THI KET QUA =====
    printf("\n===== HOA DON KARAOKE =====\n");
    printf("Gio bat dau: %d\n", gioBD);
    printf("Gio ket thuc: %d\n", gioKT);
    printf("Tong so gio hat: %d\n", soGio);
    printf("Tien thanh toan: %.0f VND\n", tongTien);

    return 0;
}
  


// ======================= CHỨC NĂNG 4 =======================
void tinhTienDien() {
    int i = 1;
    // vong lap
    while (1 == 1)
    {
        printf("Tinh tien dien\n");
        int so_kwh;
        float tien = 0;
        printf("Nhap so kWh su dung trong thang: ");
        scanf("%d", &so_kwh);
        if (so_kwh <= 50) {
            tien = so_kwh * 1.678;
        }
        else if (so_kwh <= 100) {
            tien = 50 * 1.678 + (so_kwh - 50) * 1.734;
        }
        else if (so_kwh <= 200) {
            tien = 50 * 1.678 + 50 * 1.734 + (so_kwh - 100) * 2.014;
        }
        else if (so_kwh <= 300) {
            tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (so_kwh - 200) * 2.536;
        }
        else if (so_kwh <= 400) {
            tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (so_kwh - 300) * 2.834;
        }
        else {
            tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (so_kwh - 400) * 2.927;
        }
        printf("So tien phai dong la: %f VND\n", tien);
    }
}


// ======================= CHỨC NĂNG 5 =======================
void doiTien() {
    int money;
    printf("Nhap so tien can doi: ");
    scanf("%d", &money);

    int menhGia[] = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000 };
    int i;

    for (i = 0; i < 6; i++) {
        int soTo = money / menhGia[i];
        if (soTo > 0) {
            printf("%d VND: %d to\n", menhGia[i], soTo);
        }
        money %= menhGia[i];
    }
}

// ======================= CHỨC NĂNG 6 =======================
void tinhLaiSuatVay() {
    double tienVay, laiSuat = 0.05;
    int soThang = 12;

    printf("Nhap so tien muon vay: ");
    scanf("%lf", &tienVay);

    // Công thức trả góp đều
    double tu = laiSuat * pow(1 + laiSuat, soThang);
    double mau = pow(1 + laiSuat, soThang) - 1;
    double tienTraThang = tienVay * (tu / mau);
    double tongTra = tienTraThang * soThang;
    double tongLai = tongTra - tienVay;

    printf("\n------ KET QUA ------\n");
    printf("Tien vay: %.0f VND\n", tienVay);
    printf("Tien phai tra moi thang: %.0f VND\n", tienTraThang);
    printf("Tong tien phai tra: %.0f VND\n", tongTra);
    printf("Tong lai phai tra: %.0f VND\n", tongLai);

    return 0;
}

// ======================= CHỨC NĂNG 7 =======================
void vayMuaXe() {
    int i = 1;
    // vong lap
    while (i == 1)
    {
        int percent;
        printf("Nhap so phan tram vay toi da (0-100): ");
        scanf("%d", &percent);

        if (percent < 0 || percent > 100) {
            printf("Phan tram vay phai tu 0 den 100.\n");
            return;
        }
        double giaxe = 500000000.0;
        double P = giaxe * (percent / 100.0); //tien vay
        double tratruoc = giaxe - P; //tra lan dau

        double laisuatnam = 0.072;
        int nam = 24;
        int thang = nam * 12;
        double r = laisuatnam / 12.0;

        /* Tang truong lai suat theo thang tính (1 + r)^thang*/ // lai suat kep
        int i;
        double pow1 = 1.0;
        for (i = 0; i < thang; i++) {
            pow1 *= (1 + r);
        }
        // tien tra hang thang phai cha (PMT)
        double PMT = P * (r * pow1) / (pow1 - 1);

        printf("So tien phai tra lan dau: %.0f VNÐ\n", tratruoc);
        printf("So tien phai tra hang thang cho den het ky han vay: %.0f VNÐ\n", PMT);

        printf("Ban vua nhap:%d\n", i);
        printf("Ban co muon thuc hien tiep hay khong[1-Co|khac-Khong]: ");
        scanf("%d", &i);
        system("cls");//clear screen
    }
}

// ======================= CHỨC NĂNG 8 =======================
void sapXepSinhVien() 
        {
            int n;
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            getchar();

            char hoten[100][50];
            float diem[100];


            for (int i = 0; i < n; i++) {
                printf("\nNhap ho ten sinh vien thu %d: ", i + 1);
                fgets(hoten[i], sizeof(hoten[i]), stdin);
                hoten[i][strcspn(hoten[i], "\n")] = '\0';

                printf("Nhap diem: ");
                scanf("%f", &diem[i]);
                getchar();
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (diem[i] < diem[j]) {
                        float tmp = diem[i];
                        diem[i] = diem[j];
                        diem[j] = tmp;

                        char tmpName[50];
                        strcpy(tmpName, hoten[i]);
                        strcpy(hoten[i], hoten[j]);
                        strcpy(hoten[j], tmpName);
                    }
                }
            }
            printf("\nDANH SACH SINH VIEN \n");
            printf("%-25s %-10s %-15s\n", "Ho ten", "Diem", "Hoc luc");
            for (int i = 0; i < n; i++) {
                char hocluc[20];
                if (diem[i] >= 9.0) strcpy(hocluc, "Xuat sac");
                else if (diem[i] >= 8.0) strcpy(hocluc, "Gioi");
                else if (diem[i] >= 6.5) strcpy(hocluc, "Kha");
                else if (diem[i] >= 5.0) strcpy(hocluc, "Trung binh");
                else strcpy(hocluc, "Yeu");

                printf("%-25s %-10.2f %-15s\n", hoten[i], diem[i], hocluc);
            }
            return 0;
        }
// ======================= CHỨC NĂNG 9 =======================
void gameFPOLY() {
    int num;
    printf("Nhap so (1-15): ");
    scanf("%d", &num);

    if (num == 2) printf("Trung giai nhat!\n");
    if (num == 1) printf("Trung giai nhi!\n");
    else printf("Chuc may man lan sau.\n");
}

// ======================= CHỨC NĂNG 10 =======================
void tinhPhanSo() {
    int tu1, mau1, tu2, mau2;
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d %d", &tu1, &mau1);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d %d", &tu2, &mau2);

    int tu = tu1 * mau2 + tu2 * mau1;
    int mau = mau1 * mau2;

    printf("Tong 2 phan so = %d/%d\n", tu, mau);
}

// ======================= MENU =======================
int main() {
    int chon;

    do {
        system("cls");  // Xóa màn hình cho gọn

        printf("===== MENU =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Uoc & Boi chung\n");
        printf("3. Tinh tien karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai suat vay\n");
        printf("7. Vay mua xe\n");
        printf("8. Sap xep danh sach sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        system("cls");

        switch (chon) {
        case 1: kiemTraSoNguyen(); break;
        case 2: timUocBoiChung(); break;
        case 3: tinhTienKaraoke(); break;
        case 4: tinhTienDien(); break;
        case 5: doiTien(); break;
        case 6: tinhLaiSuatVay(); break;
        case 7: vayMuaXe(); break;
        case 8: sapXepSinhVien(); break;
        case 9: gameFPOLY(); break;
        case 10: tinhPhanSo(); break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }

        if (chon != 0) {
            printf("\nNhan Enter de quay lai menu...");
            getchar(); // nhận ký tự Enter cũ
            getchar(); // chờ người dùng nhấn Enter mới
        }

    } while (chon != 0);

    return 0;
}





// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Dung "Solution Explorer window" de them/quan ly cac files
//   2. Dung "Output window" de kiem tra "build output" va "cac thong bao khac"
//   3. Dung "Error List window" de xem loi
//   4. Chon "Project > Add New Item" de tao moi file code,
//      hoac "Project > Add Existing Item" de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//      chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//      bam phim chuot phai vao "Solution" > chon "Open Folder in File Explorer"

// GV: AnhTT184