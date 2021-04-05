#include <stdio.h>
#include <crtdbg.h>
#include "UI/Console.h"
#include "Tests/Test.h"

/// Console->service(Service)->repo(Repository)->array(DynamicalArray)->capacity(int)/length(int)/elements(Estate)

int main(){
    test_all();
    int capacity=100;
    Console *c;
    c = createConsole(capacity);
    run_menu(c);
    int a = _CrtDumpMemoryLeaks();
    printf("Memory leaks: %d", a);
    return 0;
}