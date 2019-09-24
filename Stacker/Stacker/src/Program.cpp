#include "Program.h"

Program::Program(std::queue<Instruction>&& src):
	program(src)                                          
{}

void Program::start()
{
	while (!program.empty())
	{
		execute(get_next());
	}
}

void Program::execute(const Instruction& instruction)
{
	if(std::holds_alternative<Operation>(instruction))
	{
		const Operation& op = std::get<Operation>(instruction);
		switch (op) {
			case Operation::INVALID: break;
			case Operation::PUSH:
				push(std::get<Value>(get_next()));
				break;
			case Operation::POP: pop(); break;
			case Operation::SWAP:swap(); break;
			case Operation::ADD: add(); break;
			case Operation::SUB: sub(); break;
			case Operation::MUL: mul(); break;
			case Operation::DIV: div(); break;
			case Operation::POW: pow(); break;
			case Operation::LOG: log(); break;
			case Operation::MOD: mod(); break;
			case Operation::WRITE: write();	break;
			case Operation::WRITE_LINE: write_line();  break;
			case Operation::READ: read(); break;
			case Operation::READ_LINE: read_line(); break;
			default: ;
		}
	}
}

Instruction Program::get_next()
{
	Instruction ins = std::move(program.front());
	program.pop();
	return ins;
}

void Program::push(const Value& value)
{
	stack.emplace(value);
}

void Program::pop()
{
	stack.pop();
}

void Program::swap()
{
	Value a = std::move(stack.top()); stack.pop();
	Value b = std::move(stack.top()); stack.pop();
	stack.emplace(b);
	stack.emplace(a);
	
}

void Program::add()
{
	Value top = std::move(stack.top()); stack.pop();
	
}

void Program::sub()
{
}

void Program::mul()
{
}

void Program::div()
{
}

void Program::mod()
{
}

void Program::pow()
{
}

void Program::log()
{
}

void Program::write()
{
}

void Program::write_line()
{
}

void Program::read()
{
}

void Program::read_line()
{
}
