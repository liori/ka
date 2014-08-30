#include <catch.hpp>
#include "appenddb.h"

TEST_CASE("AppendDB Entry") {
	SECTION("can be created") {
		AppendDB<>::Entry::create();
	}
}

TEST_CASE("AppendDB") {
	auto db = AppendDB<>::create();
	auto const& const_db = db;

	SECTION("after creating is empty") {
		REQUIRE(const_db.get_messages_count() == 0);
	}

	SECTION("can store an entry") {
		auto const m = AppendDB<>::Entry::create();

		db.append(m);

		SECTION("and the message count increases afterwards") {
			REQUIRE(const_db.get_messages_count() == 1);
		}
	}
}
