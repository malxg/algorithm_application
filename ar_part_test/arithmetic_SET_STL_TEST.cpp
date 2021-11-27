#include <map>
#include <iostream>
#include <string>

using namespace std;

//ѧ����Ϣ
typedef struct tagStudentInfo
{
 int nID;
 string strName;
 bool operator <(const tagStudentInfo &A) const
 {
  if (nID < A.nID) return true;  //�ȱȽ�nID
  if (nID == A.nID) return strName.compare(A.strName) > 0;   //nID��ͬʱ���ٱȽ�strName
  return false;
 }

}StudentInfo,*pstudentInfo;

int main()
{
 //��ѧ����Ϣӳ�����
 map<StudentInfo,int> mapStudent;

 StudentInfo studentInfo;

 studentInfo.nID = 1;
 studentInfo.strName = "student_one";
 mapStudent.insert(map<StudentInfo,int>::value_type(studentInfo,90));

 studentInfo.nID = 2;
 studentInfo.strName = "student_two";
 mapStudent.insert(map<StudentInfo,int>::value_type(studentInfo,80));

 studentInfo.nID = 2;
 studentInfo.strName = "student_three";
 mapStudent.insert(map<StudentInfo,int>::value_type(studentInfo,80));

 map<StudentInfo,int>::iterator iter;
 for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)
  cout << iter->first.nID << iter->first.strName << endl << iter->second << endl;

 return 0;
}
