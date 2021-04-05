#include "SeqList.h"

void TestSeqList()
{
	SeqList s;

	s.PushBack(&s, 1);
	s.PushBack(&s, 2);
	s.PushBack(&s, 3);
	s.Print(&s);

	s.PushFront(&s, -1);
	s.PushFront(&s, -2);
	s.PushFront(&s, -3);
	s.Print(&s);

	int index = s.Find(&s, 2);
	s.Insert(&s, index, 666);
	s.Print(&s);

	s.Erase(&s, index);
	s.Print(&s);

}

int main()
{
	TestSeqList();
	return 0;
}



