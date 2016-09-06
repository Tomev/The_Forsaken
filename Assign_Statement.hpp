#pragma once
#include "SyntaxTree.hpp"
#include "Conditional_Statement.hpp"

namespace compiler
{
	class Assign_Statement : public Conditional_Statement
	{
	public:
		
		Assign_Statement(SyntaxTree* Variable, SyntaxTree* Expression)
		{
			condition.push_back(Variable);
			children.push_back(Expression);
		}

		virtual ~Assign_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";

			for(SyntaxTree *node : condition)
			{				
				if(node != nullptr)
				{
					code += node->toCode();
				}
			}
			
			code += "=";
			
			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)
				{
					code += node->toCode();
				}
			}

			return code;
		}


	protected:

	private:

	};
}