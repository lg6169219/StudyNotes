function norm(x, y)
	return math.sqrt(x^2 + y^2)
end

function twice(x)
	return 2.0 * x
end

print("=====lib1", twice(2))

-- lua -i lib1.lua
-- 上述的命令行会在执行完文件prog中的程序段后进入交互模式

-- 另一种运行程序段的方式是调用函数dofile，该函数会立即执行一个文件

-- > dofile("lib1.lua")
-- > n = norm(3.4, 1.0)
-- > print(twice(n))
-- 7.0880180586677


-- -e参数允许我们直接在命令行中输入代码
-- 在POSIX系统下需要使用双引号，以防止Shell错误地解析括号
-- 以下命令打印第0个参数 文件名
-- 编译器在运行代码前会创建一个名为arg的表，其中存储了所有的命令行参数。索引0中保存的内容为脚本名，索引1中保存的内容为第一个参数（本例中的"a"），依此类推；而在脚本之前的所有选项则位于负数索引上
-- lua -e "print(arg[0])" fact.lua a