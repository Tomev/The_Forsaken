#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Binary_Expression : public SyntaxTree
	{
	public:
		
		Binary_Expression(SyntaxTree* left, SyntaxTree* symbol, SyntaxTree* right)
		{
			children.push_back(left);
			children.push_back(symbol);
			children.push_back(right);
		}

		virtual ~Binary_Expression()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";
			
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