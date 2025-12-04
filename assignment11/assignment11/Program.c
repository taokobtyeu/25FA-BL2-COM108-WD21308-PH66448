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
    int gio;
    printf("Nhap so gio hat: ");
    scanf("%d", &gio);

    int tien = 0;

    if (gio <= 3) tien = gio * 50000;           //nếu <=3 giờ thi tinh 50k/1gio
    else tien = 3 * 50000 + (gio - 3) * 30000;  //

    printf("Tien karaoke: %d VND\n", tien);
}

// ======================= CHỨC NĂNG 4 =======================
void tinhTienDien() {
    int so;
    printf("Nhap so kWh: ");
    scanf("%d", &so);

    int tien = 0;

    if (so <= 50) tien = so * 1800;
    else if (so <= 100) tien = 50 * 1800 + (so - 50) * 2300;
    else tien = 50 * 1800 + 50 * 2300 + (so - 100) * 2800;

    printf("Tien dien: %d VND\n", tien);
}

// ======================= CHỨC NĂNG 5 =======================
void doiTien() {
    int money;
    printf("Nhap so tien can doi: ");
    scanf("%d", &money);

    int menhGia[] = { 500000, 200000, 100000, 50000, 20000, 10000 };
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
    double goc, lai;
    int thang;

    printf("Nhap so tien vay: ");
    scanf("%lf", &goc);
    printf("Nhap lai suat (%%/thang): ");
    scanf("%lf", &lai);
    printf("Nhap so thang: ");
    scanf("%d", &thang);

    double lsThang = goc * lai / 100;
    double tong = goc + lsThang * thang;

    printf("Tien lai moi thang: %.0lf VND\n", lsThang);
    printf("Tong tien phai tra: %.0lf VND\n", tong);
}

// ======================= CHỨC NĂNG 7 =======================
void vayMuaXe() {
    double xe, traTruoc, lai;
    int thang;

    printf("Gia xe: ");
    scanf("%lf", &xe);
    printf("Tra truoc: ");
    scanf("%lf", &traTruoc);
    printf("Lai suat %%/thang: ");
    scanf("%lf", &lai);
    printf("So thang vay: ");
    scanf("%d", &thang);

    double vay = xe - traTruoc;
    double traHangThang = vay / thang + vay * lai / 100;

    printf("So tien vay: %.0lf VND\n", vay);
    printf("Tra moi thang: %.0lf VND\n", traHangThang);
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

    if (num == 2) printf("Trung giai!\n");
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