#include "mein_string.hpp"

static const mein_string ZEBRA { "zebra" };

int main() {
    mein_string tier{ "pferd" };
    if(ZEBRA.equals(tier)) return 0;
    else return 1;
}

