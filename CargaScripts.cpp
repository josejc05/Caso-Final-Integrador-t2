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
    string script((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    if (show_script) {
        cout << "Contenido del archivo '" << filename << "':" << endl;
        cout << script << endl;
    } else {
        cout << "Archivo '" << filename << "' cargado en la consola." << endl;
    }

    apply_syntax_coloring(script);
}
void load_script() {
    string filename;
    cout << "Introduce el nombre del archivo: ";
    cin >> filename;

    load_script(filename.c_str());
}

int main() {
    load_script();

    return 0;
}