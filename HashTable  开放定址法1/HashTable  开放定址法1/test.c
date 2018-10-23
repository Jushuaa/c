#include"HashTable.h"

//void TestHashTable()
//{
//	HashData* ret;
//	HashTable ht;
//	size_t i;
//	HTInit(&ht, 10);
//	//HTInsert(&ht, 7, 0);
//	HTInsert(&ht, 17, 0);
//	//HTInsert(&ht, 27, 0);
//	//HTInsert(&ht, 8, 0);
//	HTPrint(&ht);
//	
//	HTRemove(&ht, 17);
//	ret = HTFind(&ht, 27);
//	ret->_value = 10;
//	HTPrint(&ht);
//
//	for (i = 0; i < 10; ++i)
//	{
//		HTInsert(&ht, rand(), i);
//	}
//	HTPrint(&ht);
//}
void TestHashTable()
{
	//int i = 0;
	//HashData* ret;
	//char* strs[] = {"insert","insert","insert","insert","insert","sort", "insert", "sort", "find"};
	////char* strs[] = {"abcd", "bcad", "cbad","cbad", "aad", "abc", "acb"};
	////char* strs[] = {"工具", "工具", "工具", "调试"};
	//HashTable ht;
	//HTInit(&ht, 10);
	//for (; i < sizeof(strs)/sizeof(char*); ++i)
	//{
	//	ret = HTFind(&ht, strs[i]);
	//	if (ret)
	//	{
	//		ret->_value++;
	//	}
	//	else
	//	{
	//		HTInsert(&ht, strs[i], 1);
	//	}
	//}

	//HTPrint(&ht);

	char str[] = "工具";
	char str_[6];
	str_[0] = -55;
	str_[1] = -74;
	str_[2] = ' ';
	str_[3] = -79;
	str_[4] = -56;
	str_[5] = '\0';

		printf("%s\n", str);
	printf("%s\n", str_);
}
int main()
{
	TestHashTable();
	system("pause");
	return 0;
}