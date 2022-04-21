Page page = Html().body()
    .h1("Ueberschrift")
    .table().border(0)
      .tr()
        .td().css("head").text("Hunderasse").end()
        .td().text("Pudel").end()
      .end()
    .end()
    .toPage();

