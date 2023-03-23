
#define _CRT_SECURE_NO_WARNINGs
#include <iostream>
#include <conio.h>
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




//메인 함수
int main()
{
    int num, thous, hund, ten, one, add;
    int i;
    char ch;

    add = 0;

    while (true)
    {

        

        if (_kbhit()) // 특정키 클릭
        {
            if (_getch() == 27)//esc => 27
            {
                exit;//프로그램 종료
            }

        }

        if (add % 2 == 0)
        {
            cout << "숫자 입력 : (프로그램 종료 : esc키) => " << endl;
            cin >> num;


            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX);//Int만 감지
                cout << "잘못 입력하셨습니다. 다시 입력해주세요 " << endl;
                continue;

            }


            thous = num / 1000;
            hund = (num % 1000) / 100;
            ten = (num % 100) / 10;
            one = (num % 10);
            if (num < 4000)
            {
                for (i = 0; i < thous; i++)
                {
                    std::cout << "M";
                }

                if (hund < 4)
                    for (i = 0; i < hund; i++)
                        std::cout << "C";
                else if (hund == 4)
                    std::cout << "CD";
                else if (hund >= 5 && hund < 9)
                {
                    std::cout << "D";
                    for (i = 0; i < (hund - 5); i++)
                        std::cout << "C";
                }
                else std::cout << "CM";

                if (ten < 4)
                    for (i = 0; i < ten; i++)
                        std::cout << "X";
                else if (ten == 4)
                    std::cout << "XL";
                else if (ten >= 5 && ten < 9)
                {
                    std::cout << "L";
                    for (i = 0; i < (ten - 5); i++)
                        std::cout << "X";
                }
                else std::cout << "XC";

                if (one < 4)
                    for (i = 0; i < one; i++)
                        std::cout << "I";
                else if (one == 4)
                    std::cout << "IV";
                else if (one >= 5 && one < 9)
                {
                    std::cout << "V";
                    for (i = 0; i < (one - 5); i++)
                        std::cout << "I";
                }
                else std::cout << "IX";
                std::cout << "\n";
                add += 1;
            }
            else
            {
                std::cout << "3999이상은 쓸 수 없습니다\n";
                continue;
            }

        }
        else
        {
            std::cout << "로마숫자 입력 : (프로그램 종료 : esc키) =>\n";
            cin >> a;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(CHAR_MAX, '\n');
                cout << "잘못 입력하셨습니다." << endl;
                continue;

            }
            int ans = romanToNum(a);

            if (ans == 0)
            {
                cout << "잘못 입력하셨습니다." << endl;
                continue;
            }
            else
            {
                cout << ans << endl;
                add += 1;
            }
               

        }
       


       /* std::cout << "로마숫자 입력 : (프로그램 종료 : esc키) ";
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(CHAR_MAX, '\n');
            cout << "잘못 입력하셨습니다." << endl;
            continue;

        }
        int ans = romanToNum(a);

        if (ans == 0)
        {
            cout << "잘못 입력하셨습니다." << endl;
            continue;
        }
        else
        cout << ans << endl;*/

        /*cout << "숫자 입력 : (프로그램 종료 : esc키) " << endl;
        cin >> num;*/


        //if (!cin)
        //{
        //    cin.clear();
        //    cin.ignore(INT_MAX);//Int만 감지
        //    cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
        //    continue;

        //}


        //thous = num / 1000;
        //hund = (num % 1000) / 100;
        //ten = (num % 100) / 10;
        //one = (num % 10);
        //if (num < 4000)
        //{
        //    for (i = 0; i < thous; i++)
        //    {
        //        std::cout << "M";
        //    }

        //    if (hund < 4)
        //        for (i = 0; i < hund; i++)
        //            std::cout << "C";
        //    else if (hund == 4)
        //        std::cout << "CD";
        //    else if (hund >= 5 && hund < 9)
        //    {
        //        std::cout << "D";
        //        for (i = 0; i < (hund - 5); i++)
        //            std::cout << "C";
        //    }
        //    else std::cout << "CM";

        //    if (ten < 4)
        //        for (i = 0; i < ten; i++)
        //            std::cout << "X";
        //    else if (ten == 4)
        //        std::cout << "XL";
        //    else if (ten >= 5 && ten < 9)
        //    {
        //        std::cout << "L";
        //        for (i = 0; i < (ten - 5); i++)
        //            std::cout << "X";
        //    }
        //    else std::cout << "XC";

        //    if (one < 4)
        //        for (i = 0; i < one; i++)
        //            std::cout << "I";
        //    else if (one == 4)
        //        std::cout << "IV";
        //    else if (one >= 5 && one < 9)
        //    {
        //        std::cout << "V";
        //        for (i = 0; i < (one - 5); i++)
        //            std::cout << "I";
        //    }
        //    else std::cout << "IX";
        //    std::cout << "\n";
        //}
        //else
        //{
        //    std::cout << "3999이상은 쓸 수 없습니다\n";
        //    continue;
        //}


    }


}


