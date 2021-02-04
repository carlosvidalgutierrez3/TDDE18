#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// TODO: 1-1. done
// TODO: 1-4. done
// TODO: 7-1. done
// TODO: Use setw and setfill to print out lines with repeating characters such as "=====" "    " etc. done
// TODO: Separate code in to sections using empty lines, i.e every input is a section etc.
//       Be consistent with the ammount of lines! done

// Comment: Good job using cerr! :D
// TODO: 1-3. if you split up an operator chain, i.e cout, then the next line
//            should always start with the operator and be indented to be under
//            cout << "Hello there!"
//                 << "General Kenobi!" << endl; done

int main(){

    float llimit{};
    float hlimit{};
    float stride{};
    float percentage{};
    float price{};
    float tax{};
    int steps{};

    cout << "INPUT PART" << endl
          << setfill ('=') << setw (9) << "=" << endl // If I don't write something behind setw(), it wont print the fill characters
          << "Please enter first price: ";
    cin >> llimit;
    cin.ignore(1000,'\n');

    while (llimit < 0){
        cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << "Please enter first price: ";
        cin >> llimit;
        cin.ignore(1000,'\n');
    }

    cout << "Please enter last price: ";
    cin >> hlimit;
    cin.ignore(1000,'\n');

    while (hlimit < llimit){
        cerr << "ERROR: Last price must be greater or equal than first price" << endl;
        cout << "Please enter second price: ";
        cin >> hlimit;
        cin.ignore(1000,'\n');
    }

    cout << "Please enter stride: ";
    cin >> stride;
    cin.ignore(1000,'\n');

    while (stride < 00.01){
        cerr << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Please enter stride: ";
        cin >> stride;
        cin.ignore(1000,'\n');
    }

    cout << "Please enter tax percent: ";
    cin >> percentage;
    cin.ignore(1000,'\n');

    while (percentage < 0){
        cerr << "ERROR: Tax percentage must be at least 0" << endl;
        cout << "Please enter tax percent: ";
        cin >> percentage;
        cin.ignore(1000,'\n');
    }

    cout << "\nTAX TABLE\n"
          << setfill('=') << setw(9) << "=" << endl
          << setfill(' ') << setw(12) << "Price"
          << setw(13) << "Tax"
          << setw(18) << "Price with tax" << endl
          << setfill('-') << setw(44) << "-" << endl;

    steps = 1+(hlimit-llimit)/stride;
    price = llimit;
// TODO: 8-8. Your program does not print the last line of the table for 10, 20, 0.02, 100. done
    for(int i=0; i<steps; i++){
        tax = percentage*price/100;
        cout << setfill(' ') << setw(11) << setprecision(2) << fixed << price
              << setw(14)  << setprecision(2) << fixed << tax
              << setw(18)  << setprecision(2) << fixed << price+tax << endl;
        price = price + stride;
    }

    return 0;
}
