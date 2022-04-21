struct StereoImage {
  Image *left, *right;
  StereoImage()
  : left(new Image)
  , right(new Image) // Gefahr!
  { }
  ~StereoImage() {
      delete left;
      delete right;
  }
};

