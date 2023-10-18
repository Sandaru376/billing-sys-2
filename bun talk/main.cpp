#include <iostream>
#include <fstream>
using namespace std;

class restaurant {
    char Iname[50][50];

public:
    int totalitems;
    float Qty[3];
    float price[3];
    int tprice[3];
    void input();
    void output();
    void calculation();
};

class hel : public restaurant {
public:
    void outputs();
    void sum();
};

int password() {
    string username, password;
    string correctUsername = "sandaru";
    string correctPassword = "123";

    cout << "\t\t\t\t LOGIN TO BUN TALK AUTOMATION SYSTEM" << endl;
    cout << "\t\t\t\t -----------------------------------" << endl;
    cout << "\t\t\t ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "\t\t\t ENTER YOUR PASSWORD: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "\t\t\t Login successful. :)" << endl;

    } else {
        cout << "Invalid username or password. :(" << endl;

    }
}

void restaurant::input() {
    cout << "\nEnter number of items= ";
    cin >> totalitems;

    for (int i = 0; i < totalitems; i++) {
        cout << "\nEnter name of item " << i + 1 << ": ";
        cin >> Iname[i];
        cout << "Enter quantity: ";
        cin >> Qty[i];
        cout << "Enter price of item " << i + 1 << ": ";
        cin >> price[i];
        tprice[i] = Qty[i] * price[i];
    }
}

void restaurant::output() {
    int a=1;

    ifstream infile("COUNT.TXT");
    infile >> a;

    ofstream outfile("COUNT.TXT");
    a += 1;
    outfile << a;
    outfile.close();

    {
        ofstream outfile("HIS.TXT", ios::app);
        outfile << endl << "Bill No.: " << a << endl;
        outfile << "------------------------------------------------------------------------" << endl;
        cout << "\n";

        cout << "Name of Item\tQuantity   Price  Total Price\n";

        for (int i = 0; i < totalitems; i++) {
            outfile << "Name: " << Iname[i] << " Qty: " << Qty[i] << " Price: " << tprice[i] << endl;
            cout << Iname[i] << "\t\t" << Qty[i] << "\t   " << price[i] << "\t   " << tprice[i] << '\n';
        }

        outfile << "------------------------------------------------------------------------" << endl;
        outfile.close();
    }
}

void restaurant::calculation() {
    output();

    float cash = 0, sum = 0, qty = 0, sumt = 0;

    for (int i = 0; i < totalitems; i++) {
        sumt += tprice[i];
        qty += Qty[i];
    }
    cout << "\nTotal:";
    cout << "\n------------------------------------------------------------------------------";
    cout << "\n\tQuantity= " << qty << "\t\t Sum= " << sumt;
    cout << "\n------------------------------------------------------------------------------";
}

int main() {
    restaurant obj;
    char opt, ch;
    ifstream fin;

    if (password() == 0) {

        cout << "Incorrect password. Exiting the program." << endl;
        return 0;
    }

    start:
    cout << "\n\t\t\t\t   ------------------------------";
    cout << "\n\t\t\t\t   Shop Billing Management System";
    cout << "\n\t\t\t\t   ------------------------------";
    cout << "\n\n\t\t\tWhat you want to do?";
    cout << "\n\t\t\t1.\tTo enter a new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";
    cout << "\n\nEnter your option: ";
    cin >> opt;

    switch (opt) {
        case '1':
            obj.input();
            obj.calculation();
            goto start;
        case '2':
            fin.open("HIS.TXT", ios::in);
            while (fin.get(ch)) {
                cout << ch;
            }
            fin.close();
            goto start;
        case '3':
            exit(0);
        default:
            cout << "\a";
    }

    return 0;
}
