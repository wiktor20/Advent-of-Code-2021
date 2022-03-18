#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::ifstream inf{ "Sample.txt" };
    vector<string> list;
    
    //Read file into Vector
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        inf >> strInput;
        // std::cout << strInput << '\n';
        if (strInput.size() > 0) { //Checks to make sure valid string inside strInput otherwise crash when access
            list.push_back(strInput);
        }
    }

    for (int x = 0; x < 12; x++) {
        if (list.size() == 1) {   //Checks if 1 element left
            break;
        }
        int sum = 0;
        // cout << sum << endl;
        for (int y = 0; y < list.size(); y++) {  //Checks if more 1s or 0s as MSB
            if (list[y][x] == '1') {
                sum += 1;
            }
            else {
                  sum -= 1;
            }
        }
        char MSB = (sum < 0) ? '0' : '1'; //Determines MSB using MSB

        int size = list.size();
        for (int y = 0; y < size; y++) { //Deletes elements from vector with least common MSB
           if (list[y][x] != MSB) {
                list.erase(list.begin() + y); //Needs iterator
                y--; //Technically next element is one ahead but gets moved back one so needs to be reset
                size--; //Otherwise will go past size and try to access outside of Vector
            }
        }
   //     cout << sum << endl;
   }


    //Prints out all of the elements in Vector
    for (int y = 0; y < list.size(); y++) {
        cout << list[y] << endl;
    }

    cout << endl;
    return 0;
}
}
*/