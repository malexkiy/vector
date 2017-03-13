#include <vector.hpp>
#include <catch.hpp>

SCENARIO("vector init", "[init]") {
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}

SCENARIO("vector init param", "[init param]") {
	vector_t vector(4);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 4);
	for(unsigned int i = 0; i < vector.size(); i++)
		vector[i] == 0;
}

SCENARIO("vector init object", "[init object]") {
	vector_t b;
	REQUIRE(b.size() == 0);
	REQUIRE(b.capacity() == 0);

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	REQUIRE(b.size() == 3);
	REQUIRE(b.capacity() == 4);

	vector_t a(b);

	REQUIRE(a.size() == 3);
	REQUIRE(a.capacity() == 4);
	for(unsigned int i = 0; i < a.size(); i++)
		a[i] == b[i];
}

SCENARIO("vector op=", "[op=]") {
	vector_t a(4), b;
	REQUIRE(b.size() == 0);
	REQUIRE(b.capacity() == 0);

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	REQUIRE(b.size() == 3);
	REQUIRE(b.capacity() == 4);

	a = b;

	REQUIRE(a.size() == 3);
	REQUIRE(a.capacity() == 4);
	for(unsigned int i = 0; i < a.size(); i++)
		a[i] == b[i];
}

SCENARIO("vector push", "[push]") {
	vector_t vector(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);
	vector.push_back(4);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 0);
	REQUIRE(vector[2] == 0);
	REQUIRE(vector[3] == 4);
}
