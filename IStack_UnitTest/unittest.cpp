
#include "Istack.h"
#include <fstream>
#include <String>
#include <iostream>
using namespace std;
#define file1 "in.txt"
#define file2 "inR.txt"

class UnitTest {
private:
    ifstream in;
    ifstream inR;
public:
    UnitTest() {
        in.open(file1);
        inR.open(file2);
        if (in && inR) {}
        else {
            throw exception();
        }
    }

    void testAll() {
        testStackEmptyFunc();
        testStackPopFunc();
        testStackPushFunc();
        testStackSizeFunc();
    }

    void testStackEmptyFunc() {
        Stack<string> myStack;
        assert(myStack.empty());
    }

    void testStackSizeFunc() {
        Stack<string> myStack;
        string s;
        int cnt = 0;
        while (getline(in, s)) {
            myStack.push(s);
            ++cnt;
            assert(cnt == myStack.size());
        }
    }

    void testStackPushFunc() {
        Stack<string> myStack;
        string s;
        while (getline(in, s)) {
            myStack.push(s);
            string tmp = myStack.top();
           assert(tmp == s);
        }
    }

    void testStackPopFunc() {
        Stack<string> myStack;
        string s;
        while (getline(in, s)) {
            myStack.push(s);
        }
        while (getline(inR, s)) {
            string tmp = myStack.top();
            myStack.pop();
            //cerr  << tmp << s;
            assert(tmp == s);
        }
    }
};
