/*
 * ��������btree3.c���˳�����ʾ���������������Ĵ�������ǰ����̵ķ�����
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20200202
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////
// ���������������ݽṹ��
typedef struct TBTNode
{
  char   data;               // ��Ž�������Ԫ�ء�
  struct TBTNode *lchild;    // ָ�����ӽ���ַ��ָ�롣
  struct TBTNode *rchild;    // ָ�����ӽ���ַ��ָ�롣
  unsigned char ltag,rtag;   // ����ָ������ͣ�0-������ָ�룬1-����ָ�롣
}TBTNode,*TBTTree;
///////////////////////////////////////////////

// ���ʽ��Ԫ�ء�
void visit(TBTNode *pp);

// ���õݹ�ķ����Զ����������������
void PreOrder(TBTTree TT);

// ���õݹ�ķ����Զ����������������
void InOrder(TBTTree TT);

// ���õݹ�ķ����Զ������ĺ��������
void PostOrder(TBTTree TT);

// ���������������������������
void CrtInThread(TBTTree TT);

// ��������������������ĵݹ麯��������pp�ǵ�ǰ�ڵ㣬pre��ǰ����㡣
void InThread(TBTTree pp,TBTTree *pre);  // C���Ե�pre����Ҫ��ָ���ָ�롣
// void InThread(TBTTree pp,TBTTree &pre); // C++���Ե�pre����Ϊ���ã��������������Ҫ��C++�ı��������롣

//////////////////////////////////////////////////
// ��ȡ������������������ĵ�һ����㡣
TBTNode *FirstNode(TBTTree TT);

// ��ȡ������������������ĺ�̽�㡣
TBTNode *NextNode(TBTNode *pp);

// ���������������ı���������
void InOrder1(TBTTree TT);
//////////////////////////////////////////////////

///////////////////////////////////////////////////
// ��ȡ����������������������һ����㡣
TBTNode *LastNode(TBTTree TT);

// ��ȡ�������������������ǰ����㡣
TBTNode *PriorNode(TBTNode *pp);

// ���ҵ������������������ı���������
void InOrder2(TBTTree TT);
//////////////////////////////////////////////////

int main()
{
  TBTTree TT=0; // ������ָ�������

  /*
  // �ֹ�����һ�����½ṹ�Ķ�������
             1
          /     \
         2       3
        / \     /
       4   5   6
      / \ /   /
     7  8 9  0
  */

  // ������ڵ㡣
  TT=(TBTNode *)malloc(sizeof(TBTNode));
  TT->data='1';
  TT->lchild=TT->rchild=0;
  TT->ltag=TT->rtag=0;

  // �ڶ����һ���ڵ㡣
  TT->lchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->data='2'; 
  TT->lchild->lchild=TT->lchild->rchild=0;
  TT->lchild->ltag=TT->lchild->rtag=0;

  // �ڶ���ڶ����ڵ㡣
  TT->rchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->rchild->data='3'; 
  TT->rchild->lchild=TT->rchild->rchild=0;
  TT->rchild->ltag=TT->rchild->rtag=0;

  // �������һ���ڵ㡣
  TT->lchild->lchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->lchild->data='4'; 
  TT->lchild->lchild->lchild=TT->lchild->lchild->rchild=0;
  TT->lchild->lchild->ltag=TT->lchild->lchild->rtag=0;

  // ������ڶ����ڵ㡣
  TT->lchild->rchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->rchild->data='5'; 
  TT->lchild->rchild->lchild=TT->lchild->rchild->rchild=0;
  TT->lchild->rchild->ltag=TT->lchild->rchild->rtag=0;

  // ������������ڵ㡣
  TT->rchild->lchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->rchild->lchild->data='6'; 
  TT->rchild->lchild->lchild=TT->rchild->lchild->rchild=0;
  TT->rchild->lchild->ltag=TT->rchild->lchild->rtag=0;

  // ���Ĳ��һ���ڵ㡣
  TT->lchild->lchild->lchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->lchild->lchild->data='7'; 
  TT->lchild->lchild->lchild->lchild=TT->lchild->lchild->lchild->rchild=0;
  TT->lchild->lchild->lchild->ltag=TT->lchild->lchild->lchild->rtag=0;

  // ���Ĳ�ڶ����ڵ㡣
  TT->lchild->lchild->rchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->lchild->rchild->data='8'; 
  TT->lchild->lchild->rchild->lchild=TT->lchild->lchild->rchild->rchild=0;
  TT->lchild->lchild->rchild->ltag=TT->lchild->lchild->rchild->rtag=0;

  // ���Ĳ�������ڵ㡣
  TT->lchild->rchild->lchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->lchild->rchild->lchild->data='9'; 
  TT->lchild->rchild->lchild->lchild=TT->lchild->rchild->lchild->rchild=0;
  TT->lchild->rchild->lchild->ltag=TT->lchild->rchild->lchild->rtag=0;

  // ���Ĳ���ĸ��ڵ㡣
  TT->rchild->lchild->rchild=(TBTNode *)malloc(sizeof(TBTNode));
  TT->rchild->lchild->rchild->data='0'; 
  TT->rchild->lchild->rchild->lchild=TT->rchild->lchild->rchild->rchild=0;
  TT->rchild->lchild->rchild->ltag=TT->rchild->lchild->rchild->rtag=0;

  //////////////////////////////////////////////////////////
  // �����������������
  printf("������������"); PreOrder(TT); printf("\n");

  // �����������������
  printf("������������"); InOrder(TT); printf("\n");

  // �������ĺ��������
  printf("������������"); PostOrder(TT); printf("\n");
  // ���ϱ����������Ĵ���Ҫ����������֮ǰ��
  //////////////////////////////////////////////////////////

  // ���������������������������
  CrtInThread(TT);

  printf("�������������������ұ��������"); InOrder1(TT); printf("\n");
  printf("�����������������ҵ�����������"); InOrder2(TT); printf("\n");

  return 0;
}

// ���ʽ��Ԫ�ء�
void visit(TBTNode *pp)
{
  printf("%c ",pp->data);  // ���ʽ��Ԫ�ؾ��ǰ�ֵ���������˼һ�¾����ˡ�
}

// �����������������
void PreOrder(TBTTree TT)
{
  if (TT == NULL) return;

  visit(TT);               // ��������TT�ĸ���㡣

  PreOrder(TT->lchild);    // ������������

  PreOrder(TT->rchild);    // ������������
}

// �����������������
void InOrder(TBTTree TT)
{
  if (TT == NULL) return;

  InOrder(TT->lchild);     // ������������

  visit(TT);               // ��������TT�ĸ���㡣

  InOrder(TT->rchild);     // ������������
}

// �������ĺ��������
void PostOrder(TBTTree TT)
{
  if (TT == NULL) return;

  PostOrder(TT->lchild);     // ������������

  PostOrder(TT->rchild);     // ������������

  visit(TT);                 // ��������TT�ĸ���㡣
}

// ��������������������ĵݹ麯��������pp�ǵ�ǰ�ڵ㣬pre��ǰ����㡣
void InThread(TBTTree pp,TBTTree *pre)
{
  if (pp==NULL) return;

  // �ݹ���������������
  InThread(pp->lchild,pre);  

  // ������ǰ����ǰ��������
  if (pp->lchild==NULL)
  {
    pp->lchild=(*pre); pp->ltag=1;
  }

  printf("%c ",pp->data);

  // ����ǰ�����ĺ��������
  if ( ((*pre)!=NULL) && ((*pre)->rchild==NULL) )
  {
    (*pre)->rchild=pp; (*pre)->rtag=1;
  }

  (*pre)=pp;  // ��ǰ�����Ϊ��ǰ��㡣

  // �ݹ���������������
  InThread(pp->rchild,pre);
}

/*
// C++���Ե�pre����Ϊ���ã��������������Ҫ��C++�ı��������롣
void InThread(TBTTree pp,TBTTree &pre) 
{
  if (pp==NULL) return;

  // �ݹ���������������
  InThread(pp->lchild,pre);  

  // ������ǰ����ǰ��������
  if (pp->lchild==NULL)
  {
    pp->lchild=pre; pp->ltag=1;
  }

  printf("%c ",pp->data);

  // ����ǰ�����ĺ��������
  if ( (pre!=NULL) && (pre->rchild==NULL) )
  {
    pre->rchild=pp; pre->rtag=1;
  }

  pre=pp;  // ��ǰ�����Ϊ��ǰ��㡣

  // �ݹ���������������
  InThread(pp->rchild,pre);
}
*/

// ���������������������������
void CrtInThread(TBTTree TT)
{
  if (TT==NULL) return;

  TBTNode *pre=NULL;

  // ��������������������ĵݹ麯��������pp�ǵ�ǰ�ڵ㣬pre��ǰ����㡣
  InThread(TT,&pre);  // C����ָ���ָ�롣
  // InThread(TT,pre);  // C++���ã��������������Ҫ��C++�ı��������롣

  // �������һ��������ָ�롣
  pre->rchild=NULL;
  pre->rtag=1;

  printf(" ��������ɡ�\n");
}

////////////////////////////////////////////////////////////////////////////
// ��ȡ������������������ĵ�һ����㡣
TBTNode *FirstNode(TBTTree TT)
{
  // �����ߵ���ͷ��
  while (TT->ltag==0) TT=TT->lchild;

  return TT;
}

// ��ȡ������������������ĺ�̽�㡣
TBTNode *NextNode(TBTNode *pp)
{
  // �����ǰ������ָ���ŵ���������ֱ��ָ���ء�
  // �����ǰ������ָ���ŵ��ǽ�㣬������������������ĵ�һ����㡣
  if (pp->rtag==0) return FirstNode(pp->rchild);
  else return pp->rchild;
}

// ���������������������ı���������
void InOrder1(TBTTree TT)
{
  // �õ���һ����㡣
  TBTNode *pp=FirstNode(TT);

  while (pp!=NULL)
  {
    visit(pp);        // ���ʽ�㡣
    pp=NextNode(pp);  // ָ���ƶ�����̽�㡣
  }
}

////////////////////////////////////////////////////////////////////////////
// ��ȡ����������������������һ����㡣
TBTNode *LastNode(TBTTree TT)
{
  // �����ߵ���ͷ��
  while (TT->rtag==0) TT=TT->rchild;

  return TT;
}

// ��ȡ�������������������ǰ����㡣
TBTNode *PriorNode(TBTNode *pp)
{
  // �����ǰ������ָ���ŵ���������ֱ��ָ���ء�
  // �����ǰ������ָ���ŵ��ǽ�㣬�������������������������㡣
  if (pp->ltag==0) return LastNode(pp->lchild);
  else return pp->lchild;
}

// ���ҵ������������������ı���������
void InOrder2(TBTTree TT)
{
  // �õ����һ����㡣
  TBTNode *pp=LastNode(TT);

  while (pp!=NULL)
  {
    visit(pp);        // ���ʽ�㡣
    pp=PriorNode(pp);  // ָ���ƶ���ǰ����㡣
  }
}
////////////////////////////////////////////////////////////////////////////
