#include "appenddb.h"

AppendDB::Entry AppendDB::Entry::create() {
	return AppendDB::Entry();
}

AppendDB AppendDB::create() {
	return AppendDB();
}

int AppendDB::get_messages_count() const {
	return 0;
}

void AppendDB::append(Entry const e) { }
