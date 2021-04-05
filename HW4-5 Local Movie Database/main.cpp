#include <iostream>
#include "UI/Console.h"
#include "Tests/TestAll.h"

using namespace std;

void runprog(){
    //test_all();
    Console c;
    c.run_menu();
}

int main () {
    runprog();
    //int a = _CrtDumpMemoryLeaks();
    //cout<<"Memory leaks: "<<a;
    return 0;

}