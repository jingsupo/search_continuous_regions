#pragma once

#include <iostream>
#include <vector>

/// ��������������Ϊ1���������Ԫ�ظ���
/// �����Ķ��壺������������
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
