// Write a program for Binary to decimal calculator.

#include <iostream>
#include <math.h>
using namespace std;

void Zeroes(int x)
{
    int z = 0;
    for (int i = 1; i <= 32 - x; i++)
    {
        cout << z;
        if (i % 8 == 0)
        {
            cout << " ";
        }
    }
}
    
void Ones(int y)
{
    int z = 1;
    for (int i = 1; i <= 32 - y; i++)
    {
        cout << z;
        if (i % 8    == 0)
        {
            cout << " ";
        }
    }
}

int main()
{
    cout << endl << "__________________________________" << endl << endl;

    long long int number;
    int choice;
    int n, j = 0;
    float ans;
    
    do
    {
        cout << "Press 1 for Decimal to Binary : \n";
        cout << "Press 2 for Binary to Decimal : \n\n";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:

                cout << "Enter your decimal Number : ";
                cin >> number;

                if (number > 0)
                {
                    int num = number, i = 0, count = 0;
                    int Array[32];
                    
                    while (num)
                    {
                        Array[i] = num & 1 ;
                        num = num >> 1;
                        i++ , count++ ;
                        count++;
                    }

                    cout << "Binary : ";
                    Zeroes(count);
                    for (int i = count - 1; i >= 0; i--)
                    {
                        cout << Array[i];
                        if( i % 8 == 0) cout << " " ;
                    }
                }
                else if (number < 0)
                {

                    int num = number, i = 0, count = 0, bit;
                    int Arrayay[32];

                    num = (num * (-1));
                    // For Binary :-

                    while (num != 0)
                    {
                        bit = num & 1;
                        Arrayay[i] = bit;
                        num = num >> 1;
                        count++;
                        i++;
                    }

                    cout << endl << "Binary Number    :     ";

                    Zeroes(count);

                    for (int i = count - 1; i >= 0; i--)
                    {
                        cout << Arrayay[i];
                    }
                    // For One's Compliment :-

                    i = 0;

                    while (i < count)
                    {
                        if (Arrayay[i] == 0)    Arrayay[i] = 1 ;
                        else    Arrayay[i] = 0;
                        i++;
                    }
                    
                    cout << endl << "__________________________________" << endl << endl;

                    cout << "One's Complement : ";

                    Ones(count);

                    for (int i = count - 1; i >= 0; i--)
                    {
                        cout << Arrayay[i];
                    }

                    cout << endl << "__________________________________" << endl << endl;

                    // Two's Compliment :-

                    cout << "Two's Complement : ";

                    if (Arrayay[0] == 0)
                    {
                        Ones(count);

                        Arrayay[0] = 1;

                        for (int i = count - 1; i >= 0; i--)
                        {
                            cout << Arrayay[i];
                        }
                    }
                    else
                    {
                        Ones(count);

                        for (int a = 0; a < 32; a++)
                        {
                            if (Arrayay[a] == 0)
                            {
                                Arrayay[a] = 1;

                                for (int i = a - 1; i >= 0; i--)
                                {
                                    Arrayay[i] = 0;
                                }
                                break;
                            }
                        }
                        for (int i = count - 1; i >= 0; i--)
                        {
                            cout << Arrayay[i];
                        }
                    }
                }

                else

                {
                    cout << endl << endl << "00000000 00000000 00000000 00000000 " << endl;
                }

            break;

            case 2:

                if (number > 0)
                {
                    cout << "Enter your Binary number : ";
                    cin >> n;
                    cout << endl;
                    j = 0;

                    int Array[32];

                    while (n != 0)
                    {
                        int digit = n % 10;
                        Array[j] = digit;
                        if (Array[j] == 1)
                        {
                            ans = (ans + pow(2, j));
                        }
                        n = n / 10;
                        j++;
                    }

                    cout << "Decimal number : " << ans << endl;
                }

                else
                {
                    cout << endl << endl << "00000000 00000000 00000000 00000000 " << endl;
                }

            break;

            default:
                cout << "You have only 2 choice .";
            break;
        }
        cout << endl << "__________________________________" << endl << endl;
    }
    while(1);
    return 0;
}