typedef std::string ListElemType;
class List
{
public:
	List();
	bool Insert(const ListElemType &e, const int &x);
	bool First(ListElemType &e, int &y);
	bool Next(ListElemType &e, int &y);
	void distWords();
	void frequentWord();
	void countWord(ListElemType e);
	void starting(ListElemType e);
	void containing(ListElemType e);
	void search(ListElemType e);
private:
	struct Node;
	typedef Node* Link;
	struct Node {
		ListElemType elem;
		int Line;
		int Count;
		std::vector<int>Position;
		Link next;
	};
	Link head;
	Link tail;
	Link current;
};

