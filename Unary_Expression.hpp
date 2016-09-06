#pragma once
#include "SyntaxTree.hpp"
#include <String>
#include <locale>

namespace compiler
{
	class Unary_Expression : public SyntaxTree
	{
	public:
		
		Unary_Expression(SyntaxTree* operation, SyntaxTree* expression)
		{
			children.push_back(operation);
			children.push_back(expression);
		}

		virtual ~Unary_Expression()
		{

		}

		virtual std::string toCode() const
		{
			std::string code;
			
			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)
				{	
						code += node->toCode(); 
						
				}
			}

			code += ")";
			return code;
		}


	protected:

	private:
	
	};
}