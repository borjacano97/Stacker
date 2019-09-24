#ifndef STACKER_INSTRUCTIONS_H
#define STACKER_INSTRUCTIONS_H
#include <unordered_map>
/*
 * PUSH:
 *	- example: PUSH 1; PUSH 2.3; PUSH "Hola"
 *	POP:
 *	- example: POP, POP 2, POP 3
 * SWAP:
 * - example;
 *		PUSH A
 *		PUSH B
 *		SWAP
 *		WRITE
 *		out: B
 *		WRITE
 *		out: A
 * 
 *
 *	ADD:
 *	- example:
 *		PUSH A
 *		PUSH B
 *		ADD //Note: (A+B)
 *	
 *	-SUB:
 *	- example:
 *		PUSH A
 *		PUSH B
 *		SUB //Note: (A-B)
 * MUL:
 * - example:
 *		MUL => TOP = TOP-1 * TOP;
 *
 * DIV: DIV => TOP = TOP-1/TOP;
 *
 * POW: POW => TOP = TOP-1^TOP;
 *
 * LOG: LOG => TOP = logTOP(TOP-1)
 *
 * MOD: MOD => TOP = TOP-1%TOP
 *
 * WRITE: prints into the console the top element
 * WRITE_LINE: prints into the console the top elements and inserts a new line
 *
 * READ: gets last char given
 * READ_LINE: gets last line given
 * 
 */


enum class Operation
{
	INVALID,

	PUSH,
	POP,
	SWAP,
	
	ADD,
	SUB,
	MUL,
	DIV,

	POW,
	LOG,
	MOD,

	WRITE,
	WRITE_LINE,

	READ,
	READ_LINE
};


static const std::unordered_map<const char*, Operation> TOKENS
{
	{"NULL",		Operation::INVALID},
	{"PUSH",		Operation::PUSH},
	{"POP",			Operation::POP},
	{"SWAP",		Operation::SWAP},
	{"ADD",			Operation::ADD},
	{"SUB",			Operation::SUB},
	{"MUL",			Operation::MUL},
	{"DIV",			Operation::DIV},
	{"POW",			Operation::POW},
	{"LOG",			Operation::LOG},
	{"MOD",			Operation::MOD},
	{"WRITE",		Operation::WRITE},
	{"WRITE_LINE",	Operation::WRITE_LINE},
	{"READ",		Operation::READ},
	{"READ_LINE",	Operation::READ_LINE}
};
#endif