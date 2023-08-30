
#include <iostream>
using namespace std;
const int N = 100010;
int a[N], b[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    for (int i = 0; i < n; )
    {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
            {
                i++;
            }
            if (i == n)
            {
                cout << "Yes";
                break;
            }
        }
        if (i != n)
        {
            cout << "No";
            break;
        }
       
    }
    return 0;


}

