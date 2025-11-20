//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
void fastscan(int &number) {
    bool negative = false;
    register char c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
// Function Call
int main()
{
	int number;
	fastscan(number);
	cout << number << "\n";
	return 0;
}
