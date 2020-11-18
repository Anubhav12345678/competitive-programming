//reverse a stack in O(1) space
void insert(stack<int> &s,int ele)
{
	if(s.empty())
		s.push(ele);
	else{
		int tmp = s.top();
		s.pop();
		insert(s,ele);
		s.push(tmp);
	}
}

void reverse(stack<int> &s)
{
	if(s.size()<=1) return;
	int tmp = s.top();
	s.pop();
	reverse(s);
	insert(tmp);
}