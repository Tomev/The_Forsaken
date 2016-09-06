#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Parenthesis_Expression : public SyntaxTree
	{
	public:
		
		Parenthesis_Expression(SyntaxTree* expression)
		{
			children.push_back(expression);
		}

		virtual ~Parenthesis_Expression()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "( ";
			
			for(SyntaxTree *node : children)
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

			code += " )";
			return code;
		}


	protected:

	private:
	
	};
}