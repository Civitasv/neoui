#include <gtk/gtk.h>
#include <iostream>

#include "cxxopts/cxxopts.hpp"
#include "neoui.h"
#define CV_STRING_IMPLENTATION
#include "cv_string.h"

void UI(int argc, char* argv[])
{
  // Create a new application
  GtkApplication* app
    = gtk_application_new("com.example.GtkApplication", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(neoui::on_activate), NULL);
  g_application_run(G_APPLICATION(app), argc, argv);
}

void parse(int argc, char* argv[])
{
  cxxopts::Options options(argv[0], "Neovim UI");

  // clang-format off
  options.add_options()
    ("h,help", "Print usage");
  // clang-format on

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  UI(argc, argv);
}

int main(int argc, char** argv)
{
  parse(argc, argv);

  return 0;
}
