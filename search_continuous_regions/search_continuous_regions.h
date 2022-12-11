#pragma once

#include <iostream>
#include <vector>

/// 搜索矩阵中连续为1最多的区域的元素个数
/// 连续的定义：上下左右相邻
class SearchContinuousRegions
{
public:
	SearchContinuousRegions(std::vector<std::vector<int>> arr);
	~SearchContinuousRegions();
	void search(int* num, std::vector<std::vector<std::vector<int>>> &ret);

private:
	int rows;
	int cols;
	std::vector<std::vector<int>> arr;
	std::vector<std::vector<int>> elem;

	void reset(int row, int col);
};
