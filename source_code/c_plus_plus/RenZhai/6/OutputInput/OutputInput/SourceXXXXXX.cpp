#include <iostream>
#include <fstream>

using namespace std;

void FileRead(const char *InFileName,char *InBuffer)
{
	ifstream ReadFile;
	ReadFile.open(InFileName);
	ReadFile.seekg(0, ios::end);
	int FileLen = ReadFile.tellg();
	ReadFile.seekg(0, ios::beg);
	ReadFile.read(InBuffer, FileLen);
	cout << InBuffer << endl;
	ReadFile.close();
}

bool FileCopy(const char* InCopyFileName, const char* InTargerFileName)
{
	char buffer[4096] = { 0 };
	ifstream iReadFile;
	ofstream wWriteFile;
	iReadFile.open(InCopyFileName);
	wWriteFile.open(InTargerFileName);//û�оʹ���һ��

//	while (iReadFile >> buffer)
	//while (!iReadFile.eof())
	//{
	//	iReadFile >> buffer;
	//	cout << buffer;
	//	wWriteFile << buffer;
	//}
	iReadFile.seekg(0, ios::end);
	int FileLen = iReadFile.tellg();
	iReadFile.seekg(0, ios::beg);
	iReadFile.read(buffer, FileLen);
	wWriteFile << buffer;

	iReadFile.close();
	wWriteFile.close();

	return true;
}

int main()
{
	//cout
//	cout << "Hello" << endl;//����
	//cin; //���
	//cout
	//cerr;//
	//clog;//
	char buffer[1024] = { 0 };
	//cin.getline(buffer, 1024);//����������ո��
//	cin >> buffer;//�������һ�������� 
//	cout << buffer << endl;
	//ʲô����������
	//IO
//	cerr << "asdasdasd asdasd Error" << endl;//�ǻ���

	//clog << "Hello Log" << endl;
	//cout
	//cerr
	//clog

	cout << "cout Text" << endl;
	cerr << "Error" << endl;
	clog << "LOG LOG" << endl;

	//iostream
	//fstream

	//ofstream
	//ifstream
	//fstream

	//ofstream file;
	//file.open("xxx.txt",ios::app);//����һ��

	//cout << "��ʼд����Ϣ" << endl;
	//cin.getline(buffer, 1024);
	//file << buffer << endl;

	//file.close();

	//ifstream ReadFile;
	//ReadFile.open("xxx.txt");

	////��ȡһ�� �� endl��β
	//cout << "��ʼ��ȡ��Ϣ" << endl;
	//ReadFile >> buffer;
	//cout << buffer << endl;

	////��ȡ�����Ĳ���
	//char buffer2[1024] = { 0 };
	//ReadFile.seekg(0, ios::end);
	//int FileLen = ReadFile.tellg();
	//ReadFile.seekg(0, ios::beg);
	//ReadFile.read(buffer2, FileLen);
	//cout << buffer2 << endl;
	//ReadFile.close();

	//ios::app +
	//ios::ate
	//ios::in  r
	//ios::out w
	//ios::trunc
	//ios::out | ios::app w+
	//ios::in  | ios::out r+
	//fstream file1;
	//file1.open("xxx.txt",ios::out | ios::app); //w+
	////file1 << "weraw"<<endl;
	////file1 << "ca"<<endl;

	//file1 >> buffer;
	//cout << buffer << endl;
	//file1.close();

	//char buffer4[1024] = { 0 };
	//FileRead("xxx.txt", buffer4);

	FileCopy("Source.cpp","SourceXXXXXX.cpp");

	system("pause");
	return 0;
}