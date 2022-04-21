class Auto {
public:
  Auto() : motor_{8} { }           // initialisiert ein Auto mit 8 Zylindern
  void start() { motor_.start(); } // startet Auto durch Starten des Motors
private:
  Motor motor_;                    // Auto hat-einen Motor
};

