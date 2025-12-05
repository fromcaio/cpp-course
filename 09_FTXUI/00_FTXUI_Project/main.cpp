#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main() {
  using namespace ftxui;

  // Compose three bordered text boxes; `flex` lets the middle expand.
  Element document = hbox({
    text("left")   | border,
    text("middle") | border | flex,
    text("right")  | border,
  });

  // Fit height to the document and take full terminal width.
  auto screen = Screen::Create(
    Dimension::Full(),
    Dimension::Fit(document)
  );

  Render(screen, document);
  screen.Print();
}