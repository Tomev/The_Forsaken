#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Input : public SyntaxTree
	{
	public:
		
		Input(SyntaxTree* Function_Main, SyntaxTree* Functions_List)
		{
			children.push_back(Function_Main);
			children.push_back(Functions_List);
		}

		virtual ~Input()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";

			for(SyntaxTree *node : children)
			{
				if(node != nullptr)	
					code += node->toCode();
			}
			return code;
		}


	protected:

	private:

	};
}