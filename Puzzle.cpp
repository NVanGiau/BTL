#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int kichThuoc = 3;
int troChoi[kichThuoc][kichThuoc] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

void hienThi()
{
    system("cls");
    cout << "==TRO CHOI PUZZLE==" << endl;
    for (int i = 0; i < kichThuoc; i++)
    {
        for (int j = 0; j < kichThuoc; j++)
        {
            if (troChoi[i][j] != 0)
                cout << troChoi[i][j] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

bool kiemTraKQ()
{
    int dem = 1;
    for (int i = 0; i < kichThuoc; i++)
    {
        for (int j = 0; j < kichThuoc; j++)
        {
            if (troChoi[i][j] != dem && !(i == kichThuoc - 1 && j == kichThuoc - 1 && troChoi[i][j] == 0))
                return false;
            dem++;
        }
    }
    return true;
}

void doiCho(int dong1, int cot1, int dong2, int cot2)
{
    int temp = troChoi[dong1][cot1];
    troChoi[dong1][cot1] = troChoi[dong2][cot2];
    troChoi[dong2][cot2] = temp;
}

void khoiDongTroChoi()
{
    srand(static_cast<unsigned int>(time(0)));

    int so = 1;

    for (int i = 0; i < kichThuoc; i++)
    {
        for (int j = 0; j < kichThuoc; j++)
        {
            troChoi[i][j] = so++;
        }
    troChoi[kichThuoc - 1][kichThuoc - 1] = 0;
    }

    for (int i = kichThuoc - 1; i > 0; i--)
    {
        for (int j = kichThuoc - 1; j > 0; j--)
        {
            int r = rand() % (i + 1);
            int c = rand() % (j + 1);
            doiCho(i, j, r, c);
        }
    }
}

void diChuyen(int phim)
{
    int dongTrong, cotTrong;

    for (int i = 0; i < kichThuoc; i++)
    {
        for (int j = 0; j < kichThuoc; j++)
        {
            if (troChoi[i][j] == 0)
            {
                dongTrong = i;
                cotTrong = j;
                break;
            }
        }
    }

    switch(phim)
    {
    case 72:
        if (dongTrong < kichThuoc - 1)
            doiCho(dongTrong, cotTrong, dongTrong + 1, cotTrong); break;
    case 80:
        if(dongTrong > 0)
            doiCho(dongTrong, cotTrong, dongTrong - 1, cotTrong); break;
    case 75:
        if (cotTrong < kichThuoc - 1)
            doiCho(dongTrong, cotTrong, dongTrong, cotTrong + 1); break;
    case 77:
        if(cotTrong > 0)
            doiCho(dongTrong, cotTrong, dongTrong, cotTrong - 1); break;
    }
}

int main()
{
    khoiDongTroChoi();
    int phim;
    while (true)
    {
        hienThi();
        if (kiemTraKQ())
        {
            cout << "Chuc mung ban da chien thang." << endl; break;
        }
        cout << "Su dung cac phim mui ten de di chuyen hoac (esc/Q) de thoat." << endl;

        phim = getch();

        if (phim == 27 || phim == 'q' || phim == 'Q')
            break;

        diChuyen(phim);
    }
    return 0;
}
