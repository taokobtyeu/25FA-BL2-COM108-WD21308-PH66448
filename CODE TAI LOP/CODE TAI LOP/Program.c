// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>

int main()
{
    {
        char  Kytu = 'A';// chi 1 ki tu - nhay 'a' chi 1 ki tu, nha" nhieu ki tu
        //  string - "string.h"
        char MAngKyTu[10] = { 'A','n','h' };
        for (int i = 0; i < 3; i++)
        {

            scanf(" %c", &MAngKyTu[i]);
            // dung IF cho cac ki tu dac biet, Dung vong lap
            if (MAngKyTu[i] == '.')
            {
                break;
            }
        }
        //gets thay the cho for
        //gets(MangKyTu);k dung dc voi vsua
        /*for (int i = 0; i < 3; i++)
        {
            scanf("%c", MAngKyTu[i]);
        }*/
        puts(MAngKyTu);


        int array[2][3];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("Mang tai vi tri[%d][%d]= ", i, j);
                scanf("%d", &array[i][j]);
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d, ", array[i][j]);

            }
            printf("\n");
        }
    }
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