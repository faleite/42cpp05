# C++
***(Modulo 05)***

## Index

01. **[Nested classes]()**
02. **[Exceptions]()**
03. **[Unhandled exceptions]()**
04. **[Code that causes an exeception to be thrown]()**
05. **[Nested try blocks]()**
06. **[Add custom exception class]()**
07. **[resources]()**

## Sub-typing polymorphism
**Definimos Polimorfismo** *como um princípio a partir do qual as classes derivadas de uma única classe base são capazes de invocar os métodos que, embora apresentem a mesma assinatura,comportam-se de maneira diferente para cada uma das classes derivadas. (A palavra significa ter muitas formas)*

**O Polimorfismo** *é um mecanismo por meio do qual selecionamos as funcionalidades utilizadas de forma dinâmica por um programa no decorrer de sua execução.*

*Com o Polimorfismo, os mesmos atributos e objetos podem ser utilizados em objetos distintos, porém, com implementações lógicas diferentes.*

-***Subtyping polymorphism***, também conhecido como **polimorfismo de subtipo** ou** polimorfismo de inclusão**, é um conceito da orientação a objetos onde um tipo derivado `(subtipo)` pode ser usado no lugar de um tipo base `(supertipo)`. Em outras palavras, um objeto de uma classe derivada pode ser tratado como se fosse um objeto da classe base. Isso permite que funções trabalhem com objetos de diferentes classes que compartilham a mesma interface ou superclasse.

**Destrutores Virtuais***: Sempre declare destrutores virtuais nas classes base para garantir que os destrutores das classes derivadas sejam chamados corretamente.*

***Exemplo:***
```cpp
#include <iostream>

// Classe base
class Animal {
public:
    // Construtor
    Animal() {
        std::cout << "Animal constructor called" << std::endl;
    }

    // Destrutor virtual
	/* O destrutor é virtual para garantir que o destrutor correto seja 
	chamado para objetos derivados. Ele também imprime uma mensagem 
	indicando que foi chamado.*/
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }

	// Função virtual pura (método abstrato)
	/* A classe Animal é uma classe base abstrata com um método virtual puro
	makeSound. Isso significa que Animal não pode ser instanciada diretamente.*/
    virtual void makeSound() const = 0;
};

// Classe derivada Dog
class Dog : public Animal {
public:
    // Construtor
    Dog() {
        std::cout << "Dog constructor called" << std::endl;
    }

    // Destrutor
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }

    // Sobrescrevendo o método makeSound
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

// Classe derivada Cat
class Cat : public Animal {
public:
    // Construtor
    Cat() {
        std::cout << "Cat constructor called" << std::endl;
    }

    // Destrutor
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
    }

    // Sobrescrevendo o método makeSound
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Array de ponteiros para Animal
    Animal* animals[2];

    // Adicionando objetos Dog e Cat ao array
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Loop através do array e chamando makeSound para cada animal
    for (int i = 0; i < 2; ++i) {
		/*Aqui, o polimorfismo entra em ação, pois a chamada para makeSound
		resolve para a versão apropriada do método (Dog ou Cat), dependendo 
		do tipo real do objeto.*/
        animals[i]->makeSound();
    }

    // Limpando a memória alocada dinamicamente
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}
```
[↑ Index ↑](#index)
