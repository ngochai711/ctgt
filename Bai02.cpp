#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef struct 
{
	char Name[40];
	char MSSV[20];
	float dtb;
}SV;
struct Node
{
	SV Data;
	struct Node* pNext;
};
typedef struct Node NODE;
typedef struct
{
	NODE* pHead;
	NODE* pTail;
}DSSV;
void CrList(DSSV& l)
{
	l.pHead = l.pTail = NULL;
}
NODE* CrNode(SV x)
{
	NODE* p = new NODE;
	if (p == NULL) return NULL;
	else
	{
		p->pNext = NULL;
		p->Data = x;
	}
}
void AddHead(DSSV& l, NODE* p)
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
int Search(DSSV l, char y[20])
{
	NODE* p;
	p = l.pHead;
	while (p != NULL && strcmp(p->Data.MSSV,y)!=0)
	{
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	return 1;
}
int DeleteHead(DSSV& l, char y[20])
{
	Node* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int DeleteAfterQ(DSSV& l, NODE* q, char y[20])
{
	NODE* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
			{
				l.pTail = q;
			}
			q->pNext = p->pNext;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
int DeleteX(DSSV& l, char y[20])
{
	NODE* p, * q = NULL;
	p = l.pHead;
	while (p != NULL && strcmp(p->Data.MSSV, y) != 0)
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL) return 0;
	if (q != NULL)
		DeleteAfterQ(l, q, y);
	else
		DeleteHead(l, y);
	return 1;
}
void Xeploai(DSSV l)
{
	int i = 1;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << endl <<"\nThong tin sinh vien thu " << i << ':';
		i++;
		cout << "\nHo va ten: " << p->Data.Name;
		cout << "\nMSSV: " << p->Data.MSSV;
		cout << "\nDiem trung binh: " << p->Data.dtb;
		cout << "\nXep loai: ";
		if (p->Data.dtb <= 3.6)
			cout << "Loai yeu";
		else if (p->Data.dtb < 6.5 && 3.6 < p->Data.dtb)
			cout << "Loai trung binh";
		else if (p->Data.dtb < 7 && 6.5 <= p->Data.dtb)
			cout << "Loai trung binh kha";
		else if (p->Data.dtb < 8 && 7 <= p->Data.dtb)
			cout << "Loai kha";
		else if (p->Data.dtb < 9.0 && 8.0 <= p->Data.dtb)
			cout << "Loai gioi";
		else
			cout << "Loai xuat sac";
	}
}
void InsertAfterP(DSSV& l, NODE* m)
{
	NODE* p;
	p = l.pHead;
	if (p != NULL)
	{
		m->pNext = p->pNext;
		p->pNext = m;
		if (l.pTail == p)
			l.pTail = m;
	}
	else
		AddHead(l, m);
}
void SortDS(DSSV& l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->Data.dtb > q->Data.dtb)
			{
				float tam = p->Data.dtb;
				p->Data.dtb = q->Data.dtb;
				q->Data.dtb = tam;
			}
		}
	}
}
void Output(DSSV l)
{
	int i = 1;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << "\nThong tin sinh vien thu " << i << ':';
		i++;
		cout << "\nHo va ten: " << p->Data.Name;
		cout << "\nMSSV: " << p->Data.MSSV;
		cout << "\nDiem trung binh: " << p->Data.dtb;
	}
}

int main()
{
	DSSV l;
	CrList(l);
	SV x;
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ':';
		cout << "\nNhap ho va ten: ";
		gets_s(x.Name);
		cout << "\nNhap MSSV: ";
		gets_s(x.MSSV);
		cout << "\nNhap diem trung binh: ";
		cin >> x.dtb;
		cin.ignore();
		Node* p = CrNode(x);
		AddHead(l,p);
	}
	Output(l);
	cout << "\nNhap MSSV can tim: ";
	char y[20];
	cin >> y;
	cin.ignore();
	if (Search(l, y) == 1)
		cout << "\nCo sinh vien trong lop";
	else
		cout << "\nKhong co sinh vien trong lop";
	cout << "\nNhap MSSV muon xoa khoi danh sach: ";
	cin >> y;
	cin.ignore();
	DeleteX(l, y);
	cout << "\nDanh sach moi:";
	Output(l);
	cout << "\nDanh sach co diem trung binh >=5:";
	Node* q;
	int i = 1;
	for (q = l.pHead; q != NULL; q = q->pNext)
	{
		if (q->Data.dtb >= 5)
		{
			cout << "\nThong tin sinh vien thu " << i << ':';
			i++;
			cout << "\nHo va ten: " << q->Data.Name;
			cout << "\nMSSV: " << q->Data.MSSV;
			cout << "\nDiem trung binh: " << q->Data.dtb;
		}
	}
	Xeploai(l);
	cout << "\nNhap ho va ten sinh vien can chen: ";
	gets_s(x.Name);
	cout << "\nNhap MSSV can chen: ";
	gets_s(x.MSSV);
	cout << "\nNhap diem trung binh: ";
	cin >> x.dtb;
	NODE* m = CrNode(x);
	InsertAfterP(l, m);
	SortDS(l);
	cout << "\nDanh sach diem trung binh tang dan:";
	Output(l);
	return 0;
}