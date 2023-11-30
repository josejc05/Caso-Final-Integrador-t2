#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

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
    string script;
    ifstream file(filename);

    if (!file) {
        if (file.fail()) {
            cerr << "Error: Fallo en la operación de apertura del archivo " << filename << endl;
        } else {
            cerr << "Error: El archivo " << filename << " no existe." << endl;
        }
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