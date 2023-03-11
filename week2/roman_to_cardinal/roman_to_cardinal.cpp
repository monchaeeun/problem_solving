#include <iostream>
using namespace std;
string a, b;
int romanToNum(string& s)
{
    int temp = 0;
    int aSize = s.size();

    for (int i = 0; i < aSize; i++)
    {
        
        if (s[i] == 'M')
        {
            temp += 1000;
        }
        else if (s[i] == 'D')
        {
            temp += 500;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'M')
            {
                i++;
                temp += 900;
            }
            else if (s[i + 1] == 'D')
            {
                i++;
                temp += 400;
            }
            else
            {
                temp += 100;
            }
        }
        else if (s[i] == 'L')
        {
            temp += 50;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'C')
            {
                i++;
                temp += 90;
            }
            else if (s[i + 1] == 'L')
            {
                i++;
                temp += 40;
            }
            else
            {
                temp += 10;
            }
        }
        else if (s[i] == 'V')
        {
            temp += 5;
        }
        else if (s[i] == 'I')
        {
            if (s[i + 1] == 'X')
            {
                i++;
                temp += 9;
            }
            else if (s[i + 1] == 'V')
            {
                i++;
                temp += 4;
            }
            else
            {
                temp += 1;
            }

        }
    }

    return temp;

}




int main()
{
    int num, thous, hund, ten, one;
    int i;

    
   

    std::cout << "숫자 입력 : ";
    std::cin >> num;

    thous = num / 1000;
    hund = (num % 1000) / 100;
    ten = (num % 100) / 10;
    one = (num % 10);
    if (num < 4000)
    {
        for (i = 0;i < thous;i++)
        {
            std::cout << "M";
        }

        if (hund < 4)
            for (i = 0;i < hund; i++)
                std::cout << "C";
        else if (hund == 4)
            std::cout << "CD";
        else if (hund >= 5 && hund < 9)
        {
            std::cout << "D";
            for (i = 0;i < (hund - 5);i++)
                std::cout << "C";
        }
        else std::cout << "CM";

        if (ten < 4)
            for (i = 0;i < ten;i++)
                std::cout << "X";
        else if (ten == 4)
            std::cout << "XL";
        else if (ten >= 5 && ten < 9)
        {
            std::cout << "L";
            for (i = 0;i < (ten - 5);i++)
                std::cout << "X";
        }
        else std::cout << "XC";

        if (one < 4)
            for (i = 0;i < one;i++)
                std::cout << "I";
        else if (one == 4)
            std::cout << "IV";
        else if (one >= 5 && one < 9)
        {
            std::cout << "V";
            for (i = 0; i < (one - 5);i++)
                std::cout << "I";
        }
        else std::cout << "IX";
        std::cout << "\n";
    }
    else
    {
        std::cout << "3999이상은 쓸 수 없습니다\n";
    }

    std::cout << "로마숫자 입력 : ";

    cin >> a;
    int ans = romanToNum(a);
    cout << ans << endl;
}

