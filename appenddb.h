class AppendDB {
	int message_count = 0;

public:
	class Entry {
	public:
		static Entry create();
	};

	static AppendDB create();

	int get_messages_count() const;

	void append(Entry const e);
};
