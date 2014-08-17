/*====================================
  Copyright by July2010年10月18日
  Modified by yuucyf.2011.04.28
  ======================================*/
#include <iostream>

using namespace std;

#define MAX_LEN 7

class C_NumberTB
{
private:
  int m_aryTop[MAX_LEN];
  int m_aryBottom[MAX_LEN];
  bool m_success;

public:
  C_NumberTB();

public:
  int* GetBottom();
  void SetNextBottom();
  int GetFrequecy(int nValue);
};

C_NumberTB::C_NumberTB()
{
  m_success = false;

  //format top
  for(int i = 0; i < MAX_LEN; i++)
    {
      m_aryTop[i] = i;
      m_aryBottom[i] = i;
    }
}

int* C_NumberTB::GetBottom()
{
  int i = 0;
  while(!m_success)
    {
      i++;
      SetNextBottom();
    }

  return m_aryBottom;
}

//set next bottom
void C_NumberTB::SetNextBottom()
{
  bool bRet = true;

  for(int i = 0; i < MAX_LEN; i++)
    {
      int nFreq = GetFrequecy(i);
      if(m_aryBottom[i] != nFreq)
	{
	  m_aryBottom[i] = nFreq;
	  bRet = false;
	}
    }

  m_success = bRet;
}


//get frequency in bottom
int C_NumberTB::GetFrequecy(int nValue) //此处的nValue 即指上排的数i
{
  int nCnt = 0;
  for(int  i = 0; i < MAX_LEN; i++)
    {
      if(m_aryBottom[i] == nValue)
	nCnt++;
    }

  return nCnt; //nCnt 即对应nFreq
}



int main()
{
  C_NumberTB objTB;
  int* pResult = objTB.GetBottom();

  for(int  i= 0 ;i < MAX_LEN; i++)
    {
      cout << *pResult++ << " ";
    }
  cout << endl;

  return 0;
}
