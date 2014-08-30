template<typename Entry, typename ...T>
class AppendDB : T... {
	int message_count = 0;

public:
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
