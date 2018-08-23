#include <iostream>
#include <cassert>
#include <boost/optional/optional.hpp>
#include <algorithm>

enum class ETest{
	FIRST,
	SECOND,
	THIRD
};

typedef enum{
	eLegacyEnum_one,
	eLegacyEnum_two,
	eLegacyEnum_three
} ELegacyEnum;

static std::string Label (const ETest test){
	switch (test){
		case ETest::FIRST: return "First";
		case ETest::SECOND: return "Second";
		case ETest::THIRD: return "Third";
	}
	assert (false);
}

static std::string LegacyLabel (const ELegacyEnum test){
	switch (test){
		case eLegacyEnum_one: return "one";
		case eLegacyEnum_two: return "two";
		case eLegacyEnum_three: return "three";
	}
	assert (false);
}

static void Test1 (void){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << Label(ETest::FIRST) << std::endl;
	std::cout << Label(ETest::SECOND) << std::endl;
	std::cout << Label(ETest::THIRD) << std::endl;
}

static void Test2 (void){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	boost::optional <ETest> test;
	
	test = ETest::FIRST;
	assert (ETest::FIRST == test);
	assert (ETest::SECOND != test);
	assert (ETest::FIRST == *test);
	assert (ETest::SECOND != *test);
	
	*test = ETest::SECOND;
	assert (*test == test);
	assert (test == *test);
	assert (sizeof (*test) != sizeof (test));
	
	assert (ETest::SECOND == test);
	assert (ETest::FIRST != test);
	assert (ETest::SECOND == *test);
	assert (ETest::FIRST != *test);
	
	test = ETest::FIRST;
	assert (ETest::FIRST == test);
	assert (ETest::SECOND != test);
	assert (ETest::FIRST == *test);
	assert (ETest::SECOND != *test);
	
	if (!test){
		std::cout << "uninitialized" << std::endl;
	}
	else{
		std::cout << Label (*test) << std::endl;
	}
}

static void Test3 (void){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	const ETest kVector [] = {
		ETest::FIRST,
		ETest::SECOND,
		ETest::SECOND,
		ETest::FIRST,
		ETest::FIRST,
		ETest::FIRST,
		ETest::THIRD
	};
	
	boost::optional<ETest> currentElement;
	std::cout << sizeof (ETest) << std::endl;
	std::cout << sizeof (currentElement) << std::endl;
	std::for_each  (kVector, kVector + sizeof (kVector)/sizeof(*kVector), [&currentElement](const ETest element) -> void {
		if (currentElement != element){
			currentElement = element;
			std::cout << Label (*currentElement) << std::endl;
		}
	});
}

static void Test4 (void){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	const ELegacyEnum kVector [] = {
		eLegacyEnum_one,
		eLegacyEnum_two,
		eLegacyEnum_two,
		eLegacyEnum_one,
		eLegacyEnum_one,
		eLegacyEnum_one,
		eLegacyEnum_three
	};
	
	boost::optional<ELegacyEnum> currentElement;
	std::cout << sizeof (ELegacyEnum) << std::endl;
	std::cout << sizeof (currentElement) << std::endl;
	std::for_each  (kVector, kVector + sizeof (kVector)/sizeof(*kVector), [&currentElement](const ELegacyEnum element) -> void {
		if (currentElement != element){
			currentElement = element;
			std::cout << LegacyLabel (*currentElement) << std::endl;
		}
	});
}

static void Test5 (void){
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	boost::optional<ETest> test;
	assert (!test);
	assert (test != ETest::FIRST);
	assert (!test);
	test = ETest::FIRST;
	assert (test);
}

int main (void){
	try{
		Test1 ();
		Test2 ();
		Test3 ();
		Test4 ();
		Test5 ();
	}
	catch (const std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	catch (...){
		std::cout << "unknown exception" << std::endl;
	}
	return 0;
}
