#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Function_Main : public SyntaxTree
	{
	public:
		
		Function_Main(SyntaxTree* Statements)
		{
			children.push_back(Statements);
		}

		virtual ~Function_Main()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "#define A_Long_Dead_Memory 0\n";
			code += "#include <math.h>\n";
			code += "#include <stdio.h>\n";
			code += "#include <stdlib.h>\n";
			code += "#include <iostream>\n\n";
			
			code += "int main(void){\n";

			for(SyntaxTree *node : children)
			{
				if(node != nullptr)
					code += node->toCode();
			}

			code += "std::cout << std::endl;\n";
			code += "system(\"PAUSE\");\n";
			code += "return 0;\n}";
			
			return code;
		}


	protected:

	private:

	};
}