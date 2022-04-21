// 15-utest.cpp
#include <string>
using std::string;

int fib(int n) {
    if(n==0) { return 0; }
    if(n==1) { return 1; }
    int a = 0;
    int b = 1;
    int sum = 1;
    while(n>1) {
        sum += a;
        a = b;
        b = sum;
        n -= 1;
    }
    return sum;
}

string theString(string a) {
    return a;
}

double sqSumDif(double a, double b) {
    return a*a+b*b-a*b;
}

//#define BOOST_TEST_MODULE test_fib
#define BOOST_TEST_MAIN test_main
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_tools.hpp>
namespace {

using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE( test_fib_low )
{
    BOOST_CHECK( fib(0) == 0 );
    BOOST_CHECK( fib(1) == 1 );
    BOOST_CHECK( fib(2) == 1 );
    BOOST_CHECK( fib(3) == 2 );
    BOOST_CHECK( fib(4) == 3 );
    BOOST_CHECK( fib(5) == 5 );
    BOOST_CHECK( fib(6) == 8 );
}

BOOST_AUTO_TEST_CASE( test_theString )
{
    BOOST_CHECK_EQUAL( "ergebnis", theString("ergebnis") );
    BOOST_WARN_EQUAL( "ergbnis", theString("ergebnis") );
}


BOOST_AUTO_TEST_CASE( test_sqSumDif )
{
    BOOST_CHECK_CLOSE( 16.03, sqSumDif(4.1, 3.9), 0.01 );
    BOOST_CHECK_CLOSE( 16.03, sqSumDif(4.1, 3.9), 0.00000000001 );
    BOOST_CHECK_CLOSE_FRACTION( 16.03, sqSumDif(4.1, 3.9), 0.01 );
}

}
