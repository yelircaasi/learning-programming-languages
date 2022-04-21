class Motor {
public:
  Motor(int anzZylinder);
  void start();                  // Motor starten
};
class Auto : private Motor {     // Auto hat-einen Motor
public:
  Auto() : Motor{8} { }          // initialisiert ein Auto mit 8 Zylindern
  using Motor::start;            // startet Auto durch Starten des Motors
};

