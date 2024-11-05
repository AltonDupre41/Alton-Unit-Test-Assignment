#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "MergeSort.h"

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//Note, a good chunk of code dervives from some merge sort code online, this is moreso a demonstration of its use cases
int main(int argc, char *argv[]) {
    vector<int> inputArr;
    string input;
    int inputSize = 0;
    bool endInput = false; 
    printf("--------------------------------------------------------------------------------\nMERGE SORT ALGORITHM for Assignment\n--------------------------------------------------------------------------------\n");
    
    printf("Enter an array of numbers (ex: ( 1 200 27 )).\nIf no inputs are made the program enters test mode: ");
    do
    {
        cin >> input;

        while((int)input.find(",") >= 0){input.erase(input.find(","),1);}

        while((int)input.find("(") >= 0){input.erase(0,1);}

        while ((int)input.find(")") >= 0){
            input.pop_back();
            endInput = true;
            }

        if (is_number(input) && input.size() != 0) {
            inputArr.push_back(stoi(input));
            inputSize++;
        }
        
    } while (!endInput);

    if (inputSize > 0){        
        if (inputArr.size() <= 0){
            printf("ERROR: No Numbers Entered or A String Has Been Entered");
            exit(1);
        }
        
        printf("Input: ");
        strArr(inputArr);
        mergeSort(inputArr, 0, (int)inputArr.size() - 1);
        printf("Output: ");
        strArr(inputArr);

        return 0;
    }
    
    printf("No Input Given, Deploying Test Mode:\n");

    printf("------------\nPositive cases\n------------\n");
    vector<int> posArr1 = {3, 2, 1 };
    vector<int> posArr2 = {2, 2, 4, 7, 12, 100, -1 };
    printf("\n");
    printf("Input: ");
    strArr(posArr1);
    mergeSort(posArr1, 0, (int)posArr1.size() - 1);
    printf("Output: ");
    strArr(posArr1);
    printf("\n");

    printf("Input: ");
    strArr(posArr2);
    mergeSort(posArr2, 0, (int)posArr2.size() - 1);
    printf("Output: ");
    strArr(posArr2);
    printf("\n");

    printf("------------\nNegative cases\n------------\n");
    printf("\n");
    printf("any strings or unavailable characters inputed in the program will result in an error.\n");
    printf("program is also made to handle alternate array inputs like \nif someone inputs (1 2 3) or ( 1, 2, 3) the program will function correctly");
    printf("\n");
    printf("------------\nPerformance cases\n------------\n");
    printf("\n");
    printf("Large Sorted Array\n");
    vector<int> largeSortedArray(10000);
    printf("Input: ");
    strArr(largeSortedArray);
    mergeSort(largeSortedArray, 0, (int)largeSortedArray.size() - 1);
    printf("Output: ");
    strArr(largeSortedArray);
    printf("\n");
    
    printf("------------\nBoundary cases\n------------\n");
    printf("\n");
    printf("Any input with an incorrect array or an array with nothing will lead to these tests or to an error\n");
    printf("\n");

    printf("------------\nIdempotency cases\n------------\n");
    printf("\n");
    posArr2 = {2, 2, 4, 7, 12, 100, -1 };
    printf("Input: ");
    strArr(posArr2);
    mergeSort(posArr2, 0, (int)posArr2.size() - 1);
    printf("Output: ");
    strArr(posArr2);
    printf("\n");

    posArr2 = {2, 2, 4, 7, 12, 100, -1 };
    printf("Input: ");
    strArr(posArr2);
    mergeSort(posArr2, 0, (int)posArr2.size() - 1);
    printf("Output: ");
    strArr(posArr2);
    printf("\n");

    posArr2 = {2, 2, 4, 7, 12, 100, -1 };
    printf("Input: ");
    strArr(posArr2);
    mergeSort(posArr2, 0, (int)posArr2.size() - 1);
    printf("Output: ");
    strArr(posArr2);
    printf("\n");
    printf("\n");

    posArr2 = {2, 2, 4, 7, 12, 100, -1 };
    printf("Input: ");
    strArr(posArr2);
    mergeSort(posArr2, 0, (int)posArr2.size() - 1);
    printf("Output: ");
    strArr(posArr2);
    printf("\n");
    printf("\n");

    return 0;
}