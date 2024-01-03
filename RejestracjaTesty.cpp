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
	};
}

