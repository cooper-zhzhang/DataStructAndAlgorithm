#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

// 冒泡排序
void bubble_sort(vector<int> &vec)
{
	int i, j;
	int len = vec.size();
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

void insert_sort(vector<int> &vec)
{
	int i, j, key;
	for (i = 1; i != vec.size(); ++i)
	{
		key = vec[i];
		j = i - 1;
		while ((j >= 0) && (vec[j] > key))
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

// 鸡尾酒排序
void cocktail_sort(vector<int> &vec)
{
	int j, left = 0, right = vec.size() - 1;
	while (left < right)
	{
		for (j = left; j < right; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}

		right--;
		for (j = right; j > left; j--)
		{
			if (vec[j - 1] > vec[j])
			{
				int temp = vec[j - 1];
				vec[j - 1] = vec[j];
				vec[j] = temp;
			}
		}
		left++;
	}
}

void bucket_sort(vector<int> &vec)
{
	vector<int> temp(vec.begin(), vec.end());
	for (int i = 0; i < temp.size(); ++i)
	{
		vec[temp[i]] = temp[i];
	}
}

void counting_sort(vector<int> &vec)
{ // 必须知道数据的范围
	vector<int> temp(20);
	for (int i = 0; i < vec.size(); ++i)
	{

		temp[vec[i]]++;
	}
}


void merger_sort(vector<int> &vec)
{
	int len = vec.size();

	vector<int> temp(len);
	//int *temp = new int[len];

	for (int seg = 1; seg < len; seg *= 2)
	{// 每个块的大小

		// 根据这个块大小分出数据

		// 下面是一个循环
		for (int start = 0; start < len; start += seg *2)
		{

			int start1 = start;
			int end1 = min(start + seg, len);

			int start2 = start + seg;
			int end2 = min(start + seg * 2, len);

			// 开始合并
			int k = start1;
			while (start1 < end1 && start2 < end2)
			{
				if (vec[start1] < vec[start2])
				{
					temp[k++] = vec[start1];
					start1++;
				}
				else
				{
					temp[k++] = vec[start2];
					start2++;
				}
				// 这个实现比较简洁
				//temp[k++] = vec[start1] < vec[start2] ? vec[start1++] : vec[start2++];
			}

			while (start1 < end1)
				temp[k++] = vec[start1++];
			while (start2 < end2)
				temp[k++] = vec[start2++];
		}
		// 一轮合并完后 把临时数据发到vec中
		vec = temp;
	}
}

typedef void (*FUNC)(vector<int> &);

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(i);
	}

	//srand((unsigned int)time(0));

	std::vector<FUNC> sortVec;

	sortVec.push_back(bubble_sort);
	sortVec.push_back(insert_sort);
	sortVec.push_back(cocktail_sort);
	sortVec.push_back(bucket_sort);

	std::map<string, FUNC> sortMap;
	sortMap.insert(std::make_pair("bubble sort", bubble_sort));
	sortMap.insert(std::make_pair("insert sort", insert_sort));
	sortMap.insert(std::make_pair("cocktail sort", cocktail_sort));
	sortMap.insert(std::make_pair("bucket sort", bucket_sort));
	sortMap.insert(std::make_pair("merger sort", merger_sort));

	for (auto &it : sortMap)
	{
		random_shuffle(vec.begin(), vec.end());
		std::cout << it.first << std::endl;
		it.second(vec);
		for (auto it : vec)
		{
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
