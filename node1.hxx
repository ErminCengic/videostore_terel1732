template <typename Type> 
class nodeType 
{ 
	private: 
		Type info; 
		nodeType* next; 
	public: 
		Type getInfo() {return info;} 
		nodeType* getNext() {return next;} 
		void setInfo(const Type& i) {info=i;} 
		void setNext(nodeType* n) {next = n;} 
};
