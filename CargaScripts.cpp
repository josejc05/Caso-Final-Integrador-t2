#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void apply_syntax_coloring(const string& script) {
    cout << "Aplicando coloración sintáctica en Tiny Lisp: " << script << endl;
}

void load_script(const char* filename, bool show_script = false) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }