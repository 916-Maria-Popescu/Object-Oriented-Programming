#include "TestAll.h"
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"

void test_all(){
    TestMovie tm;
    tm.test_all();

    TestService ts;
    ts.test_all();

    TestRepository tr;
    tr.test_all();

}
