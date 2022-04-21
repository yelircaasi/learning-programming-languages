#include "qwort/qwort.hpp" // under test
#define BOOST_TEST_MODULE qwort
#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE( version_is_1 ) {
    BOOST_TEST(qw::version() == 1);
    // der folgende Vergleich soll fehlschlagen, aber nur eine Warnung erzeugen:
    BOOST_WARN_EQUAL(qw::version(), 2);
}
BOOST_AUTO_TEST_CASE( init_size_0 ) {
    qw::index inst{};                     // arrange
    auto sz = inst.size();                // act
    BOOST_TEST(sz == 0u);                 // assert
}
BOOST_AUTO_TEST_CASE( add_size_1 ) {
    using namespace std::literals::string_literals;
    qw::index inst{};                     // arrange
    inst.add(""s);                        // act
    BOOST_REQUIRE_EQUAL(inst.size(), 1u); // assert
}
BOOST_AUTO_TEST_CASE( normalize ) {
    using namespace std::literals::string_literals;
    qw::index inst{}; // arrange
    // acts und asserts; könnte auch in getrennten Funktionen sein
    BOOST_CHECK_EQUAL(inst.normalize("a"s), "A"s);
    BOOST_CHECK_EQUAL(inst.normalize("Stadt"s), "STADT"s);
    BOOST_CHECK_EQUAL(inst.normalize("Leer Zeichen"s), "LEER#ZEICHEN"s);
    BOOST_CHECK_EQUAL(inst.normalize("!Sym-bol."s), "#SYM#BOL#"s);
}
BOOST_AUTO_TEST_CASE( move ) {
    qw::index inst{};
    qw::index other = std::move( inst );
    BOOST_CHECK_EQUAL(other.size(), 0u); // pimpl erfolgreich verschoben?
}

