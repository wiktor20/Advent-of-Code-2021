// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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

    int arr1[4] = {-1, -1, -1, -1};
    int count = 0;
    int sum1, sum2;
    sum1 = sum2 = count;
    int start = 0;
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        inf >> strInput;
        // std::cout << strInput << '\n';
        stringstream ss(strInput);
        int x = 0;
        ss >> x;
        if (start < 3) {
            arr1[start + 1] = x;
            start++;
        }
        else {
            arr1[0] = arr1[1];
            arr1[1] = arr1[2];
            arr1[2] = arr1[3];
            arr1[3] = x;
           
            sum1 = arr1[0] + arr1[1] + arr1[2];
            sum2 = arr1[1] + arr1[2] + arr1[3];

           if (sum2 > sum1) { count++; }
        }
    }
    cout << count;
    return 0;
}

