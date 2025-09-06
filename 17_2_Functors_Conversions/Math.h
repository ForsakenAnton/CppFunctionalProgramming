#pragma once

static class Math
{
	public:
		//static int add(float a, float b) = delete;
		//static int add(bool a, bool b) = delete;
		//static int add(char a, char b) = delete;

		template<typename T1, typename T2>
		static T1 add(T1 a, T2 b) = delete;

		static int add(int a, int b)
		{ 
			return a + b;
		}

		static int subtract(int a, int b)
		{ 
			return a - b; 
		}

		static int multiply(int a, int b)
		{
			return a * b;
		}

		static double divide(int a, int b) 
		{
			if (b == 0)
			{
				return 0;
			}

			return (double) a / b;
		}
};