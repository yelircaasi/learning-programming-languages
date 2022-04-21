struct StereoImage {
    Image* rechts_;
    Image* links_;
    StereoImage(const string& nameBase)           // konstruieren
      : rechts_{new Image{nameBase+"rechts.jpg"}} // okay
      , links_{new Image{nameBase+"links.jpg"}}   // gefährlich
      { }
    ~StereoImage() { // entfernen
        delete rechts_; delete links_;
    }
    StereoImage(const StereoImage&) = delete;     // keine Kopie
    StereoImage& operator=(const StereoImage&) = delete; // keine Zuweisung
};
int main() {
    Image* bild = new Image{"bild.jpg"};          // einem rohen Zeiger?
    StereoImage stereo{"3d"};
    delete bild;
}

