#include <iostream>
#include <iomanip>

using namespace std; // 命名空间，标准库

int main()
{
    float f1 = 3.14f;
    double d1 = 3.14;
    printf("%lf\n",d1);
    cout << f1 << endl;
    cout << d1 << endl;
    cout << fixed << setprecision(6) << d1 << endl;

    return 0;
}