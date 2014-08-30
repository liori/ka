#include <catch.hpp>
#include "appenddb.h"

TEST_CASE("AppendDB Entry") {
	SECTION("can be created") {
		auto m = AppendDB::Entry::create();
	}
}

TEST_CASE("AppendDB") {
	auto db = AppendDB::create();
	auto const& const_db = db;

	SECTION("after creating is empty") {
		REQUIRE(const_db.get_messages_count() == 0);
	}
}
