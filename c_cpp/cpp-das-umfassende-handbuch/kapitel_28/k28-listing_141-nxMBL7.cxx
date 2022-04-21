#include <system_error>
#include <iostream>
using std::error_code; using std::system_category;
namespace mylib {

    // eigene Errorcodes
    enum class errc { LOAD_ERR = 1, UNLOAD_ERR = 2, OTHER_ERR = 3 };

    error_code make_error_code(errc ec) {
        switch(ec) {
        case errc::LOAD_ERR: return error_code((int)ec, system_category());
        case errc::UNLOAD_ERR: return error_code((int)ec, system_category());
        case errc::OTHER_ERR: return error_code((int)ec, system_category());
        }
    }
    error_code run(int arg) {
        if(arg == 667) {
            return make_error_code(errc::OTHER_ERR);
        }
        return error_code{}; // alles gut.
    }
}
int main() {
    std::error_code ec = mylib::run(667);
    if(!ec) {
        std::cout << "Klasse, klappt!\n";
    } else if (ec == mylib::make_error_code(mylib::errc::OTHER_ERR)) {
        std::cout << "Anderer Fehler\n";
    } else {
        std::cout << "Nix los hier\n" << ec;
    }
}

