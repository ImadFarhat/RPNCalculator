#include "Operands.h"

Operand::~Operand()
{
	//empty
}

Number::Number(double num)
	:Num(num)
	//initalizes public double member variable
{
	//empty
}

double Number::getValue()
{
	return Num; 
	//returns public double member var
}
