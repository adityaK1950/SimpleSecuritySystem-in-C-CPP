#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password0, password1, password2, pass, name, age, user, word, word1;
    string creds[2], cp[2];

    cout << "           Security System           " << endl;

    cout << "_____________________________________" << endl << endl;
    cout << "|         1.Register                |" << endl;
    cout << "|         2.Login                   |" << endl;
    cout << "|         3.Change Password         |" << endl;
    cout << "|         4.End Program             |" << endl;
    cout << "|____________________________________" << endl << endl;

    do
    {
        cout << endl << endl;
        cout << "Enter Your Choice: ";
        cin >> a;

        switch (a)
        {

        case 1:
        {
            cout << "____________________________________" << endl << endl;
            cout << "|----------- Register -------------|" << endl;
            cout << "____________________________________" << endl << endl;
            cout << "Please Enter Username: ";
            cin >> name;
            cout << "Please Enter Password: ";
            cin >> password0;
            cout << "Please Enter your Age: ";

            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0;
                cout << "--- Registration Successful ---" << endl;
                of1.close();
            }
            break;
        }

        case 2:
        {
            i = 0;

            cout << "_____________________________________" << endl << endl;
            cout << "------------ Login ------------------" << endl;
            cout << "_____________________________________" << endl << endl;

            ifstream of2;
            of2.open("file.txt");
            cout << "Please Enter the Username: ";
            cin >> user;
            cout << "Please Enter the Password: ";
            cin >> pass;

            if (of2.is_open())
            {
                while (getline(of2, text))
                {
                    istringstream iss(text);
                    iss >> word;
                    creds[i] = word;
                    i++;
                }
                of2.close();

                if (user == creds[0] && pass == creds[1])
                {
                    cout << "--- Login Successful ---" << endl;
                    cout << endl << endl;

                    cout << "Details: " << endl;

                    cout << "Username: " << name << endl;
                    cout << "Password: " << pass << endl;
                    cout << "Age: " << age << endl;
                }
                else
                {
                    cout << endl << endl;
                    cout << "        Incorrect Credentials        " << endl;
                    cout << "-------- 1.Press 2 to Login  --------" << endl;
                    cout << "---- 2.Press 3 to Change Password ---" << endl;
                }
            }
            break;
        }

        case 3:
        {
            i = 0;

            cout << "---------- Change Password ---------" << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the Old Password: ";
            cin >> old;

            if (of0.is_open())
            {
                while (getline(of0, text))
                {
                    istringstream iss(text);
                    iss >> word1;
                    cp[i] = word1;
                    i++;
                }
                of0.close();

                if (old == cp[1])
                {
                    ofstream of1;
                    of1.open("file.txt");
                    if (of1.is_open())
                    {
                        cout << "Enter Your New Password: ";
                        cin >> password1;
                        cout << "Enter Your Password Again: ";
                        cin >> password2;

                        if (password1 == password2)
                        {
                            of1 << cp[0] << "\n";
                            of1 << password1;
                            cout << "Password Changed Successfully" << endl;
                        }
                        else
                        {
                            of1 << cp[0] << "\n";
                            of1 << old;
                            cout << "Passwords Do Not Match" << endl;
                        }
                        of1.close();
                    }
                }
                else
                {
                    cout << "Please Enter a Valid Password" << endl;
                }
            }
            break;
        }

        case 4:
        {
            cout << "------------- Thank You -------------" << endl;
            break;
        }

        default:
            cout << "Enter a Valid Choice";
        }
    } while (a != 4);

    return 0;
}
