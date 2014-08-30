template<typename ...T>
class AppendDB {
	int message_count = 0;

public:
	class Entry {
	public:
		static Entry create() {
			return AppendDB::Entry();
		}
	};

	static AppendDB create() {
		return AppendDB();
	}

	int get_messages_count() const {
		return this->message_count;
	}

	void append(Entry const e) {
		this->message_count++;
	}
};
