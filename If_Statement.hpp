#pragma once
#include "SyntaxTree.hpp"
#include "Conditional_Statement.hpp"

namespace compiler
{
	class If_Statement : public Conditional_Statement
	{
	public:
		
		If_Statement(SyntaxTree* Condition, SyntaxTree* Statements)
		{
			condition.push_back(Condition);
			children.push_back(Statements);
		}

		virtual ~If_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "if(";
			
			for(SyntaxTree* node : condition)
			{
				if(node != nullptr)
				{
					if( node->toCode() == "Sylvanas_Rules_Forsaken" )
						code += "true";
					else if( node->toCode() == "Arthas_Rules_Forsaken" )
						code += "false";
					else
						code += node->toCode();
				}		
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