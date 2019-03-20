// test4_shared_unique_weak_ptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <memory>

int main() {
	//shared_ptr
	{
		int a = 10;
		std::shared_ptr<int> ptra = std::make_shared<int>(a);
		std::shared_ptr<int> ptra2(ptra); //copy
		std::cout << ptra.use_count() << std::endl;

		int b = 20;
		int *pb = &a;
		//std::shared_ptr<int> ptrb = pb;  //error
		std::shared_ptr<int> ptrb = std::make_shared<int>(b);
		ptra2 = ptrb; //assign
		pb = ptrb.get(); //获取原始指针

		std::cout << ptra.use_count() << std::endl;
		std::cout << ptrb.use_count() << std::endl;
	}
	
	//unique_ptr
	{
		std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
		//std::unique_ptr<int> uptr2 = uptr;  //不能賦值
		//std::unique_ptr<int> uptr2(uptr);  //不能拷貝
		std::unique_ptr<int> uptr2 = std::move(uptr); //轉換所有權
		uptr2.release(); //释放所有权
	}
	//超過uptr的作用域，內存釋放

	//weak_ptr
	std::cout << std::endl;
	{
		std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
		std::cout << sh_ptr.use_count() << std::endl;

		std::weak_ptr<int> wp(sh_ptr);
		std::cout << wp.use_count() << std::endl;

		if (!wp.expired()) {
			std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
			*sh_ptr = 100;
			std::cout << wp.use_count() << std::endl;
		}
	}
	//delete memory
}

