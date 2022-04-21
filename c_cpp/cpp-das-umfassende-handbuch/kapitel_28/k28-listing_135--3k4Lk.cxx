auto res = fib(45);
// ...
std::cout << "Zeit: " << duration_cast<seconds>(t1-t0).count() << "s\n";
// Ausgabe: Zeit: 7s (z. B.)
std::cout << "Zeit: " << duration<double>{t1-t0}.count() << "s\n";
// Ausgabe: Zeit: 7.35303s (z. B.)
}

