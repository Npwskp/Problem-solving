#include <iostream>
#include <vector>
using namespace std;

#define n 100
char arr[n][n];
char main_a[n][n];

int check_path(int x, int y, int xm, int ym)
{
    if (x == xm-1)
        return 1;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < xm && nx >= 0 && ny < ym && ny >= 0 && main_a[nx][ny] == '.')
        {
            main_a[nx][ny] = 'o';
            if (check_path(nx, ny, xm, ym))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < y - 1; j++)
        {
            if (arr[i][j] == '.' && arr[i][j + 1] == '.' && arr[i + 1][j] == '.' && arr[i + 1][j + 1] == '.')
                main_a[i][j] = '.';
            else
                main_a[i][j] = '#';
        }
    }

    for (int i = 0; i < y - 1; i++)
    {
        if (main_a[0][i] == '.')
        {
            if (check_path(0, i, x - 1, y - 1))
            {
                cout << "yes";
                return 1;
            }
        }
    }

    cout << "no";
    return 0;
}