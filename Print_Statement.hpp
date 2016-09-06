#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Print_Statement : public SyntaxTree
	{
	public:
		
		Print_Statement(SyntaxTree* Expression)
		{
			children.push_back(Expression);
		}

		virtual ~Print_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "std::cout << ";

			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)	
					code += node->toCode();
			}
			
			if(code[code.length()-1] == ' ')
				code += "std::endl";

			return code;
		}


	protected:

	private:

	};
}