-- 阶乘
function fact(n)
	if (n < 0) then return nil end
	if (n <= 1) then return 1 end
	return n * fact(n - 1)
end

print("5! = ", fact(5)) 


-- Lua的type()函数返回的是一个字符串类型
-- type(nil)返回的是string类型的"nil"，所以1不对，而3中的type(nil) == "nil"才对的。
-- type(true)返回的是string类型的"boolean"，boolean不是保留字，可以作为变量。
-- false
print("type(nil)==nil ", type(nil)==nil)
-- true
print("type(nil)=='nil' ", type(nil)=="nil")