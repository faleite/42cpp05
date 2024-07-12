# C++
***(Modulo 05)***

## Index

01. **[Nested classes](#nested-classes)**
02. **[Exceptions](#exceptions)**
<!-- 03. **[Unhandled exceptions]()**
04. **[Code that causes an exeception to be thrown]()**
05. **[Nested try blocks]()**
06. **[Add custom exception class]()**
07. **[resources]()** -->

## Nested classes
Uma **classe aninhada** (nested class) é uma classe que é definida dentro do escopo de outra classe. Essas classes são úteis para organizar e agrupar logicamente o código relacionado, especialmente quando a classe aninhada é fortemente associada à classe externa. A classe aninhada pode acessar membros privados da classe que a contém, mas o contrário não é verdade a menos que sejam feitas provisões específicas para isso.

### Exemplos

Aqui está um exemplo básico para ilustrar o conceito de classes aninhadas:

```cpp
#include <iostream>

class Outer {
public:
    Outer(int val) : value(val) {}
    void show() const { std::cout << "Outer value: " << value << std::endl; }

    class Inner {
    public:
        Inner(int val) : innerValue(val) {}
        void show() const { std::cout << "Inner value: " << innerValue << std::endl; }
    private:
        int innerValue;
    };

private:
    int value;
};

int main() {
    Outer outer(10);
    outer.show();

    Outer::Inner inner(20);
    inner.show();

    return 0;
}
```

### Explicações

1. **Definição da Classe Aninhada:**
   - A classe `Inner` é definida dentro da classe `Outer`.
   - `Inner` é uma classe pública de `Outer`, o que significa que pode ser acessada de fora da classe `Outer`.

2. **Criação de Objetos:**
   - Um objeto da classe `Outer` é criado usando o construtor `Outer`.
   - Um objeto da classe `Inner` é criado usando `Outer::Inner`, indicando que `Inner` está dentro do escopo de `Outer`.

3. **Acesso aos Membros:**
   - A classe `Inner` tem seu próprio conjunto de membros, independente da classe `Outer`.
   - `Inner` pode acessar os membros privados da classe `Outer` se necessário, mas nesse exemplo específico, não há tal acesso.

### Acesso aos Membros Privados

Uma classe aninhada pode acessar membros privados da classe externa diretamente. Aqui está um exemplo:

```cpp
#include <iostream>

class Outer {
public:
    Outer(int val) : value(val) {}

    class Inner {
    public:
        void show(const Outer& outer) const { std::cout << "Accessing Outer value: " << outer.value << std::endl; }
    };

private:
    int value;
};

int main() {
    Outer outer(10);
    Outer::Inner inner;
    inner.show(outer);

    return 0;
}
```

Neste exemplo, a classe `Inner` acessa diretamente o membro privado `value` da instância da classe `Outer` passada como argumento.

### Utilização Prática

Classes aninhadas são úteis em várias situações:

1. **Encapsulamento de Implementação:**
   - A classe aninhada pode ser usada para ocultar detalhes de implementação que não devem ser expostos fora da classe externa.

2. **Organização de Código:**
   - Mantém o código relacionado logicamente agrupado, o que pode tornar o código mais limpo e fácil de entender.

3. **Acesso a Membros Privados:**
   - Facilita o acesso a membros privados da classe externa sem a necessidade de friend declarations.

### Conclusão

Classes aninhadas em C++ são uma poderosa ferramenta para organizar e encapsular o código, mantendo o acesso aos membros privados quando necessário. Elas são particularmente úteis quando há uma relação lógica forte entre as duas classes, permitindo um design mais limpo e coeso.

[↑ Index ↑](#index)

## Exceptions
Exceções em C++98 são uma maneira de lidar com erros ou condições excepcionais que ocorrem durante a execução de um programa. Elas permitem que um programa lide com problemas de forma controlada e organizada, separando a lógica de tratamento de erros da lógica principal do programa. O mecanismo de exceções envolve três componentes principais: **lançamento** de exceções, **captura** de exceções e **tratamento** de exceções.

### Componentes do Mecanismo de Exceções

1. **Lançamento de Exceções (Throwing Exceptions)**:
   - Quando uma condição de erro é detectada, uma exceção é lançada usando a palavra-chave `throw`.

2. **Captura de Exceções (Catching Exceptions)**:
   - As exceções lançadas são capturadas por um bloco `catch` correspondente que é capaz de tratar o tipo específico de exceção lançada.

3. **Tratamento de Exceções (Handling Exceptions)**:
   - Dentro do bloco `catch`, o programa pode tentar corrigir o erro, limpar recursos ou tomar outras ações apropriadas.

### Exemplo de Uso de Exceções em C++98

Aqui está um exemplo simples que demonstra como lançar, capturar e tratar exceções em C++98:

```cpp
#include <iostream>
#include <stdexcept> // Para std::runtime_error e std::out_of_range

void functionThatThrows() {
    throw std::runtime_error("An error occurred");
}

void anotherFunctionThatThrows() {
    throw std::out_of_range("Out of range error");
}

int main() {
    try {
        functionThatThrows();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Caught a runtime_error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Caught an unknown exception" << std::endl;
    }

    try {
        anotherFunctionThatThrows();
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Caught an out_of_range exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Caught an unknown exception" << std::endl;
    }

    return 0;
}
```

### Explicação do Exemplo

1. **Lançamento de Exceções**:
   - A função `functionThatThrows` lança uma exceção do tipo `std::runtime_error` usando `throw`.
   - A função `anotherFunctionThatThrows` lança uma exceção do tipo `std::out_of_range`.

2. **Bloco try**:
   - O código que pode lançar uma exceção é colocado dentro de um bloco `try`.

3. **Blocos catch**:
   - Quando uma exceção é lançada, o controle é transferido para o primeiro bloco `catch` que pode manipular o tipo específico da exceção.
   - O bloco `catch (const std::runtime_error& e)` captura exceções do tipo `std::runtime_error`.
   - O bloco `catch (const std::out_of_range& e)` captura exceções do tipo `std::out_of_range`.
   - O bloco `catch (...)` é um bloco de captura geral que pode capturar qualquer tipo de exceção.

4. **Tratamento da Exceção**:
   - Dentro do bloco `catch`, usamos `std::cerr` para imprimir uma mensagem de erro, indicando que uma exceção foi capturada.

### Vantagens do Uso de Exceções

- **Separação da Lógica de Erro**:
  - As exceções permitem separar a lógica de tratamento de erros do código principal, tornando o código mais limpo e legível.
  
- **Gerenciamento de Recursos**:
  - Com exceções, você pode garantir que recursos (como memória, arquivos ou conexões de rede) sejam liberados adequadamente usando técnicas como RAII (Resource Acquisition Is Initialization).

- **Propagação de Erros**:
  - As exceções permitem que os erros sejam propagados para níveis superiores do programa, onde podem ser tratados de forma mais apropriada.

### Considerações

- **Desempenho**:
  - O uso de exceções pode introduzir alguma sobrecarga de desempenho. No entanto, essa sobrecarga geralmente é justificada pela melhoria na robustez e na manutenibilidade do código.

- **Exceções Personalizadas**:
  - Em C++, você pode definir suas próprias classes de exceção para representar diferentes tipos de erros específicos do seu aplicativo.

Exemplo de uma exceção personalizada:

```cpp
#include <iostream>
#include <exception>

class MyException : public std::exception {
public:
    const char* what() const throw() {
        return "My custom exception";
    }
};

void functionThatThrows() {
    throw MyException();
}

int main() {
    try {
        functionThatThrows();
    }
    catch (const MyException& e) {
        std::cerr << "Caught a MyException: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Caught an unknown exception" << std::endl;
    }

    return 0;
}
```

Neste exemplo, a classe `MyException` é uma exceção personalizada que herda de `std::exception` e sobrescreve o método `what()` para fornecer uma mensagem de erro personalizada.

### Conclusão

Exceções são uma ferramenta poderosa em C++98 para tratar erros de forma robusta e estruturada. Elas permitem que o código principal permaneça limpo e focado em sua lógica principal, enquanto o tratamento de erros é delegado a blocos específicos de código. Além disso, exceções ajudam a garantir que os recursos sejam gerenciados adequadamente, evitando vazamentos e outros problemas relacionados.

[↑ Index ↑](#index)
