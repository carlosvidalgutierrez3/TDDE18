#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// TODO: 7-1.
// TODO: 4-3. Most manipulators are permanent except setw.
// TODO: 1-3. if you split up an operator chain, i.e cout, then the next line
//            should always start with the operator and be indented to be under
//            cout << "Hello there!"
//                 << "General Kenobi!" << endl;
// TODO: 1-4.

// Comment: Good naming convention and good structure! Good job! :D

int main(){
    int num{};
    float numf{};
    char letter{};
    string str{};

    cout << "Enter one integer: ";
	cin >> num;
    cout << "You entered the number: "  << num << "\n" << endl;
    cin.ignore(1000,'\n');

    cout << "Enter four integers: ";
    cin >> num;
    cout << "You entered the numbers: " << num << " ";
    cin >> num;
    cout << num << " ";
    cin >> num;
    cout << num << " ";
    cin >> num;
    cout << num << "\n"<< endl;
    cin.ignore(1000,'\n');

    cout << "Enter one integer and one real number: ";
    cin >> num >> numf;
    cout << "The real is: " << setprecision(3) << fixed << setw(9) <<numf << endl;
    cout << "The integer is: " << setw(6) << num << "\n" << endl;
    cin.ignore(1000,'\n');

    cout << "Enter one real and one integer number: ";
    cin >> numf >> num;
    cout << "The real is: " << setprecision(3) << fixed << setfill('.') << setw(9) <<numf << endl;
    cout << "The integer is: " << setfill('.') << setw(6) << num << "\n" << endl;
    cin.ignore(1000,'\n');

    cout << "Enter a character: ";
    cin >> letter;
    cout << "You entered: " << letter << "\n" << endl;
    cin.ignore(1000,'\n');

    cout << "Enter a word: ";
    cin >> str;
    cout << "The word '" << str << "' has " << str.size() << " character(s)" << "\n" <<endl;
 	cin.ignore(1000,'\n');

    cout << "Enter an integer and a word: ";
    cin >> num >> str;
    cout << "You entered '" << num << "' and '" << str << "' ." << "\n" <<endl;
    cin.ignore(1000,'\n');

    cout << "Enter an character and a word: ";
    cin >> letter >> str;
    cout << "You entered the string \"" << str << "\" and the character '" << letter << "' ." << "\n" <<endl;
    cin.ignore(1000,'\n');

    cout << "Enter a word and a real number: ";
    cin >> str >> numf;
    cout << "You entered \"" << str << "\" and  \"" << numf << "\" ." << "\n" <<endl;
    cin.ignore(1000,'\n');

    cout << "Enter a text-line: ";
    getline(cin,str);
    cout << "You entered: \"" << str << "\"\n" <<endl;

    cout << "Enter a second line of text: ";
    getline(cin,str);
    cout << "You entered: \"" << str << "\"\n" << endl;

    cout << "Enter three words: ";
    cin >> str;
    cout <<"You entered: \'" << str << " ";
    cin >> str;
    cout << str << " ";
    cin >> str;
    cout << str << "\'";

    return 0;
}
