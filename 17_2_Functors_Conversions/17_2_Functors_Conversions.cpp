#include "Blog.h"
#include "Math.h"
#include "IsEven.h"
#include "Functions.h"
#include "IsCondition.h"
#include "UniqueSequence.h"
#include "SequenceService.h"

#include <iostream>


int main()
{
	// default and deleted functions
	{
		//Blog blog1; // error: use of deleted function 'Blog::Blog()'
		Blog blog2{ "Blog about cats", "Anton" };

		Blog blog3 = blog2; // default copy constructor

		//blog3 = blog2; // default assignment operator (=) is deleted


		std::cout << Math::add(5, 3) << std::endl;
		//std::cout << Math::add(5.5, 3.3) << std::endl;
		//std::cout << Math::add(5.5F, 3.3F) << std::endl;
		//std::cout << Math::add(true, false) << std::endl;
		//std::cout << Math::add('a', 'b') << std::endl;
	}


	// operator()
	{
		// Bad example of a functors
		Blog blog{ "Blog about dogs", "John" };

		blog();
		blog("Some Info");
		Blog copyBlog = blog(123);
		copyBlog();
		// ////////////////////////////////////////


		// Good example of a functors
		int number = 123;
		IsEven isEvenF;
		std::cout << std::boolalpha << isEvenF(number) << std::endl; // functor
		std::cout << std::boolalpha << isEven(number) << std::endl; // function


		IsCondition isConditionF;
		std::cout << std::boolalpha << isConditionF(IS_EVEN, 123) << std::endl;
		std::cout << std::boolalpha << isConditionF(IS_ODD, 123) << std::endl;
		std::cout << std::boolalpha << isConditionF(IS_SIMPLE, 123) << std::endl;
		// /////////////////////////////////////////

		int someArr1[] = { 3, 4, 5, 6, 7, 1, 2, 5, 3, 4 };
		int someArr2[] = { 3, 4, 5, 6, 7, 1, 2, 5, 5, 3, 4 };

		UniqueSequence uniqueF;
		for (int value : someArr1)
		{
			if (uniqueF(value))
			{
				std::cout << value << " ";
			}
		}
		uniqueF.reset();

		std::cout << std::endl;

		for (int value : someArr2)
		{
			if (uniqueF(value))
			{
				std::cout << value << " ";
			}
		}
		uniqueF.reset();

		std::cout << std::endl;


		std::cout << SequenceService::isUniqueSequence(someArr1, uniqueF) << std::endl;
		uniqueF.reset();
		std::cout << SequenceService::isUniqueSequence(someArr2, uniqueF) << std::endl;
		uniqueF.reset();

		// standard functors
		std::plus<int> addF;
		std::cout << addF(5, 3) << std::endl;

		std::minus<int> subtractF;
		std::cout << subtractF(5, 3) << std::endl;

		// tl dr...
	}



	// conversion operator
	{
		struct Point3D
		{
			int x;
			int y;
			int z;
		};

		struct Point2D
		{
			int x;
			int y;

			explicit operator Point3D() const
			{
				return Point3D{ x, y, 0 };
			}

			explicit operator int() const
			{
				return x + y;
			}
		};

		Point2D p2d{ 1, 2 };
		Point3D p3d{ 4, 5, 3 };

		p3d = (Point3D)p2d;
		int sum = (int)p2d;
	}
}
