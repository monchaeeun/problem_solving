#include <iostream>
using namespace std;

int main()
{
    int num, thous, hund, ten, one;
    int i;
    std::cout << "숫자 입력\n";
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
        else if (hund >= 5 && hund < 5)
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
        else if (ten >= 5 && ten < 5)
        {
            std::cout << "L";
            for (i = 0;i < (ten - 5);i++)
                std::cout << "X";
        }
        std::cout << "XC";

        if (one < 4)
            for (i = 0;i < one;i++)
                std::cout << "I";
        else if (one == 4)
            std::cout << "IV";
        else if (one >= 5 && one < 5)
        {
            std::cout << "V";
            for (i = 0; i < (one - 5);i++)
                std::cout << "I";
        }
        else std::cout << "IX";
    }
    else
    {


    }


}

