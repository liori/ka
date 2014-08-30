#include <catch.hpp>
#include "appenddb.h"

TEST_CASE("AppendDB") {
	class Entry { };

	auto db = AppendDB<Entry>::create();
	auto const& const_db = db;

	SECTION("after creating is empty") {
		REQUIRE(const_db.get_messages_count() == 0);
	}

	SECTION("can store an entry") {
		auto const m = Entry();

		db.append(m);

		SECTION("and the message count increases afterwards") {
			REQUIRE(const_db.get_messages_count() == 1);
		}
	}
}

TEST_CASE("AppendDB with mocked index") {
	class Entry { };

	SECTION("derives from the given index class") {
		class MockedIndex { };
		auto answer = std::is_base_of<MockedIndex, AppendDB<Entry, MockedIndex>>::value;
		REQUIRE(answer);
	}

	SECTION("derives publicly from the given index class") {
		class MockedIndex {
		public:
			int mocked_property = 42;
		};
		auto db = AppendDB<Entry, MockedIndex>::create();
		REQUIRE(db.mocked_property == 42);
	}
}
