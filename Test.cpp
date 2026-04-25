//Name: Imad Farhat
//Homework 12: RPN calculator
#include <iostream>
#include "Operands.h"

double Calculate(std::queue<Operand*> a) {
	std::stack<double> b;
	//creates stack to hold values

	while (a.size() > 0) {
		Operand* temp = a.front();
		a.pop();
		//temporary variable to get the front of the queue, pops queue to go to the next value

		if (dynamic_cast<Number*>(temp)) {
			b.push(dynamic_cast<Number*>(temp)->getValue());
			//adds the values if they are numbers to the stack
		}
		else if (dynamic_cast<Add*>(temp)) {
			if (b.size() < 2) {
				throw std::exception("Insufficent amount of values entered. ");
				//throws error if the wrong amount of values are entered
			}
			else {
				double temp1 = b.top();
				b.pop();
				double temp2 = b.top();
				b.pop();
				b.push(temp1 + temp2);
				//pops first two numbers, assigns them to temporary vars, pushes them, adds them to b
			}
		}
		else if (dynamic_cast<Subtract*>(temp)) {

			if (b.size() < 2) {
				throw std::exception("Insufficent amount of values entered. ");
				//throws error if the wrong amount of values are entered
			}
			else {
				double temp1 = b.top();
				b.pop();
				double temp2 = b.top();
				b.pop();
				b.push(temp2 - temp1);
				//pops first two numbers, assigns them to temporary vars, subtracts them, pushes to b
			}

		}
		else if (dynamic_cast<Mulitply*>(temp)) {
			if (b.size() < 2) {
				throw std::exception("Insufficent amount of values entered. ");
				//throws error if the wrong amount of values are entered
			}
			else {
				double temp1 = b.top();
				b.pop();
				double temp2 = b.top();
				b.pop();
				b.push(temp1 * temp2);
				//pops first two numbers, assigns them to temporary vars, multiplies them, pushes to b
			}
		}
		else if (dynamic_cast<Divide*>(temp)) {
			if (b.size() < 2) {
				throw std::exception("Insufficent amount of values entered. ");
				//throws error if the wrong amount of values are entered
			}
			else {
				double temp1 = b.top();
				b.pop();
				double temp2 = b.top();
				b.pop();
				//pops first two numbers, assigns them to temporary vars
				if (temp1 == 0) {
					throw std::runtime_error("Cannot Divide by Zero!");
					//throws error if division by zero
				}
				else {
					b.push(temp2 / temp1);
					//pushes quotient 
				}
			}

		}
		else if (dynamic_cast<Square*>(temp)) {
			if (b.size() < 1) {
				throw std::exception("Insufficent amount of values entered. ");
				//throws error if more than one or less than one value is entered
			}
			else {
				double temp1 = b.top();
				b.pop();
				
				b.push(pow(temp1, 2));
				//pops value, assigns it to temporary var, squares it, pushes
			}
		}
	}
	return b.top();
	//returns the most recent value, the result
}
int main() {
	std::queue<Operand*> a;
	a.push(new Number(9));
	a.push(new Number(2));
	a.push(new Add());
	std::cout << "Addition: "  << Calculate(a) << std::endl;
	//prints 11 through adding

	std::queue<Operand*> b;
	b.push(new Number(14));
	b.push(new Number(3));
	b.push(new Subtract());
	std::cout << "Subtraction: " << Calculate(b) << std::endl;
	//prints 11 through subtraction

	std::queue<Operand*> c;
	c.push(new Number(11));
	c.push(new Number(1));
	c.push(new Mulitply());
	std::cout << "Product: " << Calculate(c) << std::endl;
	//prints 11 through product

	std::queue<Operand*> d;
	d.push(new Number(33));
	d.push(new Number(3));
	d.push(new Divide());
	std::cout << "Quotient: " << Calculate(d) << std::endl;
	//prints 11 through quotient

	std::queue<Operand*> e;
	e.push(new Number(11));
	e.push(new Square());
	std::cout << "Square: " << Calculate(e) << std::endl;
	//tests square

	std::queue<Operand*> f;
	f.push(new Number(6));
	f.push(new Number(8));
	f.push(new Add());
	f.push(new Square());
	f.push(new Number(102));
	f.push(new Number(53));
	f.push(new Subtract());
	f.push(new Divide());
	f.push(new Number(428));
	f.push(new Number(379));
	f.push(new Subtract());
	f.push(new Number(7));
	f.push(new Divide());
	f.push(new Add());
	std::cout << "Video example: " << Calculate(f) << std::endl;
	//uses the video as a test example


}