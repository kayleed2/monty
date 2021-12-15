#include "monty.h"
/**
 * get_op_func - Calls correct operation function
 * @s: Operator passed as argument
 * Return: Pointer to correct op function
 */

int (*get_op_func(char *s))(stack_t stack, unsigned int line_num)
{
	instruction_t opcode[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL && *(ops[i].op) != *s)
	{
		i++;
	}
	return (ops[i].f);
}
