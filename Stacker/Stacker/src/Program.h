#ifndef STACKER_PROGRAM_H
#define STACKER_PROGRAM_H
#include "Instruction.hpp"
#include <stack>
#include <queue>

#include "Operations.hpp"
#include "Value.hpp"

#include <variant>
typedef std::variant<Operation, Value> Instruction;

class Program
{	
	std::queue<Instruction> program;
	std::stack<Value> stack;
public:
	explicit Program(std::queue<Instruction>&& src);
	void start();
private:
	void execute(const Instruction& instruction);
	Instruction get_next();
	
	void push(const Value& value);
	void pop();
	void swap();
	
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void pow();
	void log();

	void write();
	void write_line();

	void read();
	void read_line();
	
};
#endif // STACKER_PROGRAM_H
