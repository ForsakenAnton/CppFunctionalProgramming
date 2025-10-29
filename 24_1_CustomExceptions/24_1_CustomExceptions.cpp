#include <iostream>

class UserErrorLogic abstract : public std::logic_error
{
public:
	explicit UserErrorLogic(const std::string& message) : std::logic_error{ message }
	{
	}
};

class UserInvalidLoginException final : public UserErrorLogic
{
public:
	UserInvalidLoginException() : UserErrorLogic{ "Login is invalid" }
	{
	}
};

class UserShortPasswordException final : public UserErrorLogic
{
public:
	UserShortPasswordException() : UserErrorLogic{ "Password must have at least 8 characters" }
	{
	}
};

class UserAgeTooLessException final : public UserErrorLogic
{
public:
	UserAgeTooLessException() : UserErrorLogic{ "Age must be at least 18" }
	{
	}
};

class UserAgeTooMuchException final : public UserErrorLogic
{
public:
	UserAgeTooMuchException() : UserErrorLogic{ "Age must be at less than 65" }
	{
	}
};

struct User
{
    std::string login;
    std::string password;
    int age;
};

bool signIn(const User& user)
{
	if (user.login.find("@") == std::string::npos)
	{
		//throw std::invalid_argument("Login is invalid");
		throw UserInvalidLoginException{ };
	}

	if (user.password.length() < 8)
	{
		//throw std::length_error("Password must have at least 8 characters");
		throw UserShortPasswordException{ };
	}

	if (user.age < 18)
	{
		//throw std::invalid_argument("Age must be at least 18");
		throw UserAgeTooLessException{ } ;
	}

	if (user.age >= 65)
	{
		//throw std::invalid_argument("Age must be at least 18");
		throw UserAgeTooMuchException{ };
	}
}

int main()
{
	try
	{
		User user{ "John Doe", "12345678", 18 };

		bool isSignin = signIn(user);

		std::cout << "Signed!\n";
	}
	catch (const UserErrorLogic& ex)
	{
		std::cout << "logic_error: " << ex.what() << "\n";
	}
	catch (const std::logic_error& ex)
	{
		std::cout << "logic_error: " << ex.what() << "\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << "\n";
	}
}
