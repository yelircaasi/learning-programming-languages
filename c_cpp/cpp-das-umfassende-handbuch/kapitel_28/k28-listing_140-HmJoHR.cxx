#include <system_error>
#include <string>

void create_dir(const std::string& pathname, std::error_code& ec) {
#if defined(_WIN32)
  // Windows-Implementierung, mit Windows-Fehlercodes
#elif defined(linux)
  // Linux-Implementierung, mit Linux-Fehlercodes
#else
  // Allgemeingültiger 'generischer' Fall
  ec = std::make_error_code(std::errc::not_supported);
#endif
}

