#pragma once
#include <cstring>
#include "SyntaxTree.hpp"
#include "Conditional_Statement.hpp"
#include "Name.hpp"

namespace compiler
{
	class Initialization_Statement : public Conditional_Statement
	{
	public:
		
		Initialization_Statement(SyntaxTree* Variable, SyntaxTree* Expression)
		{
			condition.push_back(Variable);
			children.push_back(Expression);
		}

		virtual ~Initialization_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";
			
			std::string expression = "";

			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)
				{
					expression += node->toCode();
				}
			}
			
			int i = 0;
			
			while(expression[i])
			{
				char iChar = expression[i];
				
				if(iChar == '.')
				{
					code += "float ";
					break;
				}
				else if(((iChar == '=') && (expression[i+1] == '=')) || iChar == '!')
				{	
					code += "bool ";
					break;
				}
				
				i++;
			}
			
			if(code[0] == 'f' || code[0] == 'b')
				;
			else
				code += "int ";
			
			
			for(SyntaxTree *node : condition)
			{				
				if(node != nullptr)
				{
					code += node->toCode();
				}
			}
			
			code += " = " + expression;
			
			return code;
		}


	protected:

	private:

	};
}