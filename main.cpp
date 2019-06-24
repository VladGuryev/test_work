#include <iostream>
#include <custom_dictionary.h>
#include "custom_not_found_exception.h"
using namespace std;

int main()
{
    CustomDictionary<int, std::string> dict;
    dict.Set(1, "a");
    dict.Set(2, "b");
    cout << dict.Get(1) << endl;
    cout << dict.Get(2) << endl;

    try {
        cout << dict.Get(3);
    } catch (CustomNotFoundException<int> e) {
        cout << "exception thrown: " << e.what() << endl;
    }
    int keyFound = 2;
    cout << "Is key " << keyFound << " in the dictionary? ";
    if(dict.IsSet(keyFound)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    int keyNotFound = 3;
    cout << "Is key " << keyNotFound << " in the dictionary? ";
    if(dict.IsSet(keyNotFound)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
