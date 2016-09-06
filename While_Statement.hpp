#pragma once
#include "SyntaxTree.hpp"
#include "Conditional_Statement.hpp"

namespace compiler
{
	class While_Statement : public Conditional_Statement
	{
	public:
		
		While_Statement(SyntaxTree* Condition, SyntaxTree* Statements)
		{
			condition.push_back(Condition);
			children.push_back(Statements);
		}

		virtual ~While_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "while(";
			
			for(SyntaxTree* node : condition)
			{
				if(node != nullptr)	
					code += node->toCode();			
			}
			
			code += ")\n{\n";

			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)	
					code += node->toCode();
			}

			code += "}\n";
			return code;
		}


	protected:

	private:

	};
}