#include <iostream>
#include <string>

using namespace std;

class ProductA {
public:
	ProductA() {
	}
	~ProductA() {
	}

	virtual void operationA1() = 0;
	virtual void operationA2() = 0;
};

class ProductA1 : public ProductA {
public:
	ProductA1(string str) {
		cout << str << endl;
	}
	~ProductA1() {
	}

	void operationA1() {
		cout << "Operation A1" << endl;
	}

	void operationA2() {
		cout << "Operation A2" << endl;
	}
};

class ProductA2 : public ProductA {
public:
	ProductA2(string str) {
		cout << str << endl;
	}
	~ProductA2() {
	}

	void operationA1() {
		cout << "Operation A1" << endl;
	}

	void operationA2() {
		cout << "Operation A2" << endl;
	}
};

class ProductB {
public:
	ProductB() {
	}
	~ProductB() {
	}

	virtual void operationB1() = 0;
	virtual void operationB2() = 0;
};

class ProductB1 : public ProductB {
public:
	ProductB1(string str) {
		cout << str << endl;
	}
	~ProductB1() {
	}

	void operationB1() {
		cout << "Operation B1" << endl;
	}

	void operationB2() {
		cout << "Operation B2" << endl;
	}
};

class ProductB2 : public ProductB {
public:
	ProductB2(string str) {
		cout << str << endl;
	}
	~ProductB2() {
	}

	void operationB1() {
		cout << "Operation B1" << endl;
	}

	void operationB2() {
		cout << "Operation B2" << endl;
	}
};

class CreateFactory {
public:
	CreateFactory() {
	}
	~CreateFactory() {
	}

	virtual ProductA *createProductA() = 0;
	virtual ProductB *createProductB() = 0;
};

class CreateFactory1 : public CreateFactory {
public:
	CreateFactory1() {
	}
	~CreateFactory1() {
	}

	ProductA *createProductA() {
		ProductA *pA = new ProductA1("ProductA1");
		return pA;
	}

	ProductB *createProductB() {
		ProductB *pB = new ProductB1("ProductB1");
		return pB;
	}
};

class CreateFactory2 : public CreateFactory {
public:
	CreateFactory2() {
	}
	~CreateFactory2() {
	}

	ProductA *createProductA() {
		ProductA *pA = new ProductA2("ProductA2");
		return pA;
	}

	ProductB *createProductB() {
		ProductB *pB = new ProductB2("ProductB2");
		return pB;
	}
};

class FactoryMaker {
public:
	FactoryMaker() {
	}
	~FactoryMaker() {
	}

	CreateFactory *getFactory(string abc) {
		CreateFactory *pFactory = nullptr;
		if (abc == "a") {
			pFactory = new CreateFactory1();
		} else if (abc == "b") {
			pFactory = new CreateFactory2();
		}
		return pFactory;
	}
};

int main() {
	FactoryMaker pF;
	CreateFactory *pCF = pF.getFactory("b");
	ProductA *pA = pCF->createProductA();
}