#include <iostream>
#include <cstring>  // Para a função strcpy e strlen

class Pessoa {
private:
    char* nome;  // Ponteiro para armazenar o nome dinamicamente

public:
    // 1. Construtor padrão
    Pessoa() : nome(nullptr) {
        std::cout << "Construtor padrão chamado." << std::endl;
    }

    // 2. Construtor parametrizado (extra)
    Pessoa(const char* n) {
        nome = new char[strlen(n) + 1];
        strcpy(nome, n);
        std::cout << "Construtor parametrizado chamado." << std::endl;
    }

    // 3. Construtor de cópia
    Pessoa(const Pessoa& outra) {
        nome = new char[strlen(outra.nome) + 1];  // Aloca memória para a cópia
        strcpy(nome, outra.nome);
        std::cout << "Construtor de cópia chamado." << std::endl;
    }

    // 4. Operador de atribuição
    Pessoa& operator=(const Pessoa& outra) {
        if (this != &outra) {  // Evita autoatribuição
            delete[] nome;  // Libera a memória existente
            nome = new char[strlen(outra.nome) + 1];  // Aloca nova memória
            strcpy(nome, outra.nome);
        }
        std::cout << "Operador de atribuição chamado." << std::endl;
        return *this;
    }

    // 5. Destrutor
    ~Pessoa() {
        delete[] nome;  // Libera memória alocada
        std::cout << "Destrutor chamado." << std::endl;
    }

    // Método para exibir o nome
    void mostrarNome() const {
        if (nome) {
            std::cout << "Nome: " << nome << std::endl;
        } else {
            std::cout << "Nome: (vazio)" << std::endl;
        }
    }
};

int main() {
    Pessoa p1("Alice");    // Construtor parametrizado
    Pessoa p2 = p1;        // Construtor de cópia
    Pessoa p3;             // Construtor padrão
    p3 = p1;               // Operador de atribuição

    p1.mostrarNome();
    p2.mostrarNome();
    p3.mostrarNome();

    return 0;
}
