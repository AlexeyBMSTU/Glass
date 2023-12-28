
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <ctime>
#include <fstream>

using namespace std;

class Error {
public: 
    class Stock {
    public:

        int size;           //Size of requests
        int price[555];     //Price
        string type[555];   //Buy or sell
        int Stype[555];
        int number[555];

        int add(int price[], int size, string type[], int Stype[], int number[]) {
            for (int i = 1; i <= size; i++) {
                cout << "Request #" << number[i] << " Price: " << price[i] << " Type: " << type[i] << endl;
            }
             return 0;
        }

        int edit(int price[], int size, string type[], int Stype[], int number[]) {
            for (int i = 1; i <= size; i++) {
                cout << "New request #" << number[i] << " Price: " << price[i] << " Type: " << type[i] << endl;
            }
            return 0;
        }

        int del(int price[], int size, string type[], int Stype[], int number[]) {
            for (int i = 1; i <= size; i++) {
                price[i] = NULL;
                number[i] = NULL;
                cout << price[i];
            }
            return 0;
        }

        int view(int price[], int size, string type[], int Stype[], int number[]) {

            //Sorting bubble

            for (int i = 1; i <= size; i++) {
                for (int j = i + 1; j <= size; j++) {
                    if (Stype[i] == 3) {
                        if (price[j] >= price[i]) {

                            int temp_price;
                            temp_price = price[i];
                            price[i] = price[j];
                            price[j] = temp_price;

                            int temp_type;
                            temp_type = Stype[i];
                            Stype[i] = Stype[j];
                            Stype[j] = temp_type;

                            int temp_number;
                            temp_number = number[i];
                            number[i] = number[j];
                            number[j] = temp_number;
                        }
                    }
                    else if (Stype[i] == 4) {
                        if (price[j] <= price[i]) {

                            int temp_price;
                            temp_price = price[i];
                            price[i] = price[j];
                            price[j] = temp_price;

                            int temp_type;
                            temp_type = Stype[i];
                            Stype[i] = Stype[j];
                            Stype[j] = temp_type;

                            int temp_number;
                            temp_number = number[i];
                            number[i] = number[j];
                            number[j] = temp_number;
                        }
                    }
                }
            }

            cout << "TOP for BUY: " << endl;
            for (int i = 1; i <= size; i++) {
                if (Stype[i] == 3) {
                    cout << i << ". " << price[i] << "$ - Request #" << number[i] << endl;
                }
            }

            cout << "TOP for SELL: " << endl;
            for (int j = 1; j <= size; j++) {
                if (Stype[j] == 4) {
                    cout << j << ". " << price[j] << "$ - Request #" << number[j] << endl;
                }
            }

            return 0;
        }
    };

    void error(int er) {
        if (er == 0) {
            cout << "Error, please try again" << endl;
        }
    }
};




int main()
{
    int timer = 1;
    ofstream F;
    (F.open("input.txt", ios::out));

    while (true) {
        Error::Stock  request;
        Error flag;
        int method;

        cout << "\nWrite method: (1. Add| 2. Edit| 3. Delete| 4. View) (only number)\n"; 
        cin >> method;

        switch (method) {

        case 1:
            cout << "Write to size: " << endl;
            cin >> request.size;

            cout << "Write to type:" << endl;

            for (int i = 1; i <= request.size; i++) {

                cin >> request.type[i];
                request.Stype[i] = request.type[i].size();
                request.number[i] = i;

            }

            cout << "Write to price: " << endl;

            for (int i = 1; i <= request.size; i++) {

                cin >> request.price[i];

            }

            if (request.add(request.price, request.size, request.type, request.Stype, request.number)) {
                flag.error(0);
            }
            else {
                flag.error(1);
            }
            break;

        case 2:
            cout << "Write to size: " << endl;
            cin >> request.size;

            cout << "Write to type:" << endl;

            for (int i = 1; i <= request.size; i++) {

                cin >> request.type[i];
                request.Stype[i] = request.type[i].size();
                request.number[i] = i;
                //(new Stock())->add(price[i], size, type);
            }

            cout << "Write to price: " << endl;

            for (int i = 1; i <= request.size; i++) {

                cin >> request.price[i];
                //(new Stock())->add(price[i], size, type);
            }

            if (request.edit(request.price, request.size, request.type, request.Stype, request.number)) {
                flag.error(0);
            }
            else {
                flag.error(1);
            }

            break;

        case 3:
            if (request.del(request.price, request.size, request.type, request.Stype, request.number)) {
                flag.error(0);
            }
            else {
                flag.error(1);
            }
            break;

        case 4:
            if (request.view(request.price, request.size, request.type, request.Stype, request.number)) {
                flag.error(0);
            }
            else {
                flag.error(1);
            }
            break;
        }
        

         cout << "\nruntime in " << timer << " time: " << clock() / 1000;
         F <<"runtime in "<<timer<<" time:  " << clock() / 1000 <<"s" << endl;
         timer++;     
    }
    return 0;
}