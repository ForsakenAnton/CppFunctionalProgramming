
#include <iostream>
#include <functional>
#include <string>
#include <iomanip>

void hello1()
{

}

auto hello2() -> void
{

}

static std::string concatMethod(double left, double right)
{
	return std::to_string(left) + " - " + std::to_string(right);
}

class StringHelper
{
public:

	std::string concat(double left, double right)
	{
		return std::to_string(left) + " - " + std::to_string(right);
	}

	std::string operator()(double left, double right)
	{
		return this->concat(left, right);
	}
};

int main()
{
	//void* voidAutoPtr = &variable;
	//std::auto_ptr<void> autoPtr;
	//autoPtr = &variable;

	// pointers
	{
		int variable = 42;

		std::shared_ptr<int> shared1{ std::make_shared<int>(variable) };

		variable = 34;

		std::cout << shared1 << "\n";
		std::cout << shared1.get() << "\n";
		std::cout << *shared1 << "\n"; // 42
		std::cout << shared1.use_count() << "\n\n";

		auto shared2{ shared1 };
		std::cout << shared2 << "\n";
		std::cout << shared2.get() << "\n";
		std::cout << *shared2 << "\n"; // 42
		std::cout << shared2.use_count() << "\n\n";

		shared1.reset(new int{ 34 });
		shared1.reset();

		shared1 = shared2;


		std::unique_ptr<int> unique1{ std::make_unique<int>(123) };

		//std::unique_ptr<int> unique2{ unique1 };
		std::unique_ptr<int> unique2{ std::move(unique1) }; // now unique1 is null.

		//*unique1 = 456; // Runtime Error
		*unique2 = 456; // OK

		unique2.release();

		auto deleter = unique2.get_deleter();
		deleter(unique2.get());


		shared1.reset(unique2.get());

		std::cout << "\n=======================================\n";
	}


	// lambdas
	{
		[/* this is lambda expression*/](/* params */) {/* body */};

		auto helloLambda = [](int param1, std::string param2 = "hi") -> void
			{
				std::cout << "lambda works!\n";
				std::cout << "Param1: " << param1 << ", param2: " << param2 << "\n";
			};

		helloLambda(123, "hello");
		helloLambda(123);


		std::string sharedDescription = "Outer parameters example";

		auto plusLambda
		{
			[&, sharedDescription](auto a, auto b) mutable
			{
				std::cout << sharedDescription << "\n";
				sharedDescription = "My description";

				std::cout << typeid(a).name() << " - " << typeid(b).name() << "\n";
				std::cout << a + b << "\n";
			}
		};


		plusLambda(3, 4.4);
		plusLambda(3, "4.4");


		const int size = 5;
		int arr[size] = { 1, 3, 5, 7, 9 };

		auto res = std::find_if(
			std::begin(arr),
			std::end(arr),
			[](int el) 
			{
				return el > 3; 
			});

		std::cout << *res << "\n";

		auto res2 = std::find_if(
			std::begin(arr),
			std::end(arr),
			[](int el) 
			{ 
				return el > 10; 
			});

		std::cout << *res2 << "\n===============\n";
	}


	// functional
	{
		StringHelper sh;

		std::function<std::string(double, double)> concatFunc;

		//concatFunc = sh.concat;
		//std::cout << concatFunc(3, 4.4) << "\n";

		concatFunc = sh;
		std::cout << concatFunc(3, 4.4) << "\n";

		concatFunc = concatMethod;
		std::cout << concatFunc(3, 4.4) << "\n";

		concatFunc = [](double l, double r) -> std::string
		{
			return std::to_string(l) + " - " + std::to_string(r);
		};

		std::cout << concatFunc(3, 4.4) << "\n";
	}
}
