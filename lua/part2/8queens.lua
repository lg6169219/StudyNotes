local N = 8 -- 棋盘大小

-- 判断从第1行开始直到当前给定的行，列是否有冲突的皇后，行（这里可以忽略），列，对角线
-- 比如一个解{3, 7, 2, 1, 8, 6, 5, 4}, 在判断第4行，第一列是否合法是， isPlaceOK(a, 4, 1)
-- 我们就发现它是与第三行的2有"斜着"冲突
local function isPlaceOK(a, row, column)
	for i = 1, row - 1 do
		if(a[i] == column) or -- 列相同
			(a[i] - i == column - row) or --斜着冲突， 方向是\
			(a[i] + i == column + row) then --斜着冲突， 方向是/
			return false
		end
	end
	return true
end

-- 打印一个解
-- 我们这里的解是放在一个table中，类似{3, 7, 2, 1, 8, 6, 5, 4}
local function printSolution(a)
	for i = 1, N do
		for j = 1, N do
			io.write(a[i] == j and "X" or "-", " ")
		end
		io.write("\n")
	end
	io.write("\n")
end

-- 回溯算法，用递归进行所有可能的尝试
-- 总的可能解是8个8相乘，所以我们要搞一个递归函数来判断8*8*8*8*8*8*8*8个可能解中是否有符合要求的解。 递归主要要处理要退出条件和参数的问题
-- 每一行，我们要判断8个列中是否能找到合法解，如果能找到合法解，继续往下一行搜索，直到到达函数的退出条件就算是找到一个解了
local solution_count = 0
local function addQueen(a, row)
	if row > N then
		solution_count = solution_count + 1
		print("=======solution_count: ", solution_count)
		printSolution(a)
	else
		for column = 1, N do
			if isPlaceOK(a, row, column) then
				a[row] = column
				addQueen(a, row + 1)
			end
		end
	end
end

addQueen({}, 1)--从第一行开始求解