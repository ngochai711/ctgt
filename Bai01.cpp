#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct Node
{
	int Data;
	struct Node* pNext;
};
typedef struct Node NODE;
struct List
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->Data = x;
	p->pNext = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Input(LIST& l)
{
	int n;
	cout << "So Node ban muon nhap: ";
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "\nNhap vao data: ";
		cin >> x;
		NODE* p = GetNode(x);
		AddTail(l, p);
	}
}
int Search(LIST l, int x)
{
	NODE* p;
	p = l.pHead;
	while (p != NULL && p->Data != x)
	{
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	return 1;
}
int RemoveHead(List& l, int& x)
{
	Node* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		x = p->Data; //lưu Data của nút cần hủy
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int RemoveHead1(List& l)
{
	Node* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int RemoveAfterQ(List& l, Node* q, int& x)
{
	Node* p;
	if (q != NULL)
	{
		p = q->pNext; //p là nút cần xoá
		if (p != NULL) // q không phài là nút cuối
		{
			if (p == l.pTail) //nút cần xoá là nút cuối cùng 
				l.pTail = q;// cập nhật lạ pTail
			q->pNext = p->pNext; x = p->Data;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
int RemoveX(List& l, int x)
{
	Node* p, * q = NULL; p = l.pHead;
	while ((p != NULL) && (p->Data != x)) //tìm
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL) //không tìm thấy phần tử có khoá bằng x
		return 0;
	if (q != NULL)//tìm thấy phần tử có khoá bằng x
		RemoveAfterQ(l, q, x);
	else //phần tử cần xoá nằm đầu List
		RemoveHead(l, x);
	return 1;
}
void InsertAfterP(LIST& l, NODE* m)
{
	Node* p;
	p = l.pHead;
	if (p != NULL)
	{
		m->pNext = p->pNext;
		p->pNext = m;
		if (l.pTail == p)
			l.pTail = m;
	}
	else
	{
		AddHead(l, m);
	}
}
/* sắp xếp trong danh sách liên kết đơn theo thứ tự tăng dần */
void Sortlist(LIST& l)
{
	// for loop thứ nhất
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		//for loop thứ hai
		for (Node* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->Data > q->Data) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				int tmp = p->Data;
				p->Data = q->Data;
				q->Data = tmp;
			}
		}
	}
}

void Output(LIST l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data << ' ';
	}
}

int main()
{
	LIST l;
	Input(l);
	Output(l);
	int x;
	cout << "\nPhan tu can tim co gia tri la: ";
	cin >> x;
	if (Search(l, x) == 1)
		cout << "\nCo phan tu can tim";
	else
		cout << "\nKhong co phan tu can tim";
	RemoveHead1(l);
	cout << endl;
	Output(l);
	cout << "\nNhap gia tri phan tu can xoa: ";
	cin >> x;
	RemoveX(l, x);
	cout << endl;
	Output(l);
	cout << "\nNhap data cho node can chen: ";
	cin >> x;
	Node* m=GetNode(x);
	InsertAfterP(l, m);
	cout << "\nSap xep tang dan: ";
	Sortlist(l);
	cout << endl;
	Output(l);
	return 0;
}