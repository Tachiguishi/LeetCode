#include <solution.h>

void TwoSum::add(int number){
	m_nums.push_back(number);
	for(int i = m_nums.size() - 1; i > 0; --i){
		if(m_nums[i] >= m_nums[i - 1]){
			break;
		}
		swap(m_nums[i], m_nums[i - 1]);
	}
}

bool TwoSum::find(int value){
	int left = 0;
	int right = m_nums.size() - 1;
	while(left < right){
		int sum = m_nums[left] + m_nums[right];
		if(sum == value){
			return true;
		}
		else if(sum < value){
			++left;
		}
		else{
			--right;
		}
	}
	return false;
}
