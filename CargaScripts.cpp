#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false)
{
    if (!fs::exists(filename)) {
        cerr << "Error: El archivo " << filename << " no existe." << endl;
        return;
    }

    string script;
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Fallo en la operación de apertura del archivo " << filename << endl;
        return;
    }

    script.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    if (show_script) {
        cout << ColorConsole::fg_blue << ColorConsole::bg_white;
        cout << script << endl;
    }
    consoleBox->new_text();
    consoleBox->set_text(script);
}

void load_script()
{
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}

int main()
{
    load_script();

    return 0;
}
