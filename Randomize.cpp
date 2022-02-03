// Randomize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using std::random_device;
using std::uniform_int_distribution;
using std::mt19937;
using std::vector;
using std::find;
using std::endl;
using std::cout;


int  RANDOM(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(a, b);
    int randNum = distrib(gen);
    return randNum;
}

vector<int> randInPlace(vector<int> a) {
    int n = a.size();
    int temp;
    int rLoc;
    for (int i = 0; i < n; ++i) {
        rLoc = RANDOM(i, n-1);
        temp = a[rLoc];
        a[rLoc] = i;
        a[i] = temp;
    }
    return a;
}

vector<int> randomSample(int n,int m,int*count) {
    if (m == 0) {
        vector<int> b = {};
        return b;
    }
    vector<int> sampleList = randomSample(n - 1, m - 1, count);
    int i = RANDOM(1, n);
    (*count)++;
    if (find(sampleList.begin(), sampleList.end(), i) != sampleList.end()) {
        sampleList.push_back(n);
    }
    else {
        sampleList.push_back(i);
    }
    return sampleList;

}
int main()
{
    vector<int> a = { 1 , 2 ,3 ,4 ,5,6 };
    cout << "Random Number between 1 and 6: " << RANDOM(1, 6) << endl;
    
    //Uniformity test
    int aray[10];
    for (int i = 0; i < 10; ++i) {
        aray[i] = 0;
    }
    cout << "Testing Uniformity\n";
    for (int i = 0; i < 20000; ++i) {
        aray[RANDOM(0, 9)]++;
    }
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << " occured " << aray[i] << " times\n";
    }
    

    //Randomize in place test
    cout << "Testing Randomize in Place\nPrePermute:\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }
    vector<int> postPer = randInPlace(a);
    cout << "\nPost Permute\n";
    for (int i = 0; i < postPer.size(); i++) {
        cout << postPer[i];
    }
    cout << endl;


    //Random Sample test
    int c = 0;
    int narray[10];
    for (int i = 0; i < 10; ++i) {
        narray[i] = 100*(i+1);
    }
    vector<int> test;
    int marray[5] = { 5,10,25,50,100 };
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            randomSample(narray[i], marray[j], &c);
            cout << "N value: " << narray[i] << " and M value: " << marray[j] << " calls random: " << c << " times" << endl;
            c = 0;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
