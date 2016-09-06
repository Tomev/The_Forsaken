#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Semicolon_Expression : public SyntaxTree
	{
	public:
		
		Semicolon_Expression(SyntaxTree* expression)
		{
			children.push_back(expression);
		}

		virtual ~Semicolon_Expression()
		{

		}

		virtual std::string toCode() const
		{
			std::string code =  "";
			
			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)
				{
					code += node->toCode();
				}
			}

			code += ";\n";
			return code;
		}


	protected:

	private:
	
	};
}