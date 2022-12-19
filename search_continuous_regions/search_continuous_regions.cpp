#include "search_continuous_regions.h"

SearchContinuousRegions::SearchContinuousRegions(std::vector<std::vector<int>> arr)
{
    if (arr.empty())
    {
        this->arr = {
                {1, 0, 0, 1, 0},
                {1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 1, 1, 0},
        };
    }
    else
    {
        this->arr = arr;
    }
    this->rows = this->arr.size();
    this->cols = this->arr[0].size();
}

SearchContinuousRegions::~SearchContinuousRegions()
{
}

void SearchContinuousRegions::reset(int row, int col)
{
    // 置为0
    this->arr[row][col] = 0;
    // 保存当前元素的行列索引
    std::vector<int> index = { row, col };
    this->elem.push_back(index);
    // 上
    if (row-1 >= 0 && this->arr[row-1][col] == 1)
    {
        this->reset(row-1, col);
    }
    // 下
    if (row+1 <= this->rows-1 && this->arr[row+1][col] == 1)
    {
        this->reset(row+1, col);
    }
    // 左
    if (col-1 >= 0 && this->arr[row][col-1] == 1)
    {
        this->reset(row, col-1);
    }
    // 右
    if (col+1 <= this->cols-1 && this->arr[row][col+1] == 1)
    {
        this->reset(row, col+1);
    }
}

void SearchContinuousRegions::search(int* num, std::vector<std::vector<std::vector<int>>> &ret)
{
    // 连续为1的区域的数量
    *num = 0;
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->arr[i][j] == 1)
            {
                this->reset(i, j);
                // 每个连续为1的区域内的元素的行列索引
                ret.push_back(this->elem);
                // 清空elem以供下个区域使用
                std::vector<std::vector<int>>().swap(this->elem);
                *num += 1;
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> arr;
    SearchContinuousRegions scr(arr);
    int num = 0;
    std::vector<std::vector<std::vector<int>>> ret;
    scr.search(&num, ret);
    std::cout << num << std::endl;
    std::cout << std::endl;
    for (auto iter1 = ret.begin(); iter1 != ret.end(); iter1++) {
        for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            for (auto iter3 = (*iter2).begin(); iter3 != (*iter2).end(); iter3++) {
                std::cout << *iter3 << " ";
            }
            std::cout << ", ";
        }
        std::cout << "\n";
    }
}
