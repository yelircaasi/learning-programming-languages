} // namespace
int main(int argc, const char* argv[]) {
    try {
        const vector<string> fNamen {argv+1, argv+argc};
        for(auto fName : fNamen) {
            std::cout << "packe " << fName << "... ";
            packe(fName, fName+".gz");
            std::cout << fName << ".gz"<< "\n";
        }
    } catch(std::runtime_error exc) {
        std::cerr << "Fehler: " << exc.what() << "\n";
    }
}

