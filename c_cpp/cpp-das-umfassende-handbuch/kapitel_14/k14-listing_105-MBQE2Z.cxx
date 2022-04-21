#define BOOST_TEST_MAIN test_main             // generiert main() in diesem Modul
#include <boost/test/included/unit_test.hpp>  // Framework
#include <boost/test/test_tools.hpp>          // BOOST_CHECK etc
unsigned fib(unsigned n);                     // zu testen
namespace {
using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE( test_fib_low )          // beliebiger Name des Testcases
{
    BOOST_CHECK( fib(0) == 0 );               // einzelne Assertions
    BOOST_CHECK( fib(1) == 1 );
    BOOST_CHECK( fib(2) == 1 );
    BOOST_CHECK( fib(3) == 2 );
    BOOST_CHECK( fib(4) == 3 );
    BOOST_CHECK( fib(5) == 5 );
    BOOST_CHECK( fib(6) == 8 );
}
}

