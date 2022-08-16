template <class T>
class Node {
  public:
	 T data;
	 Node<T> *next;

	 Node(T e) {
		 data = e;
		 next = 0;
	}
};
