class AppendDB {
public:
	class Entry {
	public:
		static Entry create();
	};

	static AppendDB create();

	int get_messages_count() const;
};
