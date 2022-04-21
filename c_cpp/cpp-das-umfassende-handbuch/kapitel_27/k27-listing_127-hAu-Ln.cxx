#include <fstream>
int main() {
    std::ofstream file("logfile.log");
    file << "Text für das Protokoll";
    file.flush();
}

