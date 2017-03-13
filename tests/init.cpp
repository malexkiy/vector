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
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 0);
	REQUIRE(vector[2] == 0);
	REQUIRE(vector[3] == 0);
}

SCENARIO("vector init object", "[init object]") {
	vector_t b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	vector_t a(b);

	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(a[0] == b[0]);
	REQUIRE(a[1] == b[1]);
	REQUIRE(a[2] == b[2]);
}

SCENARIO("vector op=", "[op=]") {
	vector_t a(4), b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	a = b;

	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(a[0] == b[0]);
	REQUIRE(a[1] == b[1]);
	REQUIRE(a[2] == b[2]);
}

SCENARIO("vector push", "[push]") {
	vector_t vector(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);
	vector.push_back(4);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 0);
	REQUIRE(vector[2] == 0);
	REQUIRE(vector[3] == 4);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 4);
}
