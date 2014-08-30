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

	SECTION("calls Index to store entries") {
		class MockedIndex {
		public:
			int value_passed = 0;
			void update(int const e) {
				this->value_passed = e;
			}
		};
		auto db = AppendDB<int, MockedIndex>::create();

		db.append(42);
		REQUIRE(db.value_passed == 42);
	}
}

TEST_CASE("TotalCount") {
	auto tc = TotalCount();
	auto const& const_tc = tc;

	SECTION("is zero on startup") {
		REQUIRE(const_tc.get_total_messages_count() == 0);
	}
}
