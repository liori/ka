template<typename Entry, typename ...T>
class AppendDB : public T... {
public:
	static AppendDB create() {
		return AppendDB();
	}

	void append(Entry const e) {
		[](...){}((T::update(e), 0)...);
	}
};

class TotalCount {
	int count = 0;
public:
	int get_total_messages_count() const {
		return this->count;
	}

	void update(...) {
		this->count++;
	}
};
