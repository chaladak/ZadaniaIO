#include "pch.h"
#include "CppUnitTest.h"
#include "../rejestracja/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RejestracjaTesty
{
	TEST_CLASS(RejestracjaTesty)
	{
	public:
		
        TEST_METHOD(TestValidateID)
        {
            Assert::IsTrue(validateID("12345678901")); 
            Assert::IsFalse(validateID("123")); 
            Assert::IsFalse(validateID("abcdefghijk")); 
        }

        TEST_METHOD(TestValidatePassword)
        {
            Assert::IsTrue(validatePassword("securePwd1")); 
            Assert::IsFalse(validatePassword("short")); 
        }

        TEST_METHOD(TestValidateUsername)
        {
            Assert::IsTrue(validateUsername("user1234")); 
            Assert::IsFalse(validateUsername("user")); 
        }

        TEST_METHOD(TestValidateEmail)
        {
            Assert::IsTrue(validateEmail("user@example.com")); 
            Assert::IsFalse(validateEmail("invalid_email")); 
        }

        TEST_METHOD(TestValidateLength)
        {
            Assert::IsTrue(validateLength("abcdef", 10)); 
            Assert::IsFalse(validateLength("too_long_text", 5)); 
        }

        TEST_METHOD(TestInsertData)
        {
            vector<User> users;
            User existingUser("jan", "kowalski", "12345678901", "Street 123", "jan@example.com", "jan_kowalski", "password");
            users.push_back(existingUser);

            std::streambuf* oldCin = cin.rdbuf();
            istringstream userInput("jan\nkowalski\n12345678901\nStreet 123\njan@example.com\njan_kowalski\npassword\n");
            cin.rdbuf(userInput.rdbuf());

            User newUser = insertData();

            cin.rdbuf(oldCin);

            Assert::IsTrue(newUser.username == "jan_kowalski");
            Assert::IsTrue(newUser.id_number == "12345678901");
        }
	};
}

