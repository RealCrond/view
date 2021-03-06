﻿// view.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

#pragma comment(lib,"opencv_world412.lib")

enum EmEvent_Api
{
	emFirst,
	emSecond,
	emThird,
};

void printName(const char* name)
{
	cout << "[打印变量名]  " << name << endl;
}

#define PRINTNAME(emEvent)  printName(#emEvent)

int main()
{
	Mat img = imread("8b1d2b63-2e02-4ebd-9344-650db12cdf52.jpg",IMREAD_GRAYSCALE);
	if ( !img.data )
	{
		cout << "Failed to open image!" << endl;
		return 1;
	}
	//imshow("Test", img);
	string str = "\"abc";
	cout << str << endl;

	EmEvent_Api emEventType = emFirst;
	//printName(#emEnvetType);
	PRINTNAME(emEnvetType);

	emEventType = emSecond;
	PRINTNAME(emSecond);

	emEventType = emThird;
	PRINTNAME(emThird);


	if( 'q' == waitKey(0) )
	{ 
		std::cout << "Hello World!\n";
		return 0;
	}
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
