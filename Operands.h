#include <iostream>
#include <stack>
#include <queue>
#include <deque>
//preprocessor directives

class Operand {
public: 
	virtual ~Operand();
	//virtual destructor
};

class Number: public Operand {
public:
	Number(double num);
	//constructor 
	double Num;
	double getValue();
	//public double and function to get value

};

class Operator : public Operand {
	//empty
};

class Add : public Operator {
	//empty
};

class Subtract : public Operator {
	//empty
};

class Mulitply : public Operator {
	//empty
};

class Divide : public Operator {
	//empty
};
class Square : public Operator {
	//empty
};
