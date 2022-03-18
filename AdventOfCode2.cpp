#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    std::ifstream inf{ "Sample.txt" };
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    int aim = 0;
    int horz = 0;
    int depth = 0;
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        inf >> strInput;
        //std::cout << strInput << '\n';
        if (strInput == "forward") {
            inf >> strInput;
            stringstream ss(strInput);
            int x = 0;
            ss >> x;
            horz += x;
            depth += x * aim;
        }
        else if (strInput == "up") {
            inf >> strInput;
            stringstream ss(strInput);
            int x = 0;
            ss >> x;
            aim -= x;
        }
        else if (strInput == "down") {
            inf >> strInput;
            stringstream ss(strInput);
            int x = 0;
            ss >> x;
            aim += x;
        }
        //std::cout << strInput << '\n';
    }
    cout << horz << '\n';
    cout << depth << '\n'   ;
    cout << horz * depth << '\n';
    return 0;
}
