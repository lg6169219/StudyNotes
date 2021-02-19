// 返回局部变量的地址
int* func() {
	int a; 
	return &a; //err qt中会报错 vs不会 linux不允许返回局部变量的地址
}

// 返回全局变量的地址
// 放在{}外面定义的变量，就是全局变量，全局变量在任何地方都可以使用
// 全局变量只有在整个程序结束后，才释放

int* GlobalFunc(int *b) {
	return b;
}