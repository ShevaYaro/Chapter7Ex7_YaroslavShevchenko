/*

Tite Chapter 7 Exercise 7 - Number Analysis
File name:Chapter7Ex7_YaroslavShevchenko.cpp
Programmer: Yaroslav Shevchenko
Date: 12/13/2024
Requirements:

Write a program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. 
The program should read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
To test the program, you can download the file numbers.txt from the book’s companion website.

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 12; // 12 numbers
void fileToArray(int arr[SIZE]);
int lowestNum(int arr[SIZE]);
int highestNum(int arr[SIZE]);
int totalNum(int arr[SIZE]);
double avarageNum(int arr[SIZE]);

int main()
{
    int arrNum[SIZE];

    fileToArray(arrNum);

    int lowestN = lowestNum(arrNum);
    int highestN = highestNum(arrNum);
    int totalN = totalNum(arrNum);
    double avgN = avarageNum(arrNum);

    cout << "\nLowest Number: " << lowestN << "\nHighest Number: " << highestN << "\nTotal Number(sum): " << totalN << "\nAvarage Number: " << avgN;
    
}

void fileToArray(int arr[SIZE]) {
    string fileName;
    fstream myFile;

    cout << "Enter the file name: ";
    getline(cin, fileName);

    
    myFile.open(fileName);
    while (!myFile.is_open()) {
        cout << "try again with your file name: ";
        getline(cin, fileName);
        myFile.open(fileName);
    }

    int num;
    if (myFile.is_open()) {
        int i = 0;
        while (myFile >> num && i < SIZE) {
            arr[i] = num;
            i++;
        }
    }
    

    myFile.close();
}

int lowestNum(int arr[SIZE]) {
    int lowest = 1000;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

int highestNum(int arr[SIZE]) {
    int highest = -1;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

int totalNum(int arr[SIZE]) {
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    return sum;
}

double avarageNum(int arr[SIZE]) {
    double sum = 0;
    double count = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
        count++;
    }
    return sum/count;
}
